/* ----------------------------------------------------------------------
 * FILE: lexer.c
 * PACKAGE: as31 - 8031/8051 Assembler.
 *
 * DESCRIPTION:
 *	This file contains the lexical tokenizer for the assembler.
 *	Since yacc is being used the lexer is called yylex().
 *
 *	In order to produce a listing, some record of the users
 *	source line must be kept. This is done by adding
 *	get_ch(), and unget_ch() routine which returns/ungets a character
 *	but also places information into a secret array.
 *
 *	When a newline is encountered the text line is returned as
 *	an attribute on the '\n' character.
 *
 * REVISION HISTORY:
 *	Jan. 19, 1990 - Created. (Ken Stauffer)
 *
 * AUTHOR:
 *	All code in this file written by Ken Stauffer (University of Calgary).
 *	January, 1990.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include "as31.h"

extern union ystack yylval;
extern int pass;

struct symbol *looksym();
struct opcode *lookop();
char *malloc();
int lineno;

static char line[100],*lineptr=line;

/* ----------------------------------------------------------------------
 * get_ch:
 *	Get a character from stdin, place char in line[]
 */

get_ch()
{
	register int c;

	c = getchar();
	if( c != EOF && lineptr - line < sizeof(line) )
		*lineptr++ = c;
	return(c);
}

/* ----------------------------------------------------------------------
 * unget_ch:
 *	Unget a character and move lineptr back by one.
 */

unget_ch(c)
int c;
{
	ungetc(c,stdin);
	if( lineptr > line )
		lineptr--;
}

/* ----------------------------------------------------------------------
 * yylex:
 *	The tokens themselves are returned via return(token)
 *
 *	Some tokens have attributes. These attributes are returned
 *	by setting a global variable yylval:
 *
 *		yylval.value
 *			numbers (any base)
 *			strings (in pass 1).
 *			bit positions .0, .1, .2, ...
 *
 *		yylval.str
 *			strings (in pass 2).
 *			'\n' (both passes).
 *
 *		yylval.sym
 *			User defined symbols.
 *
 *		yylval.op
 *			Reserved keyword (opcode/directive/misc.)
 *
 *		No other fields in yylval are used by yylex().
 * 
 *		Characters that do not have an attribute do
 *		not set anything in the yylval variable.
 *
 */

yylex()
{
	static nl_flag=0;	/* sync. error messages and the cur. line */
	register int c;
	char buf[120];		/* temporary buffer */
	char *p;		/* general pointer */
	struct symbol *sym;
	struct opcode *op;

	int octal=0,hex=0,decimal=0,binary=0;
	register long value = 0;

	if( nl_flag ) {
		nl_flag = 0;
		lineno++;
	}

for(;;) {
	c = get_ch();
	switch(c) {
	case EOF: return(EOF);
	case ' ':
	case '\r':
	case '\t':
		break;

	case '\n':
		nl_flag = 1;
		yylval.str = line;
		*lineptr = '\0';
		lineptr = line;
		return('\n');

	case ';':
		while((c=get_ch()) != EOF && c!='\n');
		nl_flag= 1;
		yylval.str = line;
		*lineptr = '\0';
		lineptr = line;
		return(c);

	case '"':
		p = buf;
		while((c=get_ch()) != EOF && c!='"' && c!='\n') {
			if( c == '\\' ) {
				switch(c=get_ch()) {
				case 'n': c = '\n'; break;
				case 'r': c = '\r'; break;
				case 't': c = '\t'; break;
				case 'b': c = '\b'; break;
				case '"': c = '"'; break;
				case '\\': c = '\\'; break;
				default:
				  error("Invalid escape character: \\%c",c);
				  break;
				}
			}
			if( p-buf<sizeof(buf)-1 ) 
				*p++ = c;
			else {
			   error("String constant longer than %d bytes",
					sizeof(buf));
			}
		}
		*p = '\0';
		if( c == '\n' || c == EOF ) {
			error("String terminated improperly.");
			unget_ch(c);
		}

		if(pass1)
			yylval.value = strlen(buf);
		else {
			if( (p = malloc(strlen(buf)+1)) == NULL )
			   error("Cannot allocate %d bytes",strlen(buf)+1);
			strcpy(p,buf);
			yylval.str = p;
		}
		return(STRING);

	case '.':
		if( (c=get_ch())>='0' && c<='7' ) {
			yylval.value = c-'0';
			return(BITPOS);
		}
		unget_ch(c);
		return('.');

	case '\'':
		c = get_ch();
		if( c=='\\' ) {
			switch(c=get_ch()) {
			case 'n': c = '\n'; break;
			case 'r': c = '\r'; break;
			case 't': c = '\t'; break;
			case 'b': c = '\b'; break;
			case '0': c = 0; break;
			case 'o': c = 0; break;
			case 'O': c = 0; break;
			case '\\': c = '\\'; break;
			case '\'': c = '\''; break;
			default:
				error("Invalid escape character: \\%c",c);
			}
		}
		if( get_ch() != '\'' )
			error("Missing quote in character constant");
		yylval.value = c;
		return(VALUE);

	case '0':	/* parse a number			*/
	case '1':	/* could be followed by a:		*/
	case '2':	/*	'b','B' - Binary		*/
	case '3':	/*	'h','H' - Hex			*/
	case '4':	/*	'd','D' - Decimal		*/
	case '5':	/*	'o','O' - Octal			*/
	case '6':	/* *** Numbers must start with a digit	*/
	case '7':	/* Numbers could be also preceeded by:  */
	case '8':	/*	0x	- Hex,	0b     - binary */
	case '9':	/*	0	- Octal			*/

		p = buf;
		do {
			if( p-buf<sizeof(buf)-1 )
				*p++ = c;
			c = get_ch();
		} while( c=='H' || c=='h' || c=='O' || c=='o' ||
				c=='x' || c=='X' || isxdigit(c) );
		unget_ch(c);
		*p = '\0';


		/* Check any preceeding chars */
		if( buf[0]=='0' && (buf[1]=='x' || buf[1]=='X') ) {
				hex++;
				buf[1] = '0';
		} else if( buf[0]=='0' &&
			(buf[1]=='b' || buf[1]=='B') ) {
				binary++;
				buf[1] = '0';
			}
		else if( buf[0]=='0' ) octal++;

		/* check any trailing chars */
		c = *(p-1);
		if( !hex && (c=='b' || c=='B') )
			{ binary++; *(p-1) = '\0'; }
		else if( c=='H' || c=='h' )
			{ hex++; *(p-1) = '\0'; }
		else if( !hex && (c=='D' || c=='d') )
			{ decimal++; *(p-1) = '\0'; }
		else if( c=='O' || c=='o' )
			{ octal++; *(p-1) = '\0'; }
		else if( !hex && !octal && !binary) decimal++;

		if( binary ) {
			for(p=buf; *p; p++ ) {
				if( *p=='1' ) value = value * 2 + 1;
				else if( *p=='0' ) value = value * 2;
				else
				  error("Invalid binary digit: %c",*p);
			}
			yylval.value = value;
			return(VALUE);
		}

		if( hex ) {
			for(p=buf; *p; p++ ) {
				value <<= 4;
				if( isdigit(*p) )
					value += *p-'0';
				else if( *p>='a' && *p<='f' )
					value += *p-'a'+ 10;
				else if( *p>='A' && *p<='F' )
					value += *p-'A'+ 10;
				else
				  error("Invalid hex digit: %c",*p);
			}
			yylval.value = value;
			return(VALUE);
		}

		if( decimal ) {
			for(p=buf; *p; p++ ) {
				if( isdigit(*p) )
					value = value*10 + *p-'0';
				else
				   error("Invalid decimal digit: %c",*p);
			}
			yylval.value = value;
			return(VALUE);
		}

		if( octal ) {
			for(p=buf; *p; p++ ) {
				if( *p>='0' && *p<='7' )
					value = value<<3 + *p-'0';
				else
				   error("Invalid octal digit: %c",*p);
			}
			yylval.value = value;
			return(VALUE);
		}

	default:
		if( isalpha(c) || c=='_' ) {
			p = buf;
			do {
				if( p-buf<sizeof(buf)-1 )
					*p++ = c;
				c = get_ch();
			} while( isalnum(c) || c=='_' );
			*p = '\0';
			unget_ch(c);
			if( op = lookop(buf) ) {
				yylval.op = op;
				return(op->type);
			}
			sym = looksym(buf);
			yylval.sym = sym;
			return(SYMBOL);
		} else
			return(c);
	} /* switch */
} /* for */

} /* yylex */
