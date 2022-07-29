#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 22 "as31.y"

#include <setjmp.h>
#include <stdio.h>
#define NOPE
#include "as31.h"
#undef NOPE

#define YYSTYPE union ystack

extern int lineno;
extern int dashl;
extern char *asmfile;
extern jmp_buf main_env;
extern FILE *listing;

int pass,fatal;
unsigned long lc;

static unsigned char bytebuf[1024];		/* used by dumplist() */
static int bytecount;

/* ------------------------ G R A M M E R ----------------------------- */

#line 30 "y.tab.c"
#define STRING 257
#define D_ORG 258
#define D_BYTE 259
#define D_WORD 260
#define D_SKIP 261
#define D_EQU 262
#define D_FLAG 263
#define D_END 264
#define ACALL 265
#define ADD 266
#define ADDC 267
#define AJMP 268
#define ANL 269
#define CJNE 270
#define CLR 271
#define CPL 272
#define DA 273
#define DEC 274
#define DIV 275
#define DJNZ 276
#define INC 277
#define JB 278
#define JBC 279
#define JC 280
#define JMP 281
#define JNB 282
#define JNC 283
#define JNZ 284
#define JZ 285
#define LCALL 286
#define LJMP 287
#define MOV 288
#define MOVC 289
#define MOVX 290
#define NOP 291
#define MUL 292
#define ORL 293
#define POP 294
#define PUSH 295
#define RET 296
#define RETI 297
#define RL 298
#define RLC 299
#define RR 300
#define RRC 301
#define SETB 302
#define SJMP 303
#define SUBB 304
#define SWAP 305
#define XCH 306
#define XCHD 307
#define XRL 308
#define AB 309
#define A 310
#define C 311
#define PC 312
#define DPTR 313
#define BITPOS 314
#define R0 315
#define R1 316
#define R2 317
#define R3 318
#define R4 319
#define R5 320
#define R6 321
#define R7 322
#define VALUE 323
#define SYMBOL 324
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    4,    4,    4,    5,    5,
    5,    5,    5,    5,    5,    7,   11,   12,   12,    3,
    8,    8,    8,    8,    9,    9,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   16,
   16,   16,   16,   17,   17,   18,   18,   18,   24,   25,
   25,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   19,   19,   19,   19,   20,   20,
   20,   23,   23,   23,   23,   30,   31,   29,   29,   32,
   32,   28,   28,   28,   28,   28,   28,   28,   28,   27,
   27,   27,   27,   27,   27,   27,   27,   13,   14,   15,
   21,   22,
};
short yylen[] = {                                         2,
    1,    2,    1,    3,    1,    2,    2,    1,    3,    3,
    3,    3,    5,    5,    2,    1,    2,    1,    1,    1,
    3,    3,    1,    1,    3,    1,    1,    3,    2,    3,
    3,    3,    3,    3,    3,    3,    4,    4,    1,    1,
    1,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    5,    5,    2,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    7,    7,    7,    7,    5,    5,    5,    5,    3,
    3,    4,    4,    3,    4,    3,    4,    4,    3,    3,
    3,    3,    3,    4,    3,    3,    4,    4,    4,    5,
    4,    3,    3,    4,    1,    1,    1,    2,    1,    1,
    1,    5,    6,    6,    7,    1,    1,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   41,    0,    0,    0,
    0,   64,   65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   20,    8,    0,    0,    0,    3,
    0,    5,    0,    0,   40,   39,    0,   27,    0,    0,
   42,    0,   44,   45,   43,    0,    0,    0,   49,   50,
   51,    0,  142,  143,  144,  145,  146,  147,  148,  149,
    0,   84,    0,  129,  130,  141,  140,   72,  131,    0,
   73,   59,  125,    0,  127,   58,  126,   60,    0,   88,
    0,   57,   56,   85,    0,   87,    0,   79,    0,   86,
   80,   81,   82,    0,   78,   77,    0,    0,    0,    0,
   89,   90,   91,    0,    0,    0,    0,   63,   52,   53,
   54,   76,   75,   66,   67,   68,   69,   74,   83,   46,
   70,   55,   71,   47,   48,    0,    0,    0,    0,    0,
    0,   15,    2,    0,    6,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  150,  151,  152,  153,  154,  155,  156,  157,    0,
    0,  138,  128,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
   24,    0,   23,    0,    0,   26,   12,    0,    0,    4,
   28,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  101,  100,    0,    0,  106,  104,    0,    0,
    0,    0,    0,    0,  111,    0,  110,  109,    0,    0,
  122,    0,    0,    0,  123,    0,  116,  115,  112,    0,
  113,    0,    0,    0,    0,    0,    0,    0,    0,   37,
   38,  102,  103,  107,  108,  105,    0,    0,    0,    0,
   61,   62,  121,  118,    0,  119,  124,  117,  114,    0,
    0,    0,   97,   96,   99,   98,   22,   21,   25,    0,
   19,   18,   14,    0,    0,  132,    0,    0,  120,    0,
    0,    0,   17,  133,    0,  134,   94,   92,   95,   93,
  135,
};
short yydgoto[] = {                                      48,
   49,   50,   51,   52,   53,   54,  199,  202,  204,   67,
  293,  294,   68,  206,   61,   63,   70,   71,   96,   88,
  115,  108,   82,  104,  100,  123,  180,   97,   89,  235,
  237,   90,
};
short yysindex[] = {                                    -10,
  205, -295, -295,  205,   26,  243, -127, -127, -284,  283,
 -265,  191,  266, -303, -303,  205,  -16, -303,  205,  205,
  205,  205,  205,  121, -247,  -62,    0, -242,   26,  205,
  205,    0,    0, -224, -202, -196, -193, -127,  205, -295,
 -189, -295, -295,  125,    0,    0,  -58,    0,  -10,    0,
   14,    0,  136,  139,    0,    0,  205,    0,  205,  572,
    0,   83,    0,    0,    0,  109,  572,  110,    0,    0,
    0,  111,    0,    0,    0,    0,    0,    0,    0,    0,
  335,    0,  114,    0,    0,    0,    0,    0,    0, -155,
    0,    0,    0,  335,    0,    0,    0,    0,  118,    0,
  120,    0,    0,    0,  127,    0,  572,    0, -301,    0,
    0,    0,    0,  572,    0,    0,  129,  130,  335,  -15,
    0,    0,    0,  138,  145,  146,  253,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  205,  195,  205,  205, -144,
 -133,    0,    0,  197,    0,    0,  -30,  494,  205,  205,
  205,  205,  205,  205,  205,   69,  132,   84,  -23,   -7,
   88,    0,    0,    0,    0,    0,    0,    0,    0,  149,
  134,    0,    0,  205,  205,  205,  151,  155, -303,  173,
  165,  166,   71,   99,  148,  150,  172,  174,    0,  572,
    0,  176,    0,  177,  572,    0,    0,  178,  179,    0,
    0,  297,  297,  -30,  -30,  -30,  -55,  -55,  205,  205,
  335,  205,    0,    0, -303, -303,    0,    0,  205,  205,
  182,  192,  205,  572,    0,  572,    0,    0,  -96,  -82,
    0,  205,  105,  -81,    0,  335,    0,    0,    0,  205,
    0, -203,  320,  -78,  -76,  199,  205,  205, -181,    0,
    0,    0,    0,    0,    0,    0,  185,  205,  205,  194,
    0,    0,    0,    0,  205,    0,    0,    0,    0,  203,
  206,  208,    0,    0,    0,    0,    0,    0,    0,  572,
    0,    0,    0,  -72,  205,    0,  209,  205,    0, -161,
  -56,    2,    0,    0,  205,    0,    0,    0,    0,    0,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  252,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  299,
    0,    0,    0,    0,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  314,    0,    0,    0,
    0,    0,    0,  316,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  319,
    0,  322,    0,  323,   74,    0,    0,    0,    0,    0,
    0,   37,   60,   32,   46,   55,   -4,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  338,    0,  342,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  343,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
    0,  305,  211,  201,    0,    0,  207,    0,    0,  156,
    0,    0,  514, -238,  354,  620,  -13,  333,  350,   87,
  341,  117,    0,    7,    0,    0,   92,  175,   -1, -183,
    0,    0,
};
#define YYTABLESIZE 789
short yytable[] = {                                      46,
  139,  127,  238,  273,  167,   30,  166,  165,  187,  226,
  122,  188,  105,  105,   62,  130,  105,   31,  289,   86,
   87,  106,  158,  225,  110,   92,   29,  229,  193,  167,
  145,  166,   30,   30,  139,   47,   30,   30,   30,   30,
   30,   32,   30,   98,   31,   31,   36,  109,   31,   31,
   31,   31,   31,   29,   31,   33,  158,   29,   29,   29,
   29,   29,  125,   29,   34,   59,  128,   58,   32,   35,
   57,  154,   32,   32,   32,   32,   32,   36,   32,   36,
   36,   36,   33,  159,  296,  134,   33,   33,   33,   33,
   33,   34,   33,  164,   91,   34,   34,   34,   34,   34,
   35,   34,   35,   35,   35,  229,  280,  135,  281,  282,
   59,  304,   58,  136,  306,   57,  137,  159,  222,   30,
  141,  311,  230,   59,  138,   58,  168,   59,   57,   58,
  219,   31,   57,  250,  246,  111,  112,  113,   59,  275,
   58,  291,  292,   57,   59,  155,   58,  221,  156,   57,
  307,  308,  169,  170,  171,  139,   60,  181,  182,   60,
   59,  184,   58,  185,   59,   57,   58,  227,  233,   57,
  186,  107,  189,  190,  107,  107,  107,  114,  114,   45,
   83,  194,   84,   85,  119,  183,  101,  241,  195,  196,
  209,  220,  232,  239,  107,   86,   87,  240,  124,  146,
  147,  148,  149,  150,  151,  152,   46,  242,  243,  244,
  191,  252,  157,  253,  158,  254,  271,  255,  198,  256,
  257,  258,  259,  264,  265,  268,  269,  272,  295,  277,
   59,  285,   58,  286,   59,   57,   58,  298,   59,   57,
   58,  303,   47,   57,   59,  300,   58,  126,  301,   57,
  302,    1,  305,  309,    1,    2,    3,    4,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   39,   40,   41,   42,   43,   44,  192,   86,
   87,  200,  228,  205,  200,   59,   81,   58,  160,   30,
   57,  310,  262,   45,  212,  213,  214,  215,  216,  217,
  218,   31,   59,  162,   58,  161,  158,   57,   16,   94,
   29,   10,   11,  163,  165,   62,   66,  278,  161,  234,
  236,  234,  224,  162,  284,   32,   94,  136,   55,   56,
   36,  137,   13,  153,  210,  207,  167,   65,  166,   33,
  208,  131,  103,  116,    0,    0,    0,  248,   34,    0,
    0,    0,    0,   35,  260,  261,    0,    0,    0,    0,
  228,  245,    0,    0,    0,   73,   74,   75,   76,   77,
   78,   79,   80,   55,   56,    0,    0,  205,   73,   74,
   75,   76,   77,   78,   79,   80,   55,   56,  249,    0,
   55,   56,  205,  290,  274,    0,    0,    0,    0,    0,
  164,   55,   56,  234,    0,    0,    0,   55,   56,    0,
   62,  117,    0,  118,   62,   73,   74,   75,   76,   77,
   78,   79,   80,   55,   56,    0,    0,   55,   56,    0,
  234,  201,    0,  234,    0,  287,    0,    0,    0,    0,
  234,    1,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   73,   74,   75,   76,   77,
   78,   79,   80,   55,   56,    0,    0,   55,   56,    0,
    0,   55,   56,   95,    0,   99,   95,   55,   56,    0,
  163,  165,    0,    0,  211,  161,  159,  120,  160,    0,
  162,    0,    0,  132,  133,    0,    0,    0,    0,    0,
    0,    0,   72,  167,    0,  166,    0,   73,   74,   75,
   76,   77,   78,   79,   80,  197,    0,  172,  173,  174,
  175,  176,  177,  178,  179,   93,    0,    0,  102,    0,
   73,   74,   75,   76,   77,   78,   79,   80,   55,   56,
    0,    0,   93,    0,    0,    0,    0,   73,   74,   75,
   76,   77,   78,   79,   80,   55,   56,    0,  163,  165,
    0,    0,    0,  161,  159,    0,  160,  164,  162,    0,
    0,    0,   64,    0,   69,    0,    0,    0,    0,    0,
    0,  167,  283,  166,  172,  173,  174,  175,  176,  177,
  178,  179,    0,  121,    0,    0,    0,    0,  129,  172,
  173,  174,  175,  176,  177,  178,  179,    0,    0,  140,
  203,  142,  143,  144,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  223,    0,    0,  231,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  164,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  247,  251,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  263,    0,    0,    0,    0,
    0,    0,  266,  267,    0,    0,  270,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  276,    0,    0,    0,
    0,    0,    0,  279,    0,    0,    0,    0,    0,  288,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  297,    0,    0,    0,    0,    0,  299,
};
short yycheck[] = {                                      10,
   10,   64,  186,  242,   60,   10,   62,   38,  310,   33,
   24,  313,   14,   15,  310,   29,   18,   10,  257,  323,
  324,   15,   10,   47,   18,  310,   10,   35,   44,   60,
   44,   62,   37,   38,   44,   46,   41,   42,   43,   44,
   45,   10,   47,  309,   37,   38,   10,   64,   41,   42,
   43,   44,   45,   37,   47,   10,   44,   41,   42,   43,
   44,   45,  310,   47,   10,   40,  309,   42,   37,   10,
   45,   58,   41,   42,   43,   44,   45,   41,   47,   43,
   44,   45,   37,   10,  268,  310,   41,   42,   43,   44,
   45,   37,   47,  124,    8,   41,   42,   43,   44,   45,
   41,   47,   43,   44,   45,   35,  310,  310,  312,  313,
   40,  295,   42,  310,  298,   45,  310,   44,   35,  124,
  310,  305,   35,   40,   38,   42,   44,   40,   45,   42,
   62,  124,   45,   35,   64,   19,   20,   21,   40,   35,
   42,  323,  324,   45,   40,   10,   42,   64,   10,   45,
  312,  313,   44,   44,   44,   39,    1,   44,  314,    4,
   40,   44,   42,   44,   40,   45,   42,  169,   35,   45,
   44,   16,   44,   44,   19,   20,   21,   22,   23,  324,
    6,   44,  310,  311,   64,   94,   12,  189,   44,   44,
  324,   60,   44,   43,   39,  323,  324,   43,   24,  258,
  259,  260,  261,  262,  263,  264,   10,   35,   44,   44,
  119,   64,   57,   64,   59,   44,  313,   44,  127,   44,
   44,   44,   44,  225,  226,   44,   35,  310,   44,  311,
   40,  310,   42,  310,   40,   45,   42,   44,   40,   45,
   42,  314,   46,   45,   40,   43,   42,  310,   43,   45,
   43,    0,   44,  310,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,  295,  296,  297,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  307,  308,  314,  323,
  324,  146,  310,  148,  149,   40,   64,   42,   10,  314,
   45,  310,  221,  324,  159,  160,  161,  162,  163,  164,
  165,  314,   40,   10,   42,   10,  314,   45,   10,   64,
  314,   10,   10,   37,   38,  310,  311,  246,   42,  184,
  185,  186,  168,   47,  253,  314,   64,   10,  323,  324,
  314,   10,   10,   49,  154,  149,   60,    4,   62,  314,
  150,   29,   13,   23,   -1,   -1,   -1,  193,  314,   -1,
   -1,   -1,   -1,  314,  219,  220,   -1,   -1,   -1,   -1,
  310,  311,   -1,   -1,   -1,  315,  316,  317,  318,  319,
  320,  321,  322,  323,  324,   -1,   -1,  242,  315,  316,
  317,  318,  319,  320,  321,  322,  323,  324,  310,   -1,
  323,  324,  257,  258,  310,   -1,   -1,   -1,   -1,   -1,
  124,  323,  324,  268,   -1,   -1,   -1,  323,  324,   -1,
  310,  311,   -1,  313,  310,  315,  316,  317,  318,  319,
  320,  321,  322,  323,  324,   -1,   -1,  323,  324,   -1,
  295,  257,   -1,  298,   -1,  257,   -1,   -1,   -1,   -1,
  305,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,  300,  301,  302,  303,
  304,  305,  306,  307,  308,  315,  316,  317,  318,  319,
  320,  321,  322,  323,  324,   -1,   -1,  323,  324,   -1,
   -1,  323,  324,   10,   -1,   12,   13,  323,  324,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   24,   45,   -1,
   47,   -1,   -1,   30,   31,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  310,   60,   -1,   62,   -1,  315,  316,  317,
  318,  319,  320,  321,  322,  313,   -1,  315,  316,  317,
  318,  319,  320,  321,  322,  310,   -1,   -1,  313,   -1,
  315,  316,  317,  318,  319,  320,  321,  322,  323,  324,
   -1,   -1,  310,   -1,   -1,   -1,   -1,  315,  316,  317,
  318,  319,  320,  321,  322,  323,  324,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,  124,   47,   -1,
   -1,   -1,    3,   -1,    5,   -1,   -1,   -1,   -1,   -1,
   -1,   60,  313,   62,  315,  316,  317,  318,  319,  320,
  321,  322,   -1,   24,   -1,   -1,   -1,   -1,   29,  315,
  316,  317,  318,  319,  320,  321,  322,   -1,   -1,   40,
  147,   42,   43,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  168,   -1,   -1,  171,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  193,  194,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  222,   -1,   -1,   -1,   -1,
   -1,   -1,  229,  230,   -1,   -1,  233,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  243,   -1,   -1,   -1,
   -1,   -1,   -1,  250,   -1,   -1,   -1,   -1,   -1,  256,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  269,   -1,   -1,   -1,   -1,   -1,  275,
};
#define YYFINAL 48
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 324
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'",
"'/'",0,0,0,0,0,0,0,0,0,0,"':'",0,"'<'",0,"'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"STRING","D_ORG","D_BYTE","D_WORD",
"D_SKIP","D_EQU","D_FLAG","D_END","ACALL","ADD","ADDC","AJMP","ANL","CJNE",
"CLR","CPL","DA","DEC","DIV","DJNZ","INC","JB","JBC","JC","JMP","JNB","JNC",
"JNZ","JZ","LCALL","LJMP","MOV","MOVC","MOVX","NOP","MUL","ORL","POP","PUSH",
"RET","RETI","RL","RLC","RR","RRC","SETB","SJMP","SUBB","SWAP","XCH","XCHD",
"XRL","AB","A","C","PC","DPTR","BITPOS","R0","R1","R2","R3","R4","R5","R6","R7",
"VALUE","SYMBOL",
};
char *yyrule[] = {
"$accept : program",
"program : linelist",
"linelist : linelist line",
"linelist : line",
"line : undefsym ':' linerest",
"line : linerest",
"linerest : directive '\\n'",
"linerest : instr '\\n'",
"linerest : '\\n'",
"directive : '.' D_ORG defexpr",
"directive : '.' D_BYTE blist",
"directive : '.' D_WORD wlist",
"directive : '.' D_SKIP defexpr",
"directive : '.' D_EQU undefsym ',' expr",
"directive : '.' D_FLAG SYMBOL ',' flag",
"directive : '.' D_END",
"defexpr : expr",
"flag : flagv BITPOS",
"flagv : SYMBOL",
"flagv : VALUE",
"undefsym : SYMBOL",
"blist : blist ',' data8",
"blist : blist ',' STRING",
"blist : data8",
"blist : STRING",
"wlist : wlist ',' data16",
"wlist : data16",
"expr : '*'",
"expr : '(' expr ')'",
"expr : '-' expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '-' expr",
"expr : expr '+' expr",
"expr : expr '>' '>' expr",
"expr : expr '<' '<' expr",
"expr : SYMBOL",
"expr : VALUE",
"instr : NOP",
"instr : ACALL addr11",
"instr : AJMP addr11",
"instr : ADD two_op1",
"instr : ADDC two_op1",
"instr : SUBB two_op1",
"instr : XRL two_op1",
"instr : XRL two_op2",
"instr : ANL two_op1",
"instr : ANL two_op2",
"instr : ANL two_op3",
"instr : ORL two_op1",
"instr : ORL two_op2",
"instr : ORL two_op3",
"instr : XCH two_op1",
"instr : INC single_op1",
"instr : INC DPTR",
"instr : DEC single_op1",
"instr : DA A",
"instr : DIV AB",
"instr : JMP '@' A '+' DPTR",
"instr : JMP '@' DPTR '+' A",
"instr : MUL AB",
"instr : RET",
"instr : RETI",
"instr : RL A",
"instr : RLC A",
"instr : RR A",
"instr : RRC A",
"instr : SWAP A",
"instr : XCHD two_op1",
"instr : CLR single_op2",
"instr : CPL single_op2",
"instr : SETB single_op2",
"instr : PUSH data8",
"instr : POP data8",
"instr : LJMP addr16",
"instr : LCALL addr16",
"instr : JC relative",
"instr : JNC relative",
"instr : JNZ relative",
"instr : JZ relative",
"instr : SJMP relative",
"instr : CJNE three_op1",
"instr : JB two_op4",
"instr : JNB two_op4",
"instr : JBC two_op4",
"instr : DJNZ two_op5",
"instr : MOV two_op1",
"instr : MOV two_op2",
"instr : MOV two_op6",
"instr : MOVC A ',' '@' A '+' DPTR",
"instr : MOVC A ',' '@' DPTR '+' A",
"instr : MOVC A ',' '@' A '+' PC",
"instr : MOVC A ',' '@' PC '+' A",
"instr : MOVX A ',' '@' regi",
"instr : MOVX A ',' '@' DPTR",
"instr : MOVX '@' regi ',' A",
"instr : MOVX '@' DPTR ',' A",
"two_op1 : A ',' reg",
"two_op1 : A ',' data8",
"two_op1 : A ',' '@' regi",
"two_op1 : A ',' '#' data8",
"two_op2 : data8 ',' A",
"two_op2 : data8 ',' '#' data8",
"two_op3 : C ',' bit",
"two_op3 : C ',' '/' bit",
"two_op3 : C ',' '!' bit",
"two_op4 : bit ',' rel",
"two_op5 : reg ',' rel2",
"two_op5 : data8 ',' rel",
"two_op6 : reg ',' A",
"two_op6 : reg ',' data8",
"two_op6 : reg ',' '#' data8",
"two_op6 : data8 ',' reg",
"two_op6 : data8 ',' data8",
"two_op6 : data8 ',' '@' regi",
"two_op6 : '@' regi ',' A",
"two_op6 : '@' regi ',' data8",
"two_op6 : '@' regi ',' '#' data8",
"two_op6 : DPTR ',' '#' data16",
"two_op6 : C ',' bit",
"two_op6 : data8 ',' C",
"two_op6 : data8 BITPOS ',' C",
"single_op1 : A",
"single_op1 : reg",
"single_op1 : data8",
"single_op1 : '@' regi",
"single_op2 : A",
"single_op2 : C",
"single_op2 : bit",
"three_op1 : A ',' data8 ',' rel",
"three_op1 : A ',' '#' data8 ',' rel",
"three_op1 : reg ',' '#' data8 ',' rel",
"three_op1 : '@' regi ',' '#' data8 ',' rel",
"rel : expr",
"rel2 : expr",
"bit : bitv BITPOS",
"bit : bitv",
"bitv : SYMBOL",
"bitv : VALUE",
"reg : R0",
"reg : R1",
"reg : R2",
"reg : R3",
"reg : R4",
"reg : R5",
"reg : R6",
"reg : R7",
"regi : R0",
"regi : R1",
"regi : R2",
"regi : R3",
"regi : R4",
"regi : R5",
"regi : R6",
"regi : R7",
"data8 : expr",
"data16 : expr",
"addr11 : expr",
"addr16 : expr",
"relative : expr",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 957 "as31.y"

/* ---------------------------------------------------------------------- */

yyerror(s)
char *s;
{
	error(s);
}


/* ----------------------------------------------------------------------
 * error:
 *	Uses semi-variable arguments. This causes immediate assembler
 *	termination.
 */

error(cs,a1,a2,a3,a4,a5,a6)
char *cs,*a1,*a2,*a3,*a4,*a5,*a6;
{
	fprintf(stderr,"line: %d, ",lineno);
	fprintf(stderr,cs,a1,a2,a3,a4,a5,a6);
	fprintf(stderr,".\n");
	longjmp(main_env,1);
}

/* ----------------------------------------------------------------------
 * warning:
 *	Produce error message. This will abort assembly at
 *	the end of the current pass.
 *
 */

warning(cs,a1,a2,a3,a4,a5,a6)
char *cs,*a1,*a2,*a3,*a4,*a5,*a6;
{
	fatal++;
	fprintf(stderr,"line: %d, ",lineno);
	fprintf(stderr,cs,a1,a2,a3,a4,a5,a6);
	fprintf(stderr,".\n");
}


/* ----------------------------------------------------------------------
 * makeop:
 *	This function makes an opcode based on the instruction symbol table
 *	entry, and an addressing mode structure.
 *	This function is called from both passes, but
 *	only generates code in pass 2.
 *
 *	Resultant opcode bytes are passed to genbyte().
 *
 *	Returns the nuumber of bytes that the instruction
 *	occupies.
 *
 */

makeop(op,m,add)
struct opcode *op;
struct mode *m;
{
	register unsigned int newop;

	if( m == NULL ) {
		if(pass2) genbyte(op->bytes[0+add]);
		return(1);
	}

	if( pass2 ) {
		newop = op->bytes[ get_md(*m)+add ] | get_ov(*m);
		genbyte(newop);
		if( get_sz(*m) > 0 ) genbyte( get_b1(*m) );
		if( get_sz(*m) > 1 ) genbyte( get_b2(*m) );
	}
	return( get_sz(*m)+1 );
}


/* ----------------------------------------------------------------------
 * inclc:
 *	Increments the Location Counter by 'i' amount.
 *	Check to see if 'i' overflows 64K.
 *	Checks to see if assembler is overlapping previous sections
 *	of code. (using a large bit field).
 *
 */

#define indx(a) ( (a)/(sizeof(long)*8) )
#define bit(a)	( 1 << ((a)%(sizeof(long)*8)) )

#define getloc(a) (regions[indx(a)] & bit(a))
#define setloc(a) (regions[indx(a)] |= bit(a))

inclc(i)
{
	static unsigned long regions[ 0x10000/(sizeof(long)*8) ];

	while(i-- > 0) {
		if( pass2 && getloc(lc) )
			error("Location counter overlaps");
		if( pass2 ) setloc(lc);
		lc += 1;
	}
		
	if( lc > 0xffff )
		error("Location counter has exceeded 16-bits");
}

/* ----------------------------------------------------------------------
 * padline:
 *	This routine returns a new string, which is equivilant to
 *	'line' except that all tabs have been expanded to spaces, and
 *	the total length has been truncated to 60 chars.
 */

char *padline(line)
char *line;
{
	static char newline[61];
	char *p1;
	int pos=0,nxtpos;

	for(p1=line; pos<sizeof(newline)-1 && *p1; p1++ ) {
		if( *p1 == '\t' ) {
			nxtpos = pos+8-pos%8;
			while(pos<sizeof(newline)-1 && pos <= nxtpos)
				newline[pos++] = ' ';
		} else if( *p1 != '\n' )
			newline[pos++]= *p1;
	}
	newline[pos] = '\0';
	return(newline);
}


/* ----------------------------------------------------------------------
 * dumplist:
 *	Outputs the current location counter, bytebuf[] array, and
 *	the string 'txt' to the listing file.
 *	This routine is called for every source line encountered in the
 *	source file. (Only in pass 2, and if listing is turned on).
 *
 */

dumplist(txt,show)
char *txt;
{
	int i,j;

	fprintf(listing,show?"%04X: ":"      ",lc);

	j=0;
	for(i=0; i<bytecount; i++ ) {
		fprintf(listing,"%02X ",bytebuf[i]);
		if( ++j >= 4 ) {
			j = 0;
			fprintf(listing,"\n      ");
		}
	}
	while(++j <= 4)
		fprintf(listing,"   ");

	fprintf(listing," %s\n",padline(txt));
}

/* ----------------------------------------------------------------------
 * gen* routines:
 *	Place information into the bytebuf[] array, and also
 *	call emitbyte with the byte.
 *
 */

genbyte(b)
int b;
{
	if( bytecount < sizeof(bytebuf) )
		bytebuf[bytecount++] = b;
	emitbyte(b);
}

genstr(s)
char *s;
{
	while( *s )
		genbyte(*s++);
}

genword(w)
unsigned long w;
{
	genbyte( (w & 0xff00) >> 8 );
	genbyte( (w & 0x00ff) );
}

#line 825 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d\n",
                    yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 125 "as31.y"
{
}
break;
case 4:
#line 134 "as31.y"
{
	if( pass1 ) {
		yyvsp[-2].sym->type = LABEL;
		yyvsp[-2].sym->value = lc;
	}
	inclc(yyvsp[0].value);
	bytecount = 0;
}
break;
case 5:
#line 142 "as31.y"
{ inclc(yyvsp[0].value); bytecount = 0; }
break;
case 6:
#line 145 "as31.y"
{
						yyval.value = yyvsp[-1].value;
						if( dashl && pass2 )
							dumplist(yyvsp[0].str,1);
					}
break;
case 7:
#line 150 "as31.y"
{
						yyval.value = yyvsp[-1].value;
						if( dashl && pass2 )
							dumplist(yyvsp[0].str,1);

					}
break;
case 8:
#line 156 "as31.y"
{
						yyval.value = 0;
						if( dashl && pass2 )
							dumplist(yyvsp[0].str,0);
					}
break;
case 9:
#line 173 "as31.y"
{
	lc = yyvsp[0].val.v;
	if( pass2 ) emitaddr(lc);
	bytecount = 0;
	yyval.value = 0;
}
break;
case 10:
#line 179 "as31.y"
{ yyval.value = yyvsp[0].value; }
break;
case 11:
#line 180 "as31.y"
{ yyval.value = yyvsp[0].value; }
break;
case 12:
#line 181 "as31.y"
{ yyval.value = yyvsp[0].val.v;
					  if( pass2 )
						emitaddr(lc+yyval.value); }
break;
case 13:
#line 185 "as31.y"
{
	if( yyvsp[0].val.d == 0 )
		error("Expression is undefined in pass 1");
	yyvsp[-2].sym->type = LABEL;
	yyvsp[-2].sym->value = yyvsp[0].val.v;
	yyval.value = 0;
}
break;
case 14:
#line 194 "as31.y"
{
	yyvsp[-2].sym->type = LABEL;
	yyvsp[-2].sym->value = yyvsp[0].value;
	yyval.value = 0;
}
break;
case 15:
#line 199 "as31.y"
{ yyval.value = 0; }
break;
case 16:
#line 203 "as31.y"
{
		if( yyvsp[0].val.d == 0 )
			error("Expression is undefined in pass 1");
		if( !(isbit16(yyvsp[0].val.v)) )
			error("Value greater than 16-bits");
		yyval.value = yyvsp[0].val.v;
}
break;
case 17:
#line 213 "as31.y"
{
	if( !isbit8(yyvsp[-1].value) )
		warning("Bit address exceeds 8-bits");
	if( isbmram(yyvsp[-1].value) )
		yyval.value = (yyvsp[-1].value-0x20)*8+ yyvsp[0].value;
	else if( isbmsfr(yyvsp[-1].value) )
		yyval.value = yyvsp[-1].value + yyvsp[0].value;
	else
		warning("Invalid bit addressable RAM location");
}
break;
case 18:
#line 226 "as31.y"
{
	if( yyvsp[0].sym->type == UNDEF )
		error("Symbol %s must be defined in pass 1",yyvsp[0].sym->name);
	yyval.value = yyvsp[0].sym->value;
}
break;
case 19:
#line 231 "as31.y"
{ yyval.value = yyvsp[0].value; }
break;
case 20:
#line 236 "as31.y"
{
	if( yyvsp[0].sym->type != UNDEF && pass1)
		error("Attempt to redefine symbol: %s",yyvsp[0].sym->name);
	yyval.sym = yyvsp[0].sym;
}
break;
case 21:
#line 244 "as31.y"
{
	if( pass2 ) genbyte(yyvsp[0].value);
	yyval.value = yyvsp[-2].value + 1;
}
break;
case 22:
#line 249 "as31.y"
{
	if( pass1 )
		yyval.value = yyvsp[-2].value + yyvsp[0].value;
	else {
		yyval.value = yyvsp[-2].value + strlen(yyvsp[0].str);
		genstr(yyvsp[0].str);
		
		free(yyvsp[0].str);
	}
}
break;
case 23:
#line 260 "as31.y"
{
	if( pass2 ) genbyte(yyvsp[0].value);
	yyval.value = 1;
}
break;
case 24:
#line 265 "as31.y"
{
	if( pass1 )
		yyval.value = yyvsp[0].value;
	else {
		yyval.value = strlen(yyvsp[0].str);
		genstr(yyvsp[0].str);
		free(yyvsp[0].str);
	}
}
break;
case 25:
#line 277 "as31.y"
{
	if( pass2 ) genword(yyvsp[0].value);
	yyval.value = yyvsp[-2].value + 2;
}
break;
case 26:
#line 282 "as31.y"
{
	if( pass2 ) genword(yyvsp[0].value);
	yyval.value = 2;
}
break;
case 27:
#line 295 "as31.y"
{ yyval.val.v = lc;
					  yyval.val.d = 1; }
break;
case 28:
#line 298 "as31.y"
{ yyval.val.v = yyvsp[-1].val.v;
					  yyval.val.d = yyvsp[-1].val.d; }
break;
case 29:
#line 301 "as31.y"
{ yyval.val.v = -yyvsp[0].val.v;
					  yyval.val.d = yyvsp[0].val.d;  }
break;
case 30:
#line 304 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v | yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 31:
#line 307 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v & yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 32:
#line 310 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v * yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 33:
#line 313 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v / yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 34:
#line 316 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v % yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 35:
#line 319 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v - yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 36:
#line 322 "as31.y"
{ yyval.val.v = yyvsp[-2].val.v + yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-2].val.d && yyvsp[0].val.d; }
break;
case 37:
#line 325 "as31.y"
{ yyval.val.v = yyvsp[-3].val.v >> yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d; }
break;
case 38:
#line 328 "as31.y"
{ yyval.val.v = yyvsp[-3].val.v << yyvsp[0].val.v;
					  yyval.val.d = yyvsp[-3].val.d && yyvsp[0].val.d; }
break;
case 39:
#line 331 "as31.y"
{
	if( pass1 ) {
		yyval.val.v = yyvsp[0].sym->value;
		yyval.val.d = (yyvsp[0].sym->type != UNDEF);
	}
	else {
		if( yyvsp[0].sym->type == UNDEF )
			error("Undefined symbol %s",yyvsp[0].sym->name);
		yyval.val.v = yyvsp[0].sym->value;
		yyval.val.d = 1;
	}
}
break;
case 40:
#line 343 "as31.y"
{ yyval.val.v = yyvsp[0].val.v; yyval.val.d=1; }
break;
case 41:
#line 356 "as31.y"
{ yyval.value = makeop(yyvsp[0].op,NULL,0); }
break;
case 42:
#line 358 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 43:
#line 360 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 44:
#line 362 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 45:
#line 364 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 46:
#line 366 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 47:
#line 368 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 48:
#line 370 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
break;
case 49:
#line 372 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 50:
#line 374 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
break;
case 51:
#line 376 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,6); }
break;
case 52:
#line 378 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 53:
#line 380 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
break;
case 54:
#line 382 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,6); }
break;
case 55:
#line 384 "as31.y"
{ if( get_md(yyvsp[0].mode) == 3 )
					error("Immediate mode is illegal");
				  yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0);
				}
break;
case 56:
#line 389 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 57:
#line 391 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,4); }
break;
case 58:
#line 393 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 59:
#line 395 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 60:
#line 397 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 61:
#line 399 "as31.y"
{ yyval.value = makeop(yyvsp[-4].op,NULL,0); }
break;
case 62:
#line 401 "as31.y"
{ yyval.value = makeop(yyvsp[-4].op,NULL,0); }
break;
case 63:
#line 403 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 64:
#line 405 "as31.y"
{ yyval.value = makeop(yyvsp[0].op,NULL,0); }
break;
case 65:
#line 407 "as31.y"
{ yyval.value = makeop(yyvsp[0].op,NULL,0); }
break;
case 66:
#line 409 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 67:
#line 411 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 68:
#line 413 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 69:
#line 415 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 70:
#line 417 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,NULL,0); }
break;
case 71:
#line 419 "as31.y"
{ if( get_md(yyvsp[0].mode) != 2 )
					error("Invalid addressing mode");
				  yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,-2); }
break;
case 72:
#line 423 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 73:
#line 425 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 74:
#line 427 "as31.y"
{ if( get_md(yyvsp[0].mode) == 0 )
					error("Invalid addressing mode");
				  yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,-1); }
break;
case 75:
#line 431 "as31.y"
{
				   struct mode tmp;
					set_md(tmp,0);
					set_ov(tmp,0);
					set_sz(tmp,1);
					set_b1(tmp,yyvsp[0].value);
					yyval.value = makeop(yyvsp[-1].op,&tmp,0);
				}
break;
case 76:
#line 440 "as31.y"
{
				   struct mode tmp;
					set_md(tmp,0);
					set_ov(tmp,0);
					set_sz(tmp,1);
					set_b1(tmp,yyvsp[0].value);
					yyval.value = makeop(yyvsp[-1].op,&tmp,0);
				}
break;
case 77:
#line 449 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 78:
#line 451 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 79:
#line 453 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 80:
#line 455 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 81:
#line 457 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 82:
#line 459 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 83:
#line 461 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 84:
#line 463 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 85:
#line 465 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 86:
#line 467 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 87:
#line 469 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 88:
#line 471 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 89:
#line 473 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,0); }
break;
case 90:
#line 475 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,4); }
break;
case 91:
#line 477 "as31.y"
{ yyval.value = makeop(yyvsp[-1].op,&yyvsp[0].mode,6); }
break;
case 92:
#line 481 "as31.y"
{ yyval.value = makeop(yyvsp[-6].op,NULL,0); }
break;
case 93:
#line 483 "as31.y"
{ yyval.value = makeop(yyvsp[-6].op,NULL,0); }
break;
case 94:
#line 485 "as31.y"
{ yyval.value = makeop(yyvsp[-6].op,NULL,1); }
break;
case 95:
#line 487 "as31.y"
{ yyval.value = makeop(yyvsp[-6].op,NULL,1); }
break;
case 96:
#line 490 "as31.y"
{ yyval.value = makeop(yyvsp[-4].op,NULL,yyvsp[0].value); }
break;
case 97:
#line 492 "as31.y"
{ yyval.value = makeop(yyvsp[-4].op,NULL,2); }
break;
case 98:
#line 494 "as31.y"
{ yyval.value = makeop(yyvsp[-4].op,NULL,yyvsp[-2].value+3); }
break;
case 99:
#line 496 "as31.y"
{ yyval.value = makeop(yyvsp[-4].op,NULL,5); }
break;
case 100:
#line 508 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode, yyvsp[0].value);
					set_sz(yyval.mode, 0);
				}
break;
case 101:
#line 514 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 102:
#line 521 "as31.y"
{
					set_md(yyval.mode,2);
					set_ov(yyval.mode,yyvsp[0].value);
					set_sz(yyval.mode,0);
				}
break;
case 103:
#line 527 "as31.y"
{
					set_md(yyval.mode,3);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 104:
#line 536 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[-2].value);
				}
break;
case 105:
#line 543 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-3].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 106:
#line 553 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 107:
#line 560 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 108:
#line 567 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 109:
#line 576 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-2].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 110:
#line 586 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,yyvsp[-2].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 111:
#line 593 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-2].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 112:
#line 603 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,yyvsp[-2].value);
					set_sz(yyval.mode,0);
				}
break;
case 113:
#line 609 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,yyvsp[-2].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 114:
#line 616 "as31.y"
{
					set_md(yyval.mode,2);
					set_ov(yyval.mode,yyvsp[-3].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 115:
#line 623 "as31.y"
{
					set_md(yyval.mode,3);
					set_ov(yyval.mode,yyvsp[0].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[-2].value);
				}
break;
case 116:
#line 630 "as31.y"
{
					set_md(yyval.mode,4);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[0].value);
					set_b2(yyval.mode,yyvsp[-2].value);
				}
break;
case 117:
#line 638 "as31.y"
{
					set_md(yyval.mode,5);
					set_ov(yyval.mode,yyvsp[0].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[-3].value);
				}
break;
case 118:
#line 645 "as31.y"
{
					set_md(yyval.mode,6);
					set_ov(yyval.mode,yyvsp[-2].value);
					set_sz(yyval.mode,0);
				}
break;
case 119:
#line 651 "as31.y"
{
					set_md(yyval.mode,7);
					set_ov(yyval.mode,yyvsp[-2].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 120:
#line 658 "as31.y"
{
					set_md(yyval.mode,8);
					set_ov(yyval.mode,yyvsp[-3].value);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 121:
#line 665 "as31.y"
{
				set_md(yyval.mode,9);
				set_ov(yyval.mode,0);
				set_sz(yyval.mode,2);
				set_b1(yyval.mode, (yyvsp[0].value & 0xff00) >> 8 );
				set_b2(yyval.mode, (yyvsp[0].value & 0x00ff) );
			}
break;
case 122:
#line 673 "as31.y"
{
					set_md(yyval.mode,10);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 123:
#line 689 "as31.y"
{
					set_md(yyval.mode,11);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[-2].value);
				}
break;
case 124:
#line 696 "as31.y"
{
	if( pass2 ) {
		if( !isbit8(yyvsp[-3].value) )
			warning("Bit address exceeds 8-bits");
		if( isbmram(yyvsp[-3].value) )
			set_b1(yyval.mode, (yyvsp[-3].value-0x20)*8+ yyvsp[-2].value );
		else if( isbmsfr(yyvsp[-3].value) )
			set_b1(yyval.mode, yyvsp[-3].value + yyvsp[-2].value );
		else
			warning("Invalid bit addressable RAM location");
	}
	set_md(yyval.mode,11);
	set_ov(yyval.mode,0);
	set_sz(yyval.mode,1);
}
break;
case 125:
#line 715 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,0);
				}
break;
case 126:
#line 722 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,yyvsp[0].value);
					set_sz(yyval.mode,0);
				}
break;
case 127:
#line 728 "as31.y"
{
					set_md(yyval.mode,2);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 128:
#line 735 "as31.y"
{
					set_md(yyval.mode,3);
					set_ov(yyval.mode,yyvsp[0].value);
					set_sz(yyval.mode,0);
				}
break;
case 129:
#line 743 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,0);
				}
break;
case 130:
#line 749 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,0);
				}
break;
case 131:
#line 755 "as31.y"
{
					set_md(yyval.mode,2);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,1);
					set_b1(yyval.mode,yyvsp[0].value);
				}
break;
case 132:
#line 764 "as31.y"
{
					set_md(yyval.mode,0);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-2].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 133:
#line 772 "as31.y"
{
					set_md(yyval.mode,1);
					set_ov(yyval.mode,0);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-2].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 134:
#line 780 "as31.y"
{
					set_md(yyval.mode,2);
					set_ov(yyval.mode,yyvsp[-5].value);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-2].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 135:
#line 788 "as31.y"
{
					set_md(yyval.mode,3);
					set_ov(yyval.mode,yyvsp[-5].value);
					set_sz(yyval.mode,2);
					set_b1(yyval.mode,yyvsp[-2].value);
					set_b2(yyval.mode,yyvsp[0].value);
				}
break;
case 136:
#line 798 "as31.y"
{
		long offset;
		if( pass2 ) {
			offset = yyvsp[0].val.v - (lc+3);
			if( offset > 127 || offset < -128 )
			   warning("Relative offset exceeds -128 / +127");
			yyval.value = offset;
		}
}
break;
case 137:
#line 815 "as31.y"
{
		long offset;
		if( pass2 ) {
			offset = yyvsp[0].val.v - (lc+2); /* different! */
			if( offset > 127 || offset < -128 )
			   warning("Relative offset exceeds -128 / +127");
			yyval.value = offset;
		}
}
break;
case 138:
#line 828 "as31.y"
{
	if( pass2 ) {
		if( !isbit8(yyvsp[-1].value) )
			warning("Bit address exceeds 8-bits");
		if( isbmram(yyvsp[-1].value) )
			yyval.value = (yyvsp[-1].value-0x20)*8+yyvsp[0].value;
		else if( isbmsfr(yyvsp[-1].value) )
			yyval.value = yyvsp[-1].value + yyvsp[0].value;
		else
			warning("Invalid bit addressable RAM location");
	}
}
break;
case 139:
#line 841 "as31.y"
{
	if( pass2 ) {
		if( !isbit8(yyvsp[0].value) )
			warning("Bit address exceeds 8-bits");
		yyval.value = yyvsp[0].value;
	}
}
break;
case 140:
#line 851 "as31.y"
{
	if( yyvsp[0].sym->type == UNDEF && pass2 )
		error("Symbol %s undefined",yyvsp[0].sym->name);
	yyval.value = yyvsp[0].sym->value;
}
break;
case 141:
#line 856 "as31.y"
{ yyval.value = yyvsp[0].value; }
break;
case 142:
#line 859 "as31.y"
{ yyval.value = 0; }
break;
case 143:
#line 860 "as31.y"
{ yyval.value = 1; }
break;
case 144:
#line 861 "as31.y"
{ yyval.value = 2; }
break;
case 145:
#line 862 "as31.y"
{ yyval.value = 3; }
break;
case 146:
#line 863 "as31.y"
{ yyval.value = 4; }
break;
case 147:
#line 864 "as31.y"
{ yyval.value = 5; }
break;
case 148:
#line 865 "as31.y"
{ yyval.value = 6; }
break;
case 149:
#line 866 "as31.y"
{ yyval.value = 7; }
break;
case 150:
#line 869 "as31.y"
{ yyval.value = 0; }
break;
case 151:
#line 870 "as31.y"
{ yyval.value = 1; }
break;
case 152:
#line 872 "as31.y"
{ yyval.value = 0;
				  warning("Illegal indirect register: @r2"); }
break;
case 153:
#line 875 "as31.y"
{ yyval.value = 0;
				  warning("Illegal indirect register: @r3"); }
break;
case 154:
#line 878 "as31.y"
{ yyval.value = 0;
				  warning("Illegal indirect register: @r4"); }
break;
case 155:
#line 881 "as31.y"
{ yyval.value = 0;
				  warning("Illegal indirect register: @r5"); }
break;
case 156:
#line 884 "as31.y"
{ yyval.value = 0;
				  warning("Illegal indirect register: @r6"); }
break;
case 157:
#line 887 "as31.y"
{ yyval.value = 0;
				  warning("Illegal indirect register: @r7"); }
break;
case 158:
#line 892 "as31.y"
{
	if( pass2 ) {
		if( !isbit8(yyvsp[0].val.v) )
			warning("Expression greater than 8-bits");
	}
	yyval.value = yyvsp[0].val.v;
}
break;
case 159:
#line 902 "as31.y"
{
	if( pass2 ) {
		if( !isbit16(yyvsp[0].val.v) )
			warning("Expression greater than 16-bits");
	}
	yyval.value = yyvsp[0].val.v;
}
break;
case 160:
#line 912 "as31.y"
{
		if( pass2 ) {
			if( !isbit16(yyvsp[0].val.v)  )
				warning("Address greater than 16-bits");
			if( (yyvsp[0].val.v & size11) != ((lc+2) & size11) )
				warning("Address outside current 2K page");
		}
		set_md(yyval.mode,0);
		set_ov(yyval.mode, (yyvsp[0].val.v&0x0700)>>3 );
		set_sz(yyval.mode,1);
		set_b1(yyval.mode,yyvsp[0].val.v&0x00ff);
}
break;
case 161:
#line 927 "as31.y"
{
		if( pass2 ) {
			if( !isbit16(yyvsp[0].val.v)  )
				warning("Address greater than 16-bits");
		}
		set_md(yyval.mode,0);
		set_ov(yyval.mode, 0 );
		set_sz(yyval.mode,2);
		set_b1(yyval.mode, (yyvsp[0].val.v & 0xff00 ) >> 8 );
		set_b2(yyval.mode, (yyvsp[0].val.v & 0x00ff ) );
}
break;
case 162:
#line 941 "as31.y"
{
		long offset;
		if( pass2 ) {
			offset = yyvsp[0].val.v - (lc+2);
			if( offset>127 || offset<-128 )
			   warning("Relative offset exceeds -128 / +127");
		}
		set_md(yyval.mode,0);
		set_ov(yyval.mode,0);
		set_sz(yyval.mode,1);
		set_b1(yyval.mode,offset);

}
break;
#line 2016 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
