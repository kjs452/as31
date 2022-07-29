# FILE: makefile
# PACKAGE: as31 - 8031/8051 Assembler.
#
# DESCRIPTION:
#
#
# REVISION HISTORY:
#		Jan. 19, 1990 - Created. (Ken Stauffer).
#		Jan. 30, 1990 - Theo played here.
#               Late 1994     - Paul Stoffregen updates the code
#               Sept 1995     - bug fixes, add obsure option for cgi


#Use this CFLAGS line with gcc on linux
CFLAGS=-O2 -m486 -fomit-frame-pointer
CC=gcc

#Use this CFLAGS line on solaris, etc
#CFLAGS=-O

#Try these for HPUX
#CFLAGS=-O2
#CC=gcc

YACCFLAGS=-d
OBJ=as31.o symbol.o lexer.o emitter.o main.o

as31:		$(OBJ)
		$(CC) $(CFLAGS) -o as31 $(OBJ)
		chmod a+rx as31

main.o:		main.c as31.h
emitter.o:	emitter.c as31.h
symbol.o:	symbol.c as31.h
lexer.o:	lexer.c as31.h
as31.o:		as31.c
as31.c:		as31.y as31.h
		yacc $(YACCFLAGS) as31.y
		/bin/mv y.tab.c as31.c

clean:
		$(RM) *~ *.o as31.c y.tab.h as31.shar core
