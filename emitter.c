/* ----------------------------------------------------------------------
 * FILE: emitter.c
 * PACKAGE: as31 - 8031/8051 Assembler.
 *
 * DESCRIPTION:
 *	This file contains the code to generate various
 *	object code formats. Provisions exist to
 *	support many types of output formats within the
 *	same executable.
 *
 * REVISION HISTORY:
 *	Jan. 19, 1990 - Created. (Ken Stauffer)
 *	Jan. 29, 1990 - Added S-records (Theo Deraadt)
 *
 *
 * AUTHOR:
 *	All code in this file written by Ken Stauffer (University of Calgary).
 *	January, 1990.
 */

#include <stdio.h>

/* ----------------------------------------------------------------------
 * DECLARE your own open(), close(), addr(), and byte() routines here.
 *
 */

static int open1(), close1(), addr1(), byte1();
static int open2(), close2(), addr2(), byte2();
static int open3(), close3(), addr3(), byte3();
static int open4(), close4(), addr4(), byte4();
static int open5(), close5(), addr5(), byte5();

/* ----------------------------------------------------------------------
 * ADD an entry to this table to register your
 * output format routines. Give your object format
 * a name to be specified with the -F option.
 *
 */

static int format;
static struct {
	char *name;
	int (*e_open)();
	int (*e_close)();
	int (*e_addr)();
	int (*e_byte)();
} formtab[] = {
	{ "hex",   open5, close5, addr5, byte5 },
	{ "tdr",   open1, close1, addr1, byte1 },
	{ "byte",  open2, close2, addr2, byte2 },
	{ "od",    open3, close3, addr3, byte3 },
	{ "srec2", open4, close4, addr4, byte4 },
	{ "srec3", open4, close4, addr4, byte4 },
	{ "srec4", open4, close4, addr4, byte4 }
};

#define FORMTABSIZE	(sizeof(formtab)/sizeof(formtab[0]))

emitusage()
{
	int i;
	fprintf(stderr, "\tfmt is one of:");
	for(i=0; i<FORMTABSIZE; ) {
		fprintf(stderr, "%s", formtab[i].name);
		if( ++i < FORMTABSIZE)
			fprintf(stderr, ", ");
	}
	fprintf(stderr, ".\n");
}

emitopen(file,ftype,arg)
char *file,*ftype,*arg;
{
	int i;
	if( ftype ) {
		for(i=0; i<FORMTABSIZE; i++ ) {
			if( !strcmp(formtab[i].name,ftype) ) {
				format = i;
				(*formtab[format].e_open)(file,ftype,arg);
				return;
			}
		}
		fprintf(stderr, "warning: no format \"%s\", using \"%s\"\n",
			ftype, formtab[0].name);
	}
	/*
	 * 0th entry is the default format type
	 */
	format = 0;
	(*formtab[format].e_open)(file,ftype,arg);
}

emitclose()
{
	(*formtab[format].e_close)();
}

emitaddr(a)
unsigned long int a;
{
	(*formtab[format].e_addr)(a);
}

emitbyte(b)
int b;
{
	(*formtab[format].e_byte)(b);
}

/* ----------------------------------------------------------------------
 * Individual file format routines appear here:
 *	Each file format must define the following routines:
 *		open()	- Called ONCE before any of the others.
 *			It is passed with a filename and a format
 *			specific argument.
 *
 *		close() - Called ONCE when no more emit_byte()
 *			function calls will be made.
 *
 *		addr() - Called when ever a new address has been set
 *			in the assembler (ie. .org, .skip).
 *			This routine is also called once when the
 *			location counter is set to 0 at the very start of
 *			assembling.
 * 
 *		byte() - Called with each byte to be outputed.
 *
 */


static unsigned long addr;
static FILE *fout;
static long int offset;
static int newaddr;
static int pos=-666;
static unsigned char bytes[16];

/*-----------------------------------------------------------------------
 * "hex" format.  Intel HEX format expected by many EPROM programmers
 */


void hexdump()     /* dumps one line into file */
{
int i, sum;
     fprintf(fout,":%02X%04X00", pos, addr);
     sum = pos + ((addr>>8)&0xff) + (addr&0xff) ;
     for(i=0; i < pos; ++i) {
         fprintf(fout,"%02X", bytes[i]&0xff );
         sum += bytes[i]&0xff;
         }
     fprintf(fout, "%02X\n", (-sum)&0xff);
     addr += pos;
     pos = 0;
}

static open5(file,ftype,arg)
char *file, *ftype, *arg;
{
     if (strcmp(file, "stdout")) fout = fopen(file,"w");
     else fout = stdout;
     if( fout == NULL ) {
          fprintf(stderr,"Cannot open %s for writting.\n",file);
          exit(1);
     }
     pos = 0;
}

static close5()
{
     if ( pos > 0 ) hexdump();
     fprintf(fout, ":00000001FF\n");  /* end of file marker */
     fclose(fout);
}

static addr5(a)
unsigned long int a;
{

     if ( pos > 0 ) hexdump();
     addr = a;
}

static byte5(b)
unsigned char b;
{
     bytes[pos] = b;
     pos += 1;
     if ( pos == 16) hexdump();
}


/* ----------------------------------------------------------------------
 * "tdr" format. For tdr's 68008 system. Generates a
 * script file readable by a debugger.
 *      [addr] : [byte] [byte] ..
 *
 * arg: This is a number in decimal which specifies
 *      the offset, -Ftdr -A0000
 *
 *      These options specifies the tdr format, with an argument
 *      of 0. This becomes the offset used in generating the
 *      script file. The default if no A is present is 0x10000.
 * 
 */

static open1(file,ftype,arg)
char *file, *ftype, *arg;
{
	fout = fopen(file,"w");
	if( fout == NULL ) {
		fprintf(stderr,"Cannot open %s for writting.\n",file);
		exit(1);
	}
	if( arg ) {
		offset = atoi(arg);
	} else
		offset = 0x10000;
}

static close1()
{
	if( pos != 15 ) fprintf(fout,"\n");
	fclose(fout);
}

static addr1(a)
unsigned long int a;
{
	addr = a;
	newaddr = 1;
}



static byte1(b)
unsigned char b;
{
	if( newaddr ) {
		if( pos != -666 ) fprintf(fout,"\n");
		newaddr = 0;
		pos = 15;
		fprintf(fout,"%06x: ",addr+offset);
	} else if( pos == 15 ) {
		fprintf(fout,"%06x: ",addr+offset);
	}

	fprintf(fout,"%02x ", b&0xff );

	if( pos-- == 0 ) {
		fprintf(fout,"\n");
		pos = 15;
	}
	addr += 1;
}


/* ----------------------------------------------------------------------
 * "byte" format.
 *	Like "tdr" but each byte is on a line by itself.
 *	This is nice for debugging. No -A is used.
 */

static open2(file,ftype,arg)
char *file, *ftype, *arg;
{
	fout = fopen(file,"w");
	if( fout == NULL ) {
		fprintf(stderr,"Cannot open %s for writting.\n",file);
		exit(1);
	}
}

static close2()
{
	fclose(fout);
}

static addr2(a)
unsigned long int a;
{
	addr = a;
}

static byte2(b)
unsigned char b;
{
	fprintf(fout,"%04x: %02x\n", addr, b&0xff );
	addr += 1;
}


/* ----------------------------------------------------------------------
 * "od", this format shows 16 bytes per line, with address.
 *	It also includes ascii on one side.
 *
 * The format is similar to the od(1) program under Unix.
 *
 */

static int pos3;
static unsigned char buf[16];
static unsigned long saveaddr;

static open3(file,ftype,arg)
char *file, *arg;
{
	fout = fopen(file,"w");
	if( fout == NULL ) {
		fprintf(stderr,"Cannot open %s for writting.\n",file);
		exit(1);
	}
}

static close3()
{
	dumpline(saveaddr,buf,pos3-1);
	fclose(fout);
}

static addr3(a)
unsigned long int a;
{
	newaddr = 1;
	addr = a;
}

static byte3(b)
unsigned char b;
{
	if( newaddr ) {
		dumpline(saveaddr,buf,pos3-1);
		pos3 = 0;
		newaddr = 0;
		saveaddr = addr;
	} else if( pos3 == 16 ) {
		dumpline(saveaddr,buf,pos3-1);
		pos3 = 0;
		saveaddr = addr;
	}
	buf[pos3++] = b & 0x00ff;

	addr += 1;
}

dumpline(a,b,len)
unsigned long a;
unsigned char *b;
int len;
{
	int i;

	if(len <= 0 ) return;

	fprintf(fout,"%04x: ",a);

	for(i=0; i<8; i++ ) {
		if( i <= len )
			fprintf(fout,"%02x ",b[i]);
		else
			fprintf(fout,"   ");
	}

	fprintf(fout,"- ");

	for(i=8; i<16; i++ ) {
		if( i <= len )
			fprintf(fout,"%02x ",b[i]);
		else
			fprintf(fout,"   ");
	}
	fprintf(fout,"   ");

	for(i=0; i<16; i++ ) {
		if( i <= len )
			fprintf(fout,"%c",
				(b[i]>=' ' && b[i]<='~') ? b[i] : '.' );
		else
			break;
	}
	fprintf(fout,"\n");
}

/* ----------------------------------------------------------------------
 * srecord format. This is called with "-Fsrec2", "-Fsrec3", or
 * "-Fsrec4"...
 *
 * arg: This is a number in decimal which specifies
 *	the offset, -Fsrec3 -A0000
 *
 *	These options specifies the tdr format, with an argument
 *	of 0. This becomes the offset used in generating the
 *	script file. The default if no A is present is 0x0000.
 * 
 */
#define SREC_BYTESPERLINE 32

static char format4;
static int check4, index4;
static char buf4[SREC_BYTESPERLINE];
static long address4;

static open4(file,ftype,arg)
char *file, *ftype, *arg;
{
	format4 = ftype[4];		/* will be '2' -- '4' */

	fout = fopen(file,"w");
	if( fout == NULL ) {
		fprintf(stderr,"Cannot open %s for writing.\n",file);
		exit(1);
	}

	if(arg)	offset = atoi(arg);
	else	offset = 0;

	fprintf(fout, "S0030000%02X\n", (~3 & 0xff) );

}

static close4()
{
	if(index4)
		finishline();
	switch(format4) {
	case '2':
		fprintf(fout, "S9030000%02X\n", ~3 & 0xff);
		break;
	case '3':
		fprintf(fout, "S804000000%02X\n", ~4 & 0xff);
		break;
	case '4':
		fprintf(fout, "S70500000000%02X\n", ~5 & 0xff);
		break;
	}
	fclose(fout);
}


static addr4(a)
unsigned long int a;
{
	if(index4>0)
		finishline();
	address4 = a + offset;
}

static byte4(b)
{
	buf4[index4++] = b;
	if(index4==SREC_BYTESPERLINE) {
		finishline();
		address4 += SREC_BYTESPERLINE;
	}
}

finishline()
{
	int i;

	check4 = index4 + (address4 & 0xff) + ((address4>>8) & 0xff) + 4;

	switch(format4) {
	case '2':
		fprintf(fout, "S1%02X%04X", index4 + 4,	address4 & 0xffff);
		break;
	case '3':
		fprintf(fout, "S2%02X%06X", index4 + 6, address4 & 0xffffff);
		check4 += ((address4>>16) & 0xff) + 2;
		break;
	case '4':
		fprintf(fout, "S3%02X%08X", index4 + 8, address4);
		check4 += ((address4>>16) & 0xff) +((address4>>24) & 0xff) + 4;
		break;
	}

	for(i=0; i<index4; i++) {
		fprintf(fout, "%02X", buf4[i] & 0xff);
		check4 += buf4[i];
	}

	fprintf(fout, "%02X\n", (~check4 & 0xff) );
	index4 = 0;
}

