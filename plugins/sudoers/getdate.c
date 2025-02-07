/*
 * This is an open source non-commercial project. Dear PVS-Studio, please check it.
 * PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 */

#include <config.h>
#include <stdlib.h>
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "getdate.y"
/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  This grammar has 10 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
*/
/* SUPPRESS 287 on yaccpar_sccsid *//* Unused static variable */
/* SUPPRESS 288 on yyerrlab *//* Label unused */

/* PVS Studio suppression*/
/* -V::1037, 1042*/

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(HAVE_STDINT_H)
# include <stdint.h>
#elif defined(HAVE_INTTYPES_H)
# include <inttypes.h>
#endif
#include <time.h>
#include <limits.h>
#include <ctype.h>

#include "sudo_compat.h"


#define EPOCH		1970
#define HOUR(x)		((time_t)(x) * 60)
#define SECSPERDAY	(24L * 60L * 60L)


/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    char	*name;
    int		type;
    time_t	value;
} TABLE;


/*
**  Daylight-savings mode:  on, off, or not yet known.
*/
typedef enum _DSTMODE {
    DSTon, DSToff, DSTmaybe
} DSTMODE;

/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;


/*
**  Global variables.  We could get rid of most of these by using a good
**  union as the yacc stack.  (This routine was originally written before
**  yacc had the %union construct.)  Maybe someday; right now we only use
**  the %union very rarely.
*/
static char	*yyInput;
static DSTMODE	yyDSTmode;
static time_t	yyDayOrdinal;
static time_t	yyDayNumber;
static int	yyHaveDate;
static int	yyHaveDay;
static int	yyHaveRel;
static int	yyHaveTime;
static int	yyHaveZone;
static time_t	yyTimezone;
static time_t	yyDay;
static time_t	yyHour;
static time_t	yyMinutes;
static time_t	yyMonth;
static time_t	yySeconds;
static time_t	yyYear;
static MERIDIAN	yyMeridian;
static time_t	yyRelMonth;
static time_t	yyRelSeconds;

static int	yylex(void);
       int	yyparse(void);
       void	yyerror(const char *s);

#line 97 "getdate.y"
#ifndef YYSTYPE_DEFINED
#define YYSTYPE_DEFINED
typedef union {
    time_t		Number;
    enum _MERIDIAN	Meridian;
} YYSTYPE;
#endif /* YYSTYPE_DEFINED */
#line 115 "getdate.c"
#define tAGO 257
#define tID 258
#define tDST 259
#define tDAY 260
#define tDAYZONE 261
#define tMINUTE_UNIT 262
#define tMONTH 263
#define tMONTH_UNIT 264
#define tSEC_UNIT 265
#define tSNUMBER 266
#define tUNUMBER 267
#define tZONE 268
#define tMERIDIAN 269
#define YYERRCODE 256
const short yylhs[] =
	{                                        -1,
    0,    0,    2,    2,    2,    2,    2,    2,    3,    3,
    3,    3,    3,    4,    4,    4,    6,    6,    6,    5,
    5,    5,    5,    5,    5,    5,    5,    7,    7,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    8,    1,
    1,
};
const short yylen[] =
	{                                         2,
    0,    2,    1,    1,    1,    1,    1,    1,    2,    4,
    4,    6,    6,    1,    1,    2,    1,    2,    2,    3,
    5,    3,    3,    2,    4,    2,    3,    2,    1,    2,
    2,    1,    2,    2,    1,    2,    2,    1,    1,    0,
    1,
};
const short yydefred[] =
	{                                      1,
    0,    0,   15,   32,    0,   38,   35,    0,    0,    0,
    2,    3,    4,    5,    6,    7,    8,    0,   18,    0,
   31,   36,   33,   19,   30,    0,   37,   34,    0,    9,
    0,    0,   16,   28,    0,   23,   27,   22,    0,    0,
   25,   11,   41,    0,   10,    0,    0,   21,   13,   12,
};
const short yydgoto[] =
	{                                       1,
   45,   11,   12,   13,   14,   15,   16,   17,   18,
};
const short yysindex[] =
	{                                      0,
 -199,  -38,    0,    0, -254,    0,    0, -260,  -47, -245,
    0,    0,    0,    0,    0,    0,    0, -242,    0,  -28,
    0,    0,    0,    0,    0, -259,    0,    0, -249,    0,
 -247, -246,    0,    0, -244,    0,    0,    0,  -55,  -29,
    0,    0,    0, -243,    0, -241, -257,    0,    0,    0,};
const short yyrindex[] =
	{                                      0,
    0,    1,    0,    0,    0,    0,    0,    0,   60,   10,
    0,    0,    0,    0,    0,    0,    0,   19,    0,   28,
    0,    0,    0,    0,    0,   55,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   46,   37,
    0,    0,    0,    0,    0,    0,   46,    0,    0,    0,};
const short yygindex[] =
	{                                      0,
  -25,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 328
const short yytable[] =
	{                                      32,
   17,   21,   44,   22,   23,   19,   36,   37,   49,   14,
   31,   43,   20,   33,   34,   35,   38,   46,   29,   39,
   40,   50,   41,   47,    0,   48,    0,   24,    0,    0,
    0,    0,    0,    0,    0,    0,   20,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,    0,    0,    0,
    0,    0,    0,    0,   26,    0,    0,    0,    0,   39,
    2,    3,    4,    5,    6,    7,    8,    9,   10,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   42,    0,   24,   43,   25,   26,   27,   28,   29,    0,
    0,   30,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   40,   40,   40,   40,   40,
   40,    0,   40,   40,   26,   26,   26,   26,   26,   26,
   39,    0,   26,    0,    0,    0,   39,   39,
};
const short yycheck[] =
	{                                      47,
    0,  262,   58,  264,  265,   44,  266,  267,  266,    0,
   58,  269,  267,  259,  257,   44,  266,   47,    0,  267,
  267,   47,  267,  267,   -1,  267,   -1,    0,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,    0,
  260,  261,  262,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  266,   -1,  260,  269,  262,  263,  264,  265,  266,   -1,
   -1,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  260,  261,  262,  263,  264,
  265,   -1,  267,  268,  260,  261,  262,  263,  264,  265,
  261,   -1,  268,   -1,   -1,   -1,  267,  268,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#if YYDEBUG
const char * const yyname[] =
	{
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"','",0,0,"'/'",0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tAGO","tID","tDST",
"tDAY","tDAYZONE","tMINUTE_UNIT","tMONTH","tMONTH_UNIT","tSEC_UNIT","tSNUMBER",
"tUNUMBER","tZONE","tMERIDIAN",
};
const char * const yyrule[] =
	{"$accept : spec",
"spec :",
"spec : spec item",
"item : time",
"item : zone",
"item : date",
"item : day",
"item : rel",
"item : number",
"time : tUNUMBER tMERIDIAN",
"time : tUNUMBER ':' tUNUMBER o_merid",
"time : tUNUMBER ':' tUNUMBER tSNUMBER",
"time : tUNUMBER ':' tUNUMBER ':' tUNUMBER o_merid",
"time : tUNUMBER ':' tUNUMBER ':' tUNUMBER tSNUMBER",
"zone : tZONE",
"zone : tDAYZONE",
"zone : tZONE tDST",
"day : tDAY",
"day : tDAY ','",
"day : tUNUMBER tDAY",
"date : tUNUMBER '/' tUNUMBER",
"date : tUNUMBER '/' tUNUMBER '/' tUNUMBER",
"date : tUNUMBER tSNUMBER tSNUMBER",
"date : tUNUMBER tMONTH tSNUMBER",
"date : tMONTH tUNUMBER",
"date : tMONTH tUNUMBER ',' tUNUMBER",
"date : tUNUMBER tMONTH",
"date : tUNUMBER tMONTH tUNUMBER",
"rel : relunit tAGO",
"rel : relunit",
"relunit : tUNUMBER tMINUTE_UNIT",
"relunit : tSNUMBER tMINUTE_UNIT",
"relunit : tMINUTE_UNIT",
"relunit : tSNUMBER tSEC_UNIT",
"relunit : tUNUMBER tSEC_UNIT",
"relunit : tSEC_UNIT",
"relunit : tSNUMBER tMONTH_UNIT",
"relunit : tUNUMBER tMONTH_UNIT",
"relunit : tMONTH_UNIT",
"number : tUNUMBER",
"o_merid :",
"o_merid : tMERIDIAN",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
/* LINTUSED */
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
unsigned int yystacksize;
int yyparse(void);
#line 316 "getdate.y"

/* Month and day table. */
static TABLE const MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL }
};

/* Time units table. */
static TABLE const UnitsTable[] = {
    { "year",		tMONTH_UNIT,	12 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tMINUTE_UNIT,	14 * 24 * 60 },
    { "week",		tMINUTE_UNIT,	7 * 24 * 60 },
    { "day",		tMINUTE_UNIT,	1 * 24 * 60 },
    { "hour",		tMINUTE_UNIT,	60 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL }
};

/* Assorted relative-time words. */
static TABLE const OtherTable[] = {
    { "tomorrow",	tMINUTE_UNIT,	1 * 24 * 60 },
    { "yesterday",	tMINUTE_UNIT,	-1 * 24 * 60 },
    { "today",		tMINUTE_UNIT,	0 },
    { "now",		tMINUTE_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tUNUMBER,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "third",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL }
};

/* The timezone table. */
/* Some of these are commented out because a time_t can't store a float. */
static TABLE const TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR( 0) },
    { "wet",	tZONE,     HOUR( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR(3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR(3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR(3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR(10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR(10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR(10) },	/* Central Alaska */
    { "ahst",	tZONE,     HOUR(10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR(11) },	/* Nome */
    { "idlw",	tZONE,     HOUR(12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR(1) },	/* Central European */
    { "met",	tZONE,     -HOUR(1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR(1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR(1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR(1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR(1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR(1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR(1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR(2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR(3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR(3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR(4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR(5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR(5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR(6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Stanard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR(6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR(7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR(7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR(7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR(7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR(8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR(9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR(9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR(9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR(10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR(10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR(10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR(12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR(12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR(12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR(12) },	/* International Date Line East */
    {  NULL  }
};

/* Military timezone table. */
static TABLE const MilitaryTable[] = {
    { "a",	tZONE,	HOUR(  1) },
    { "b",	tZONE,	HOUR(  2) },
    { "c",	tZONE,	HOUR(  3) },
    { "d",	tZONE,	HOUR(  4) },
    { "e",	tZONE,	HOUR(  5) },
    { "f",	tZONE,	HOUR(  6) },
    { "g",	tZONE,	HOUR(  7) },
    { "h",	tZONE,	HOUR(  8) },
    { "i",	tZONE,	HOUR(  9) },
    { "k",	tZONE,	HOUR( 10) },
    { "l",	tZONE,	HOUR( 11) },
    { "m",	tZONE,	HOUR( 12) },
    { "n",	tZONE,	HOUR(- 1) },
    { "o",	tZONE,	HOUR(- 2) },
    { "p",	tZONE,	HOUR(- 3) },
    { "q",	tZONE,	HOUR(- 4) },
    { "r",	tZONE,	HOUR(- 5) },
    { "s",	tZONE,	HOUR(- 6) },
    { "t",	tZONE,	HOUR(- 7) },
    { "u",	tZONE,	HOUR(- 8) },
    { "v",	tZONE,	HOUR(- 9) },
    { "w",	tZONE,	HOUR(-10) },
    { "x",	tZONE,	HOUR(-11) },
    { "y",	tZONE,	HOUR(-12) },
    { "z",	tZONE,	HOUR(  0) },
    { NULL }
};




/* ARGSUSED */
void
yyerror(const char *s)
{
    return;
}


static time_t
ToSeconds(time_t Hours, time_t Minutes, time_t Seconds, MERIDIAN Meridian)
{
    if (Minutes < 0 || Minutes > 59 || Seconds < 0 || Seconds > 59)
	return -1;
    switch (Meridian) {
    case MER24:
	if (Hours < 0 || Hours > 23)
	    return -1;
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERam:
	if (Hours < 1 || Hours > 12)
	    return -1;
	if (Hours == 12)
	    Hours = 0;
	return (Hours * 60L + Minutes) * 60L + Seconds;
    case MERpm:
	if (Hours < 1 || Hours > 12)
	    return -1;
	if (Hours == 12)
	    Hours = 0;
	return ((Hours + 12) * 60L + Minutes) * 60L + Seconds;
    default:
	abort ();
    }
    /* NOTREACHED */
}


/* Year is either
   * A negative number, which means to use its absolute value (why?)
   * A number from 0 to 99, which means a year from 1900 to 1999, or
   * The actual year (>=100).  */
static time_t
Convert(time_t Month, time_t Day, time_t Year, time_t Hours, time_t Minutes,
    time_t Seconds, MERIDIAN Meridian, DSTMODE DSTmode)
{
    static int DaysInMonth[12] = {
	31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    struct tm	tm;
    time_t	tod;
    time_t	Julian;
    int		i;

    if (Year < 0)
	Year = -Year;
    if (Year < 69)
	Year += 2000;
    else if (Year < 100) {
	Year += 1900;
	if (Year < EPOCH)
		Year += 100;
    }
    DaysInMonth[1] = Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0)
		    ? 29 : 28;
    /* 32-bit time_t cannot represent years past 2038 */
    if (Year < EPOCH || (sizeof(time_t) == sizeof(int) && Year > 2038)
     || Month < 1 || Month > 12
     /* Lint fluff:  "conversion from long may lose accuracy" */
     || Day < 1 || Day > DaysInMonth[(int)--Month])
	return -1;

    for (Julian = Day - 1, i = 0; i < Month; i++)
	Julian += DaysInMonth[i];
    for (i = EPOCH; i < Year; i++)
	Julian += 365 + (i % 4 == 0);
    Julian *= SECSPERDAY;
    Julian += yyTimezone * 60L;
    if ((tod = ToSeconds(Hours, Minutes, Seconds, Meridian)) < 0)
	return -1;
    Julian += tod;
    if (DSTmode == DSTon
     || (DSTmode == DSTmaybe && localtime_r(&Julian, &tm) && tm.tm_isdst))
	Julian -= 60 * 60;
    return Julian;
}


static time_t
DSTcorrect(time_t Start, time_t Future)
{
    struct tm	start_tm;
    struct tm	future_tm;
    time_t	StartDay;
    time_t	FutureDay;

    if (!localtime_r(&Start, &start_tm) || !localtime_r(&Future, &future_tm))
	return -1;

    StartDay = (start_tm.tm_hour + 1) % 24;
    FutureDay = (future_tm.tm_hour + 1) % 24;
    return (Future - Start) + (StartDay - FutureDay) * 60L * 60L;
}


static time_t
RelativeDate(time_t Start, time_t DayOrdinal, time_t DayNumber)
{
    struct tm	tm;
    time_t	now;

    now = Start;
    if (!localtime_r(&now, &tm))
	return -1;
    now += SECSPERDAY * ((DayNumber - tm.tm_wday + 7) % 7);
    now += 7 * SECSPERDAY * (DayOrdinal <= 0 ? DayOrdinal : DayOrdinal - 1);
    return DSTcorrect(Start, now);
}


static time_t
RelativeMonth(time_t Start, time_t RelMonth)
{
    struct tm	tm;
    time_t	Month;
    time_t	Year;

    if (RelMonth == 0)
	return 0;
    if (!localtime_r(&Start, &tm))
	return -1;
    Month = 12 * (tm.tm_year + 1900) + tm.tm_mon + RelMonth;
    Year = Month / 12;
    Month = Month % 12 + 1;
    return DSTcorrect(Start,
	    Convert(Month, (time_t)tm.tm_mday, Year,
		(time_t)tm.tm_hour, (time_t)tm.tm_min, (time_t)tm.tm_sec,
		MER24, DSTmaybe));
}


static int
LookupWord(char *buff)
{
    char		*p;
    char		*q;
    const TABLE		*tp;
    int			i;
    int			abbrev;

    /* Make it lowercase. */
    for (p = buff; *p; p++)
	if (isupper((unsigned char)*p))
	    *p = tolower((unsigned char)*p);

    if (strcmp(buff, "am") == 0 || strcmp(buff, "a.m.") == 0) {
	yylval.Meridian = MERam;
	return tMERIDIAN;
    }
    if (strcmp(buff, "pm") == 0 || strcmp(buff, "p.m.") == 0) {
	yylval.Meridian = MERpm;
	return tMERIDIAN;
    }

    /* See if we have an abbreviation for a month. */
    if (strlen(buff) == 3)
	abbrev = 1;
    else if (strlen(buff) == 4 && buff[3] == '.') {
	abbrev = 1;
	buff[3] = '\0';
    }
    else
	abbrev = 0;

    for (tp = MonthDayTable; tp->name; tp++) {
	if (abbrev) {
	    if (strncmp(buff, tp->name, 3) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }
	}
	else if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = TimezoneTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}

    if (strcmp(buff, "dst") == 0) 
	return tDST;

    for (tp = UnitsTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}

    /* Strip off any plural and try the units table again. */
    i = strlen(buff) - 1;
    if (buff[i] == 's') {
	buff[i] = '\0';
	for (tp = UnitsTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }
	buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

    for (tp = OtherTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval.Number = tp->value;
	    return tp->type;
	}

    /* Military timezones. */
    if (buff[1] == '\0' && isalpha((unsigned char)*buff)) {
	for (tp = MilitaryTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }
    }

    /* Drop out any periods and try the timezone table again. */
    for (i = 0, p = q = buff; *q; q++)
	if (*q != '.')
	    *p++ = *q;
	else
	    i++;
    *p = '\0';
    if (i)
	for (tp = TimezoneTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval.Number = tp->value;
		return tp->type;
	    }

    return tID;
}


static int
yylex(void)
{
    char		c;
    char		*p;
    char		buff[20];
    int			Count;
    int			sign;

    for ( ; ; ) {
	while (isspace((unsigned char)*yyInput))
	    yyInput++;

	if (isdigit((unsigned char)(c = *yyInput)) || c == '-' || c == '+') {
	    if (c == '-' || c == '+') {
		sign = c == '-' ? -1 : 1;
		if (!isdigit((unsigned char)*++yyInput))
		    /* skip the '-' sign */
		    continue;
	    }
	    else
		sign = 0;
	    for (yylval.Number = 0; isdigit((unsigned char)(c = *yyInput++)); )
		yylval.Number = 10 * yylval.Number + c - '0';
	    yyInput--;
	    if (sign < 0)
		yylval.Number = -yylval.Number;
	    return sign ? tSNUMBER : tUNUMBER;
	}
	if (isalpha((unsigned char)c)) {
	    for (p = buff; isalpha((unsigned char)(c = *yyInput++)) || c == '.'; )
		if (p < &buff[sizeof buff - 1])
		    *p++ = c;
	    *p = '\0';
	    yyInput--;
	    return LookupWord(buff);
	}
	if (c != '(')
	    return *yyInput++;
	Count = 0;
	do {
	    c = *yyInput++;
	    if (c == '\0')
		return c;
	    if (c == '(')
		Count++;
	    else if (c == ')')
		Count--;
	} while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

/* Yield A - B, measured in seconds.  */
static long
difftm(struct tm *a, struct tm *b)
{
  int ay = a->tm_year + (TM_YEAR_ORIGIN - 1);
  int by = b->tm_year + (TM_YEAR_ORIGIN - 1);
  int days = (
	      /* difference in day of year */
	      a->tm_yday - b->tm_yday
	      /* + intervening leap days */
	      +  ((ay >> 2) - (by >> 2))
	      -  (ay/100 - by/100)
	      +  ((ay/100 >> 2) - (by/100 >> 2))
	      /* + difference in years * 365 */
	      +  (long)(ay-by) * 365
	      );
  return (60*(60*(24*days + (a->tm_hour - b->tm_hour))
	      + (a->tm_min - b->tm_min))
	  + (a->tm_sec - b->tm_sec));
}

time_t
get_date(char *p)
{
    struct tm		tm, gmt;
    time_t		Start;
    time_t		tod;
    time_t		now;
    time_t		tz;

    yyInput = p;
    (void)time (&now);

    if (gmtime_r (&now, &gmt) == NULL)
	return -1;

    if (localtime_r (&now, &tm) == NULL)
	return -1;

    tz = difftm (&gmt, &tm) / 60;
    if (tm.tm_isdst)
	tz += 60;

    yyYear = tm.tm_year + 1900;
    yyMonth = tm.tm_mon + 1;
    yyDay = tm.tm_mday;
    yyTimezone = tz;
    yyDSTmode = DSTmaybe;
    yyHour = 0;
    yyMinutes = 0;
    yySeconds = 0;
    yyMeridian = MER24;
    yyRelSeconds = 0;
    yyRelMonth = 0;
    yyHaveDate = 0;
    yyHaveDay = 0;
    yyHaveRel = 0;
    yyHaveTime = 0;
    yyHaveZone = 0;

    if (yyparse()
     || yyHaveTime > 1 || yyHaveZone > 1 || yyHaveDate > 1 || yyHaveDay > 1)
	return -1;

    if (yyHaveDate || yyHaveTime || yyHaveDay) {
	Start = Convert(yyMonth, yyDay, yyYear, yyHour, yyMinutes, yySeconds,
		    yyMeridian, yyDSTmode);
	if (Start < 0)
	    return -1;
    }
    else {
	Start = now;
	if (!yyHaveRel)
	    Start -= ((tm.tm_hour * 60L + tm.tm_min) * 60L) + tm.tm_sec;
    }

    Start += yyRelSeconds;
    Start += RelativeMonth(Start, yyRelMonth);

    if (yyHaveDay && !yyHaveDate) {
	tod = RelativeDate(Start, yyDayOrdinal, yyDayNumber);
	Start += tod;
    }

    /* Have to do *something* with a legitimate -1 so it's distinguishable
     * from the error return value.  (Alternately could set errno on error.) */
    return Start == -1 ? 0 : Start;
}


#ifdef TEST

/* ARGSUSED */
int
main(int argc, char *argv[])
{
    char	buff[128];
    time_t	d;

    (void)printf("Enter date, or blank line to exit.\n\t> ");
    (void)fflush(stdout);
    while (fgets(buff, sizeof(buff), stdin) && buff[0]) {
	d = get_date(buff);
	if (d == -1)
	    (void)printf("Bad format - couldn't convert.\n");
	else
	    (void)printf("%s", ctime(&d));
	(void)printf("\t> ");
	(void)fflush(stdout);
    }
    exit(0);
    /* NOTREACHED */
}
#endif	/* TEST */
#line 933 "getdate.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    unsigned int newsize;
    long sslen;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
#ifdef SIZE_MAX
#define YY_SIZE_MAX SIZE_MAX
#else
#define YY_SIZE_MAX 0xffffffffU
#endif
    if (YY_SIZE_MAX / newsize < sizeof *newss)
        goto bail;
    sslen = yyssp - yyss;
    newss = yyss ? realloc(yyss, newsize * sizeof *newss) :
      malloc(newsize * sizeof *newss); /* overflow check above */
    if (newss == NULL)
        goto bail;
    yyss = newss;
    yyssp = newss + sslen;
    newvs = yyvs ? realloc(yyvs, newsize * sizeof *newvs) :
      malloc(newsize * sizeof *newvs); /* overflow check above */
    if (newvs == NULL)
        goto bail;
    yyvs = newvs;
    yyvsp = newvs + sslen;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
bail:
    free(yyss);
    free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return -1;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif /* YYDEBUG */

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
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
#if defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(__GNUC__)
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
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
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
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
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
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 115 "getdate.y"
{
	    yyHaveTime++;
	}
break;
case 4:
#line 118 "getdate.y"
{
	    yyHaveZone++;
	}
break;
case 5:
#line 121 "getdate.y"
{
	    yyHaveDate++;
	}
break;
case 6:
#line 124 "getdate.y"
{
	    yyHaveDay++;
	}
break;
case 7:
#line 127 "getdate.y"
{
	    yyHaveRel++;
	}
break;
case 9:
#line 133 "getdate.y"
{
	    yyHour = yyvsp[-1].Number;
	    yyMinutes = 0;
	    yySeconds = 0;
	    yyMeridian = yyvsp[0].Meridian;
	}
break;
case 10:
#line 139 "getdate.y"
{
	    yyHour = yyvsp[-3].Number;
	    yyMinutes = yyvsp[-1].Number;
	    yySeconds = 0;
	    yyMeridian = yyvsp[0].Meridian;
	}
break;
case 11:
#line 145 "getdate.y"
{
	    yyHour = yyvsp[-3].Number;
	    yyMinutes = yyvsp[-1].Number;
	    yyMeridian = MER24;
	    yyDSTmode = DSToff;
	    yyTimezone = - (yyvsp[0].Number % 100 + (yyvsp[0].Number / 100) * 60);
	}
break;
case 12:
#line 152 "getdate.y"
{
	    yyHour = yyvsp[-5].Number;
	    yyMinutes = yyvsp[-3].Number;
	    yySeconds = yyvsp[-1].Number;
	    yyMeridian = yyvsp[0].Meridian;
	}
break;
case 13:
#line 158 "getdate.y"
{
	    yyHour = yyvsp[-5].Number;
	    yyMinutes = yyvsp[-3].Number;
	    yySeconds = yyvsp[-1].Number;
	    yyMeridian = MER24;
	    yyDSTmode = DSToff;
	    yyTimezone = - (yyvsp[0].Number % 100 + (yyvsp[0].Number / 100) * 60);
	}
break;
case 14:
#line 168 "getdate.y"
{
	    yyTimezone = yyvsp[0].Number;
	    yyDSTmode = DSToff;
	}
break;
case 15:
#line 172 "getdate.y"
{
	    yyTimezone = yyvsp[0].Number;
	    yyDSTmode = DSTon;
	}
break;
case 16:
#line 177 "getdate.y"
{
	    yyTimezone = yyvsp[-1].Number;
	    yyDSTmode = DSTon;
	}
break;
case 17:
#line 183 "getdate.y"
{
	    yyDayOrdinal = 1;
	    yyDayNumber = yyvsp[0].Number;
	}
break;
case 18:
#line 187 "getdate.y"
{
	    yyDayOrdinal = 1;
	    yyDayNumber = yyvsp[-1].Number;
	}
break;
case 19:
#line 191 "getdate.y"
{
	    yyDayOrdinal = yyvsp[-1].Number;
	    yyDayNumber = yyvsp[0].Number;
	}
break;
case 20:
#line 197 "getdate.y"
{
	    yyMonth = yyvsp[-2].Number;
	    yyDay = yyvsp[0].Number;
	}
break;
case 21:
#line 201 "getdate.y"
{
	    if (yyvsp[-4].Number >= 100) {
		yyYear = yyvsp[-4].Number;
		yyMonth = yyvsp[-2].Number;
		yyDay = yyvsp[0].Number;
	    } else {
		yyMonth = yyvsp[-4].Number;
		yyDay = yyvsp[-2].Number;
		yyYear = yyvsp[0].Number;
	    }
	}
break;
case 22:
#line 212 "getdate.y"
{
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    yyYear = yyvsp[-2].Number;
	    yyMonth = -yyvsp[-1].Number;
	    yyDay = -yyvsp[0].Number;
	}
break;
case 23:
#line 218 "getdate.y"
{
	    /* e.g. 17-JUN-1992.  */
	    yyDay = yyvsp[-2].Number;
	    yyMonth = yyvsp[-1].Number;
	    yyYear = -yyvsp[0].Number;
	}
break;
case 24:
#line 224 "getdate.y"
{
	    yyMonth = yyvsp[-1].Number;
	    yyDay = yyvsp[0].Number;
	}
break;
case 25:
#line 228 "getdate.y"
{
	    yyMonth = yyvsp[-3].Number;
	    yyDay = yyvsp[-2].Number;
	    yyYear = yyvsp[0].Number;
	}
break;
case 26:
#line 233 "getdate.y"
{
	    yyMonth = yyvsp[0].Number;
	    yyDay = yyvsp[-1].Number;
	}
break;
case 27:
#line 237 "getdate.y"
{
	    yyMonth = yyvsp[-1].Number;
	    yyDay = yyvsp[-2].Number;
	    yyYear = yyvsp[0].Number;
	}
break;
case 28:
#line 244 "getdate.y"
{
	    yyRelSeconds = -yyRelSeconds;
	    yyRelMonth = -yyRelMonth;
	}
break;
case 30:
#line 251 "getdate.y"
{
	    yyRelSeconds += yyvsp[-1].Number * yyvsp[0].Number * 60L;
	}
break;
case 31:
#line 254 "getdate.y"
{
	    yyRelSeconds += yyvsp[-1].Number * yyvsp[0].Number * 60L;
	}
break;
case 32:
#line 257 "getdate.y"
{
	    yyRelSeconds += yyvsp[0].Number * 60L;
	}
break;
case 33:
#line 260 "getdate.y"
{
	    yyRelSeconds += yyvsp[-1].Number;
	}
break;
case 34:
#line 263 "getdate.y"
{
	    yyRelSeconds += yyvsp[-1].Number;
	}
break;
case 35:
#line 266 "getdate.y"
{
	    yyRelSeconds++;
	}
break;
case 36:
#line 269 "getdate.y"
{
	    yyRelMonth += yyvsp[-1].Number * yyvsp[0].Number;
	}
break;
case 37:
#line 272 "getdate.y"
{
	    yyRelMonth += yyvsp[-1].Number * yyvsp[0].Number;
	}
break;
case 38:
#line 275 "getdate.y"
{
	    yyRelMonth += yyvsp[0].Number;
	}
break;
case 39:
#line 280 "getdate.y"
{
	    if (yyHaveTime && yyHaveDate && !yyHaveRel)
		yyYear = yyvsp[0].Number;
	    else {
		if(yyvsp[0].Number>10000) {
		    yyHaveDate++;
		    yyDay= (yyvsp[0].Number)%100;
		    yyMonth= (yyvsp[0].Number/100)%100;
		    yyYear = yyvsp[0].Number/10000;
		}
		else {
		    yyHaveTime++;
		    if (yyvsp[0].Number < 100) {
			yyHour = yyvsp[0].Number;
			yyMinutes = 0;
		    }
		    else {
		    	yyHour = yyvsp[0].Number / 100;
		    	yyMinutes = yyvsp[0].Number % 100;
		    }
		    yySeconds = 0;
		    yyMeridian = MER24;
	        }
	    }
	}
break;
case 40:
#line 307 "getdate.y"
{
	    yyval.Meridian = MER24;
	}
break;
case 41:
#line 310 "getdate.y"
{
	    yyval.Meridian = yyvsp[0].Meridian;
	}
break;
#line 1413 "getdate.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
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
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
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
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    free(yyss);
    free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (1);
yyaccept:
    free(yyss);
    free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (0);
}
