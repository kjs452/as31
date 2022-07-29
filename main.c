/* ----------------------------------------------------------------------
 * FILE: main.c
 * PACKAGE: as31 - 8031/8051 Assembler.
 *
 * DESCRIPTION:
 *	The file contains main(). It handles the arguments and makes
 *	sure that pass 1 is done before pass 2 etc...
 *
 * REVISION HISTORY:
 *	Jan. 19, 1990 - Created. (Ken Stauffer)
 *
 * AUTHOR:
 *	All code in this file written by Ken Stauffer (University of Calgary).
 *	January, 1990. */ static char
 *	id_id= "Written by: Ken Stauffer";/*
 *
 */

/* add -s option, 2 sept 95.  This option makes it use stdout */
/* for the object code.  The listing is supressed, and the */
/* original .asm is DELETED.  This option is intended for use */

#include <stdio.h>
#include <setjmp.h>

extern int lineno;
extern int pass,fatal;
extern unsigned long lc;

jmp_buf main_env;
char *asmfile;
int dashl=0;
FILE *listing;

/* ----------------------------------------------------------------------
 * checkext:
 *	Check the string s, for the presence of an extenstion e.
 *	Return the position of the start of e in s.
 *	or return NULL.
 */

char *checkext(s,e)
char *s,*e;
{
	register char *ps = s, *pe = e;

	while( *ps ) ps++;
	while( *pe ) pe++;

	for( ; ps>=s && pe>=e && tolower(*ps) == tolower(*pe); ps--, pe-- )
		if( pe == e ) return(ps);
	return(NULL);
}

main(argc,argv)
char *argv[];
{
	FILE *fin;
	char *p,*dashF=NULL, *dashA=NULL;
	char objfile[100];
	char lstfile[100];
        char basefile[100];
	int use_stdout=0;
	int delete_asm=0;
	int i;

	if( argc < 2 ) {
		fprintf(stderr,"Usage: %s [-Ffmt] [-Aarg] infile.asm\n",
						argv[0]);
		emitusage();
		exit(1);
	}

	for(i=1; i<argc; i++ ) {
		if( argv[i][0] != '-' ) break;
		if( argv[i][1] == 'l' ) dashl = 1;
		else if( dashF == NULL && argv[i][1] == 'F' )
			dashF = argv[i]+2;
		else if( dashA == NULL && argv[i][1] == 'A' )
			dashA = argv[i]+2;
		else if( !strcmp(argv[i], "-cgi") )
			delete_asm = use_stdout = 1;
		else {
			fprintf(stderr,"Duplicate or unknown flag.\n");
			exit(1);
		}
	}
        dashl = 1;            /* don't we always want a listing? */
	if (use_stdout) dashl = 0;  /* not when using stdout */
	if( i == argc ) {
		fprintf(stderr,"Missing input file.\n");
		exit(1);
	}


	asmfile = (char *)malloc(256);
	if( checkext(argv[i], ".asm") ) {
		strcpy(asmfile, argv[i]);
		strncpy(basefile, argv[i], strlen(argv[i])-4 );
		}
	else {
		strcpy(basefile, argv[i]);
		strcpy(asmfile, argv[i]);
		strcat(asmfile, ".asm");
		}

	strcpy(lstfile, basefile);
	strcat(lstfile, ".lst");
	strcpy(objfile, basefile);
	strcat(objfile, ".obj");

	if( (fin = freopen(asmfile,"r",stdin)) == NULL ) {
		fprintf(stderr,"Cannot open input file: %s\n",asmfile);
		exit(1);
	}

	if (dashl) {
		listing = fopen(lstfile,"w");
		if( listing == NULL ) {
			fprintf(stderr,"Cannot open file: %s for writting.\n",
				lstfile);
			exit(1);
		}
	}

	if (use_stdout) strcpy(objfile, "stdout");
	emitopen(objfile,dashF,dashA);

	syminit();
	fatal = 0;
	lineno = 1;
	pass=0;
	lc = 0x2000;

	if( setjmp(main_env) ) {
		fclose(fin);
		emitclose();
		if (!use_stdout) unlink(objfile);
		if (delete_asm) unlink(asmfile);
		exit(1);
	}

#ifdef MSDOS
	printf("AS31 - UNIX platform 8051 family assembler.\n");
	printf("Initial cross compile for MSDOS, 5-Oct-95.\n");
	printf("Please report problems to: paul@ece.orst.edu.\n\n");
#endif

	/*
	** P A S S    1
	*/
	if (!use_stdout) printf("Begin Pass #1\n");
	yyparse();
	if( fatal ) longjmp(main_env,1);

	rewind(fin);
	lineno = 1;
	pass++;
	lc = 0x2000;
	emitaddr(lc);

	/*
	** P A S S    2
	*/
        if (!use_stdout) printf("Begin Pass #2\n");
	yyparse();

	emitclose();
	fclose(fin);
	if( dashl )
		fclose(listing);
	if (delete_asm) unlink(asmfile);
	exit(0);

}
