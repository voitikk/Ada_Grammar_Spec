#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "ada.y"
	/* Alex Voitik          */
	/* ada.y                */
	/* Last Edit: 10/30/2016 */

#include <stdio.h>
#include "include_list.h"
	extern int lineno;
	int currReg;
	

#line 39 "ada.y"
typedef union {
    	int integer;
    	char *var;
    	struct idnode *listptr;
		struct semInfo *semNode;
		struct writeNode *writeList;
} YYSTYPE;
#line 42 "y.tab.c"
#define IS 257
#define BEG 258
#define END 259
#define PROCEDURE 260
#define ID 261
#define NUMBER 262
#define TYPE 263
#define ARRAY 264
#define RAISE 265
#define OTHERS 266
#define RECORD 267
#define IN 268
#define OUT 269
#define RANGE 270
#define CONSTANT 271
#define ASSIGN 272
#define EXCEPTION 273
#define NULLWORD 274
#define LOOP 275
#define IF 276
#define THEN 277
#define ELSEIF 278
#define ELSE 279
#define EXIT 280
#define WHEN 281
#define AND 282
#define OR 283
#define EQ 284
#define NEQ 285
#define LT 286
#define GT 287
#define GTE 288
#define LTE 289
#define TICK 290
#define NOT 291
#define EXP 292
#define ARROW 293
#define OF 294
#define DOTDOT 295
#define ENDIF 296
#define ENDREC 297
#define ENDLOOP 298
#define EXITWHEN 299
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,   23,   19,   20,   27,   28,   25,   26,   26,    9,
   29,   29,   30,   30,    7,    6,    6,   31,   31,   31,
   31,    5,   21,   33,   33,   32,   32,   34,   34,   34,
   34,   34,   34,   35,    8,   36,   41,   41,   38,   37,
   39,   40,   42,   22,   22,   43,   43,   43,   43,   43,
   43,   44,   46,   49,   49,   49,   47,   50,   50,   50,
   48,   45,   18,   18,   14,   13,   13,   12,   12,   15,
   15,   17,   17,   11,   11,   16,   16,   16,   16,   10,
   10,   10,    4,    4,    3,    3,    3,    3,    3,    3,
    1,    1,    2,    2,   24,   24,   51,   51,   51,   52,
   52,   52,
};
short yylen[] = {                                         2,
    1,    0,    9,    2,    0,    0,   10,    4,    1,    2,
    1,    0,    6,    4,    1,    3,    1,    1,    1,    2,
    0,    1,    2,    2,    0,    3,    0,    1,    1,    1,
    1,    1,    1,   11,    1,    6,    3,    0,    3,    7,
    5,    3,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    3,    4,    2,    3,    0,    6,    5,    2,    0,
    2,    1,    2,    1,    3,    3,    1,    1,    3,    1,
    3,    1,    3,    1,    3,    1,    3,    2,    2,    1,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    0,    5,    4,    0,    2,
    3,    0,
};
short yydefred[] = {                                      0,
    0,    0,    1,    0,    4,    0,   15,    0,    0,    0,
    0,    0,    0,   28,   29,   30,   31,   32,   33,    0,
    0,    0,    2,    0,    0,    0,    0,   23,    0,    0,
    0,   42,   39,   22,   16,    0,   10,    0,   24,    5,
   26,    0,    0,    0,    0,    0,   46,    0,    0,    0,
   62,    0,    0,   47,   48,   49,   50,   51,    0,    0,
   11,    0,    0,    0,    0,    0,   35,    0,   43,   41,
   61,    0,   80,    0,    0,    0,   81,    0,    0,    0,
    0,   74,    0,    0,    0,   63,    0,    0,    0,    0,
    8,    0,    0,    0,    0,   36,    0,    0,    0,    0,
   78,    0,   79,    0,   93,   94,    0,    0,   83,   84,
    0,   85,   86,   87,   89,   90,   88,    0,   92,   91,
    0,    0,    0,    0,    0,   95,    0,   44,    0,   19,
    0,    6,    0,   37,   40,   54,    0,   53,   82,   77,
   75,    0,    0,    0,    0,    0,   65,    0,    0,    0,
    0,    3,   20,    0,    0,    0,   55,    0,    0,    0,
   66,  100,    0,    0,    0,    0,    0,    0,    0,   59,
   57,   98,  101,    0,   13,    0,    0,    0,   97,    0,
   34,    0,    7,   58,
};
short yydgoto[] = {                                       2,
  121,  107,  118,  111,   33,    9,   77,   68,   25,   78,
   79,  123,  124,   86,   81,   82,   83,   51,    3,    4,
   11,   52,   36,   88,   26,   27,   62,  155,   60,   61,
  131,   12,   28,   13,   14,   15,   16,   17,   18,   19,
   66,   70,   53,   54,   55,   56,   57,   58,  100,  160,
  126,  151,
};
short yysindex[] = {                                   -237,
 -226,    0,    0, -219,    0, -227,    0, -209,    2,   23,
 -185, -181,   26,    0,    0,    0,    0,    0,    0, -152,
 -187, -170,    0, -153,   79, -181, -136,    0, -227, -166,
 -148,    0,    0,    0,    0, -158,    0, -170,    0,    0,
    0,   87, -170, -134, -132, -129,    0, -158,  -40,  -39,
    0, -140,   77,    0,    0,    0,    0,    0,   80,   98,
    0, -227, -134,   82,   83, -154,    0, -151,    0,    0,
    0, -248,    0,  -32,  -40,  -32,    0, -143,   17, -190,
 -130,    0,   13,  -40,  -40,    0, -131, -107, -158, -224,
    0,  -97, -133, -170, -170,    0, -134,  104,  -40, -128,
    0,  -21,    0,  -32,    0,    0,  -40, -158,    0,    0,
  -40,    0,    0,    0,    0,    0,    0,  -40,    0,    0,
  -40, -183,  -42,  123, -115,    0,  106,    0, -103,    0,
 -170,    0, -134,    0,    0,    0,  -55,    0,    0,    0,
    0, -156, -130,   13,   17,  -40,    0, -108, -126,  -93,
 -124,    0,    0,  113, -158,  132,    0,  -40, -158, -122,
    0,    0, -158, -108, -158, -170, -140, -119, -157,    0,
    0,    0,    0, -131,    0,  -83, -170, -158,    0,  119,
    0, -156,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0, -149,    0,    0,    0,  121,
    0,  -78,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -76,  -78,    0,    0, -149,    0,
    0,    0,    0,    0,    0,    0,    0,  141,    0,    0,
    0,    0, -114,    0,    0,    0,    0,    0,    0,  125,
    0,  -74,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -149,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -111,    0,    0,    0,    0,    0,  -30,  -17,    0,
  -38,    0,    9,    0,    0,    0,  -73,    0, -184,  -72,
    0,    0,    0,    0, -114,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  129,  149,    0, -102,    0,    0,    0,  -69,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -100,  -34,   22,   -4,    0,    0, -102,    0,    0,
    0,    0,    0,  152,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -102,    0,    0,  -74,    0,    0,    0,
    0,    0,    0,  -73,    0,    0,    0,    0,    0,    0,
    0, -100,    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,    0, -112,   11,   40,  -20,    0,    6,
   73,  -27,   51,    0,   89,   91,   84,    0,    0,    0,
  139,  -18,    0,   37,    0,    0,    0,    0,    0,   41,
    0,  179,  183,    0,    0,    0,    0,  -25,    0,    0,
  115,    0,    0,    0,    0,    0,    0,    0,    0,   29,
   38, -117,
};
#define YYTABLESIZE 311
short yytable[] = {                                      75,
   85,  146,   68,  157,   76,   68,   69,   75,  150,   69,
   76,   76,   76,   76,   76,  150,   76,   65,  154,  139,
   68,   80,    1,   72,   69,   72,   72,   72,   76,   72,
  162,   98,   35,    7,    5,    8,   73,    6,   73,   73,
   73,   72,   93,  129,  130,   10,  173,  102,   59,   70,
   99,   20,   70,   64,   73,  120,  122,  119,  105,   21,
   34,   10,   71,  106,  181,   71,   22,   70,   10,   65,
  128,  137,   23,    7,   45,   50,  135,   10,   24,  101,
   71,  103,   10,   31,   29,   32,  108,   50,   45,  142,
    7,  109,  110,   45,   45,   45,   45,   42,  109,  110,
   43,   10,    7,   44,   30,   64,   46,   37,   27,  140,
   27,   45,  156,   45,   45,   47,   48,   49,   38,  178,
   40,  158,  159,   45,  109,  110,   63,   67,   50,   69,
  169,   71,   87,   34,   10,   89,  167,   90,   91,   94,
  170,   95,   96,   97,  172,  148,  174,   50,  104,  125,
  149,  127,  148,  112,  113,  114,  115,  116,  117,  182,
  132,  133,  136,  147,  152,  153,  163,  164,  165,  138,
   34,  166,  168,  171,  177,  180,   59,  183,   17,   25,
    9,   12,   38,   64,   96,   99,   56,   52,   21,   67,
  102,   18,   14,  145,   50,   60,  161,  141,   50,  143,
   92,  144,   50,  176,   50,   10,  175,   41,   39,  134,
  184,  179,    0,    0,    0,    0,   34,   50,    0,    0,
    7,   73,    0,    0,    0,    0,  109,  110,    7,   73,
    0,    0,   84,    0,    0,    0,    0,    0,   68,  109,
  110,    0,   69,   68,   68,    0,   76,   69,   69,    0,
   74,   76,   76,   76,   76,   76,   76,   76,   76,   72,
  109,  110,    0,    0,   72,   72,   72,   72,   72,   72,
   72,   72,   73,    0,    0,    0,    0,   73,   73,   73,
   73,   73,   73,   73,   73,   70,    0,    0,    0,    0,
   70,   70,   70,   70,   70,   70,   70,   70,   71,    0,
    0,    0,    0,   71,   71,   71,   71,   71,   71,   71,
   71,
};
short yycheck[] = {                                      40,
   40,   44,   41,   59,   45,   44,   41,   40,  124,   44,
   41,   42,   43,   44,   45,  124,   47,   43,  131,   41,
   59,   49,  260,   41,   59,   43,   44,   45,   59,   48,
  148,  280,   22,  261,  261,  263,   41,  257,   43,   44,
   45,   59,   63,  268,  269,    6,  164,   75,   38,   41,
  299,  261,   44,   43,   59,   43,   84,   45,   42,   58,
   21,   22,   41,   47,  177,   44,   44,   59,   29,   95,
   89,   99,  258,  261,  259,   36,   97,   38,  260,   74,
   59,   76,   43,  271,   59,  273,  277,   48,  273,  108,
  261,  282,  283,  278,  279,  280,  281,  264,  282,  283,
  267,   62,  261,  270,  257,   95,  265,  261,  258,  104,
  260,  296,  133,  298,  299,  274,  275,  276,   40,  277,
  257,  278,  279,  272,  282,  283,   40,  262,   89,  262,
  158,  261,  273,   94,   95,   59,  155,   58,   41,   58,
  159,   59,  297,  295,  163,  261,  165,  108,  292,  281,
  266,  259,  261,  284,  285,  286,  287,  288,  289,  178,
  258,  295,   59,   41,   59,  269,  293,  261,  293,  298,
  131,   59,   41,  296,  294,  259,  166,   59,   58,  258,
  257,   41,  297,   59,  259,  259,  298,   59,  261,   41,
  293,  261,   41,  121,  155,  296,  146,  107,  159,  111,
   62,  118,  163,  167,  165,  166,  166,   29,   26,   95,
  182,  174,   -1,   -1,   -1,   -1,  177,  178,   -1,   -1,
  261,  262,   -1,   -1,   -1,   -1,  282,  283,  261,  262,
   -1,   -1,  272,   -1,   -1,   -1,   -1,   -1,  277,  282,
  283,   -1,  277,  282,  283,   -1,  277,  282,  283,   -1,
  291,  282,  283,  284,  285,  286,  287,  288,  289,  277,
  282,  283,   -1,   -1,  282,  283,  284,  285,  286,  287,
  288,  289,  277,   -1,   -1,   -1,   -1,  282,  283,  284,
  285,  286,  287,  288,  289,  277,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  277,   -1,
   -1,   -1,   -1,  282,  283,  284,  285,  286,  287,  288,
  289,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 299
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"IS","BEG","END","PROCEDURE","ID","NUMBER","TYPE","ARRAY","RAISE",
"OTHERS","RECORD","IN","OUT","RANGE","CONSTANT","ASSIGN","EXCEPTION","NULLWORD",
"LOOP","IF","THEN","ELSEIF","ELSE","EXIT","WHEN","AND","OR","EQ","NEQ","LT",
"GT","GTE","LTE","TICK","NOT","EXP","ARROW","OF","DOTDOT","ENDIF","ENDREC",
"ENDLOOP","EXITWHEN",
};
char *yyrule[] = {
"$accept : program",
"program : main_body",
"$$1 :",
"main_body : main_spec IS declarative_part BEG $$1 seq_of_stmts except_part END ';'",
"main_spec : PROCEDURE ID",
"$$2 :",
"$$3 :",
"procedure_body : procedure_spec IS $$2 declarative_part BEG $$3 seq_of_stmts except_part END ';'",
"procedure_spec : procedure_head '(' formal_param_part ')'",
"procedure_spec : procedure_head",
"procedure_head : PROCEDURE ID",
"formal_param_part : parameters",
"formal_param_part :",
"parameters : id_list ':' mode type_name ';' parameters",
"parameters : id_list ':' mode type_name",
"identifier : ID",
"id_list : identifier ',' id_list",
"id_list : identifier",
"mode : IN",
"mode : OUT",
"mode : IN OUT",
"mode :",
"type_name : identifier",
"declarative_part : decl_list procedure_decl_list",
"procedure_decl_list : procedure_body procedure_decl_list",
"procedure_decl_list :",
"decl_list : decl ';' decl_list",
"decl_list :",
"decl : array_type",
"decl : record_type",
"decl : name_type",
"decl : variable_decl",
"decl : constant_type",
"decl : exception_type",
"array_type : TYPE ID IS ARRAY '(' constant DOTDOT constant ')' OF type_name",
"constant : NUMBER",
"record_type : TYPE ID IS RECORD component_list ENDREC",
"component_list : variable_decl ';' component_list",
"component_list :",
"variable_decl : id_list ':' type_name",
"name_type : TYPE ID IS RANGE constant DOTDOT constant",
"constant_type : id_list ':' CONSTANT ASSIGN constant_expr",
"exception_type : id_list ':' EXCEPTION",
"constant_expr : NUMBER",
"seq_of_stmts : stmt_type ';' seq_of_stmts",
"seq_of_stmts : stmt_type ';'",
"stmt_type : NULLWORD",
"stmt_type : assignment_stmt",
"stmt_type : procedure_call",
"stmt_type : loop_stmt",
"stmt_type : if_stmt",
"stmt_type : raise_exc",
"assignment_stmt : identifier ASSIGN expression",
"loop_stmt : LOOP seq_of_stmts loop_exit ENDLOOP",
"loop_exit : EXIT ';'",
"loop_exit : EXITWHEN expression ';'",
"loop_exit :",
"if_stmt : IF expression THEN seq_of_stmts if_cont ENDIF",
"if_cont : ELSEIF expression THEN seq_of_stmts if_cont",
"if_cont : ELSE seq_of_stmts",
"if_cont :",
"raise_exc : RAISE ID",
"procedure_call : proc_params",
"proc_params : identifier optional_params",
"proc_params : identifier",
"optional_params : '(' function_params ')'",
"function_params : expression ',' function_params",
"function_params : expression",
"expression : relation",
"expression : expression boolean_op relation",
"relation : simple_expr",
"relation : relation relational_op simple_expr",
"simple_expr : term",
"simple_expr : simple_expr adding_op term",
"term : factor",
"term : term multiplying_op factor",
"factor : primary",
"factor : primary EXP primary",
"factor : NOT primary",
"factor : '-' primary",
"primary : NUMBER",
"primary : identifier",
"primary : '(' expression ')'",
"boolean_op : AND",
"boolean_op : OR",
"relational_op : EQ",
"relational_op : NEQ",
"relational_op : LT",
"relational_op : LTE",
"relational_op : GT",
"relational_op : GTE",
"adding_op : '+'",
"adding_op : '-'",
"multiplying_op : '*'",
"multiplying_op : '/'",
"except_part : EXCEPTION exception_body",
"except_part :",
"exception_body : WHEN choice_sequence ARROW seq_of_stmts exception_body",
"exception_body : WHEN OTHERS ARROW seq_of_stmts",
"exception_body :",
"choice_sequence : ID choice_sequence",
"choice_sequence : '|' ID choice_sequence",
"choice_sequence :",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 945 "ada.y"
#include <stdio.h>
#include <string.h>
FILE *codeFile;
main()
{
	outerContext();
	codeFile = fopen("code.txt", "w");
	create_prologue(codeFile);
	if(codeFile == NULL){
		printf("Error: File could not be opened");
		return;
	}
	yyparse();
	fclose(codeFile);
	integratePatchList();
	
}
#line 438 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

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
        yychar = YYEMPTY;
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
        yychar = YYEMPTY;
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
case 1:
#line 48 "ada.y"
{printf ("\n*****\nDone.\n*****\n");}
break;
case 2:
#line 53 "ada.y"
{

	beg_main = insCtr;	
}
break;
case 3:
#line 60 "ada.y"
{
	printf("\nPopping scope for %s, Printing Tree\n", stack[sCtr-1].name);
	printf("All Code in Code.txt file\n");
	printf("***************************************************************\n");
	printTree(stack[sCtr-1].root);
	if(sCtr > 0){
		int curr_reg = getRegister();
		
		/*main Epilogue*/
		fprintf(codeFile, "%d r%d := contents b, 1\n", getInstruction(), curr_reg);
		fprintf(codeFile, "%d b := contents b, 3\n", getInstruction());
		fprintf(codeFile, "%d pc := r%d\n", getInstruction(), curr_reg);
	}
	pop();
	int firstb = getInstruction();
	fprintf(codeFile, "\n\nPATCH_LIST\n");
    fprintf(codeFile, "**********\n");
	insertPatch(0, firstb);
	insertPatch(1, stack[sCtr].root->data.nextARsize + firstb);
	insertPatch(3, beg_main);
	printList(codeFile);
}
break;
case 4:
#line 85 "ada.y"
{
	push_tree(yyvsp[0].var);
	
}
break;
case 5:
#line 92 "ada.y"
{
	printf("%s declared by %s\n", stack[sCtr-1].name, stack[sCtr-2].name);
}
break;
case 6:
#line 96 "ada.y"
{
	printf("\nBeginnning of %s's Code at line %d\n\n", stack[sCtr-1].name, insCtr);
}
break;
case 7:
#line 101 "ada.y"
{
	printf("\nPopping scope for %s, so print tree\n", stack[sCtr-1].name);
	printf("***************************************************************\n");
	printTree(stack[sCtr-1].root);
	printf("Stack Ctr: %d\n", sCtr);
	pop();
	
	printf("Stack Ctr: %d\n", sCtr);
	if(sCtr > 0){
		int curr_reg = getRegister();
		fprintf(codeFile, "%d r%d := contents b, 1\n", getInstruction(), curr_reg);
		fprintf(codeFile, "%d b := contents b, 3\n", getInstruction());
		fprintf(codeFile, "%d pc := r%d\n", getInstruction(), curr_reg);
	}
}
break;
case 8:
#line 119 "ada.y"
{
	if ( sCtr > 2 ) {
		Insert( yyvsp[-3].var, &( stack[ sCtr-2 ].root ) );
		treeNode *find_inserted = search( yyvsp[-3].var, stack[ sCtr-2 ].root );
		char *str = malloc(sizeof("procedure")+1);
		strcpy(str, "procedure");
        find_inserted->data.kind = str;
		find_inserted->data.ins_ctr = insCtr;
	}
}
break;
case 9:
#line 130 "ada.y"
{
	if ( sCtr > 2 ) {
		Insert( yyvsp[0].var, &( stack[ sCtr-2 ].root ) );
		treeNode *find_inserted = search( yyvsp[0].var, stack[ sCtr-2 ].root );
		char *str = malloc(sizeof("procedure")+1);
		strcpy(str, "procedure");
        find_inserted->data.kind = str;
		find_inserted->data.ins_ctr = insCtr;
	}
}
break;
case 10:
#line 143 "ada.y"
{
	yyval.var = yyvsp[0].var;
	offset = 4;
	push_tree(yyvsp[0].var);
}
break;
case 15:
#line 158 "ada.y"
{ 
	yyval.var = yyvsp[0].var; 
}
break;
case 16:
#line 164 "ada.y"
{
	aList = malloc(sizeof(struct idnode));
	(*aList).next = yyvsp[0].listptr;
	(*aList).name = malloc(strlen(yyvsp[-2].var)+1);
	strcpy((*aList).name, yyvsp[-2].var);
	yyval.listptr = aList;
}
break;
case 17:
#line 173 "ada.y"
{
	aList = malloc(sizeof(struct idnode));
	(*aList).next = NULL;
	(*aList).name = malloc(strlen(yyvsp[0].var)+1);
	strcpy((*aList).name, yyvsp[0].var);
	yyval.listptr = aList;
}
break;
case 22:
#line 189 "ada.y"
{
	yyval.var = yyvsp[0].var;
}
break;
case 27:
#line 203 "ada.y"
{
	if(sCtr > 2){
		treeNode *search = parentSearch(stack[sCtr-1].name);
		search->data.offSet = offset;
		search->data.ARsize = offset;
	}
}
break;
case 34:
#line 220 "ada.y"
{
	int legal = add(yyvsp[-9].var);
	if(legal != -1){
		treeNode* newArr = search( yyvsp[-9].var,stack[sCtr-1].root );
		char *str = malloc(sizeof("array")+1);
        	strcpy(str, "array");
		newArr->data.kind = str;
		newArr->data.lower = yyvsp[-5].integer;
		newArr->data.upper = yyvsp[-3].integer;
		/*find parent type*/
		treeNode *findType = parentSearch( yyvsp[0].var );
		/*add to component type*/
		newArr->data.component_type = findType;
		/*calculate the length, put in size*/
		int length = yyvsp[-3].integer-yyvsp[-5].integer+1;
		newArr->data.size = length * findType->data.size;
	}
}
break;
case 39:
#line 252 "ada.y"
{
	printf("Line no %d: ", lineno + 1);
	print_list(yyvsp[-2].listptr);
	printf(" : %s\n", yyvsp[0].var);
	int num = 0;
	set_Type(yyvsp[-2].listptr, yyvsp[0].var, &num);
	printf("There are %d vars in %s\n", num, stack[sCtr-1].name);
	stack[sCtr-1].root->data.nextARsize = num;
	printf("NEXTAR: %d\n", stack[sCtr-1].root->data.nextARsize);
}
break;
case 52:
#line 289 "ada.y"
{
	int d;
	treeNode* lookup = walkBack(yyvsp[-2].var, &d);
	printf("VAL OF ISBOOL FOR %s := %d\n", lookup->data.name, yyvsp[0].semNode->isBool);
	if(d == 0){
		if(lookup != NULL){
			if(yyvsp[0].semNode->isBool == 1){
				lookup->data.value = yyvsp[0].semNode->value;
				printf("Assigning %d to var %s at offset %d\n", yyvsp[0].semNode->value, lookup->data.name, lookup->data.offSet);
				if(yyvsp[0].semNode->value == 1){
					fprintf(codeFile, "%d contents b, %d := true\n",getInstruction(), lookup->data.offSet);
				}else if(yyvsp[0].semNode->value == 0){
					fprintf(codeFile, "%d contents b, %d := false\n",getInstruction(), lookup->data.offSet);
				}
				lookup->data.inReg = yyvsp[0].semNode->regNum;
			}else{
				if(yyvsp[0].semNode->depth > 0){
					int currReg = getRegister();
					fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
					fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
					fprintf(codeFile, "%d contents b, %d := contents r%d, %d\n", getInstruction(), lookup->data.offSet, currReg, yyvsp[0].semNode->offset);
				}else{
					lookup->data.value = yyvsp[0].semNode->value;
					printf("Assigning %d to var %s at offset %d\n", yyvsp[0].semNode->value, lookup->data.name, lookup->data.offSet);
					fprintf(codeFile, "%d contents b, %d := r%d\n",getInstruction(), lookup->data.offSet, yyvsp[0].semNode->regNum);
					lookup->data.inReg = yyvsp[0].semNode->regNum;
				}
			}
		}
	}else if(d == 1){
		if(lookup != NULL){
			lookup->data.value = yyvsp[0].semNode->value;
			currReg = getRegister();
			fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
			fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
			if(yyvsp[0].semNode->isNum == 0){
				fprintf(codeFile, "%d contents r%d, %d := contents b, %d\n", getInstruction(), currReg, lookup->data.offSet, yyvsp[0].semNode->offset);
			}else{
				fprintf(codeFile, "%d contents r%d, %d := r%d\n", getInstruction(), currReg, lookup->data.offSet, currReg-1);
			}
		}
		lookup->data.inReg = yyvsp[0].semNode->regNum;
	}else{
		if(lookup != NULL){
			lookup->data.value = yyvsp[0].semNode->value;
			currReg = getRegister();
			fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
			fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
			int i = 1;
			while(i < d){
				printf("going back %d links....\n", i);
				fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
				i = i + 1;
			}
			if(yyvsp[0].semNode->isNum == 0){
				fprintf(codeFile, "%d contents r%d, %d := contents b, %d\n", getInstruction(), currReg, lookup->data.offSet, yyvsp[0].semNode->offset);
			}else{
				fprintf(codeFile, "%d contents r%d, %d := r%d\n", getInstruction(), currReg, lookup->data.offSet, currReg-1);
			}
		}
		lookup->data.inReg = yyvsp[0].semNode->regNum;
	}
}
break;
case 53:
#line 356 "ada.y"
{
	int startloop = insCtr;
}
break;
case 54:
#line 362 "ada.y"
{
	/*fprintf(codeFile, "%d pc := %d)*/
}
break;
case 63:
#line 385 "ada.y"
{
	treeNode* find = parentSearch(yyvsp[-1].var);
	int d;
	char *name;
	treeNode* lookup = walkBack(yyvsp[-1].var, &d);
	if(yyvsp[0].writeList->isBool == 1){
		name = "boolean";
	}else{
		name = "integer";
	}
	if(strcmp(find->data.kind, "read_routine") == 0){
		fprintf(codeFile, "%d read_%s contents b, %d\n", getInstruction(), name, yyvsp[0].writeList->offset);
	}else if(strcmp(find->data.kind, "write_routine") == 0){
		emitWrite(yyvsp[0].writeList, codeFile);
	}
}
break;
case 64:
#line 402 "ada.y"
{
	/*check if the proc. is in the scope*/
	int d;
	printf("THE STACK CTR IS %d\n", sCtr);
	treeNode* found = walkBack(yyvsp[0].var, &d);
	if(found != NULL){
		printf("The value of d is %d\n", d);
		/*start to build AR for proc. call*/
		if((d == 1)||(d == 0)){ /*dyn. link is main*/
			
			int currReg = getRegister();
			fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
			/*THIS ADJUSTS THE NEW BASE OF THE AR*/
			fprintf(codeFile, "%d b := contents r%d, 0\n", getInstruction(), currReg);
			fprintf(codeFile, "%d contents b, 3 := r%d\n", getInstruction(), currReg); /*DYN LINK*/
			
			
			
			
			if(d >= 1){
				printf("The depth is %d\n", d);
				fprintf(codeFile, "%d contents b, 2 := contents r%d, 2\n", getInstruction(), currReg);
				/*Static Link is the same as the previous AR's static link.*/
			}else if(d == 0){
				fprintf(codeFile, "%d contents b, 2 := r%d\n", getInstruction(), currReg);
				/*Static link is the same as the dynamic link*/
			}
			
			
			
			
			
			
			/*FIX NEXT BASE*/
			currReg = getRegister();
			fprintf(codeFile, "%d r%d = ?\n", getInstruction(), currReg);
			fprintf(codeFile, "%d contents b, 0 := b + r%d\n", getInstruction(), currReg);
			/*FIX RETURN ADDRESS*/
			int ins = getInstruction();
			currReg = getRegister();
			fprintf(codeFile, "%d r%d := %d\n", ins, currReg, ins + 3);
			fprintf(codeFile, "%d contents b, 1 := r%d\n", getInstruction(), currReg);
			fprintf(codeFile, "%d pc := %d\n", getInstruction(), found->data.ins_ctr);
		}
		if(d > 1){
				printf("The depth is %d\n", d);
				fprintf(codeFile, "%d contents b, 2 := contents r%d, 2\n", getInstruction(), currReg);
				int i = 1;
				while(i < d){
					printf("going back %d links....\n", i);
					fprintf(codeFile, "%d contents r%d, 2 := r%d\n", getInstruction(), currReg);
					i = i + 1;
			}
		}
	}
}
break;
case 65:
#line 461 "ada.y"
{
	yyval.writeList = yyvsp[-1].writeList;
}
break;
case 66:
#line 467 "ada.y"
{
	wrList = malloc(sizeof(struct writeNode));
	(*wrList).next = yyvsp[0].writeList;
	(*wrList).rNum = yyvsp[-2].semNode->regNum;
	(*wrList).isBool = yyvsp[-2].semNode->isBool;
	(*wrList).offset = yyvsp[-2].semNode->offset;
	yyval.writeList = wrList;
}
break;
case 67:
#line 477 "ada.y"
{
	wrList = malloc(sizeof(struct writeNode));
	(*wrList).next = NULL;
	(*wrList).rNum = yyvsp[0].semNode->regNum;
	(*wrList).isBool = yyvsp[0].semNode->isBool;
	(*wrList).offset = yyvsp[0].semNode->offset;
	yyval.writeList = wrList;
}
break;
case 68:
#line 489 "ada.y"
{
	yyval.semNode = yyvsp[0].semNode;

}
break;
case 69:
#line 494 "ada.y"
{
	int currReg = getRegister();
	int a;
	emitBoolInstruct(yyvsp[-2].semNode, yyvsp[0].semNode, yyvsp[-1].integer, currReg, codeFile, &a);
	yyval.semNode->regNum = currReg;
	yyval.semNode->value = a;
}
break;
case 70:
#line 504 "ada.y"
{
	yyval.semNode = yyvsp[0].semNode;
}
break;
case 71:
#line 508 "ada.y"
{
	int currReg = getRegister();
	int a;
	emitRelInstruct(yyvsp[-2].semNode, yyvsp[0].semNode, yyvsp[-1].integer, currReg, codeFile, &a);
	yyval.semNode->regNum = currReg;
	yyval.semNode->value = a;
}
break;
case 72:
#line 519 "ada.y"
{
	yyval.semNode = yyvsp[0].semNode;
}
break;
case 73:
#line 523 "ada.y"
{
	if(yyvsp[-1].integer == 1){
		yyval.semNode->value = yyvsp[-2].semNode->value + yyvsp[0].semNode->value;
	}else{
		yyval.semNode->value = yyvsp[-2].semNode->value - yyvsp[0].semNode->value;
	}
	
	if((yyvsp[-2].semNode->isNum == 0)&&(yyvsp[0].semNode->isNum == 0)){
	
		int regist = getRegister();
		
		if(yyvsp[0].semNode->inReg == 1){
			if(yyvsp[-2].semNode->inReg == 1){
				fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
				if(yyvsp[-1].integer == 1){
					fprintf(codeFile, " + ");
				}else{
					fprintf(codeFile, " - ");
				}
				fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
				yyval.semNode->inReg = 1;
				yyval.semNode->regNum = regist;
			}else{
				fprintf(codeFile, "%d r%d := contents b, %d", getInstruction(), regist, yyvsp[-2].semNode->offset);
				if(yyvsp[-1].integer == 1){
					fprintf(codeFile, " + ");
				}else{
					fprintf(codeFile, " - ");
				}
				fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
				yyval.semNode->inReg = 1;
				yyval.semNode->regNum = regist;
			}
		}
		
		else if(yyvsp[-2].semNode->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
		
		else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), getRegister(), yyvsp[-2].semNode->offset);

			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "contents b, %d\n", yyvsp[0].semNode->offset);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regCt;
		}
		
		
		
		
	}else if((yyvsp[-2].semNode->isNum == 1)&&(yyvsp[0].semNode->isNum == 1)){
		int regist = getRegister();
		fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, yyvsp[-2].semNode->regNum);
		if(yyvsp[-1].integer == 1){
			fprintf(codeFile, " + ");
			printf(" PLUS");
		}else{
			fprintf(codeFile, " - ");
			printf(" MINUS");
		}
		fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
		yyval.semNode->inReg = 1;
		yyval.semNode->regNum = regist;
		
			
	}else if((yyvsp[-2].semNode->isNum == 1)&&(yyvsp[0].semNode->isNum == 0)){
		int regist = getRegister();
		if(yyvsp[0].semNode->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "contents b, %d\n", yyvsp[0].semNode->offset);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
	}else if((yyvsp[-2].semNode->isNum == 0)&&(yyvsp[0].semNode->isNum == 1)){
		int regist = getRegister();
		if(yyvsp[-2].semNode->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), regist, yyvsp[-2].semNode->offset);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
	}
}
break;
case 74:
#line 652 "ada.y"
{
	yyval.semNode = yyvsp[0].semNode;
	
}
break;
case 75:
#line 657 "ada.y"
{
	if(yyvsp[-1].integer == 1){
		yyval.semNode->value = yyvsp[-2].semNode->value * yyvsp[0].semNode->value;
		
	}else{
		yyval.semNode->value = yyvsp[-2].semNode->value / yyvsp[0].semNode->value;
		
	}
	if((yyvsp[-2].semNode->isNum == 0)&&(yyvsp[0].semNode->isNum == 0)){
	
		int regist = getRegister();
		
		if(yyvsp[0].semNode->inReg == 1){
			if(yyvsp[-2].semNode->inReg == 1){
				fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
				if(yyvsp[-1].integer == 1){
					fprintf(codeFile, " * ");
				}else{
					fprintf(codeFile, " / ");
				}
				fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
				yyval.semNode->inReg = 1;
				yyval.semNode->regNum = regist;
			}else{
				fprintf(codeFile, "%d r%d := contents b, %d", getInstruction(), regist, yyvsp[-2].semNode->offset);
				if(yyvsp[-1].integer == 1){
					fprintf(codeFile, " * ");
				}else{
					fprintf(codeFile, " / ");
				}
				fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
				yyval.semNode->inReg = 1;
				yyval.semNode->regNum = regist;
			}
		}
		
		else if(yyvsp[-2].semNode->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
		
		else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), regist, yyvsp[-2].semNode->offset);

			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "contents b, %d\n", yyvsp[0].semNode->offset);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
		
		
		
		
	}else if((yyvsp[-2].semNode->isNum == 1)&&(yyvsp[0].semNode->isNum == 1)){
		int regist = getRegister();
		fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, yyvsp[-2].semNode->regNum);
		if(yyvsp[-1].integer == 1){
			fprintf(codeFile, " * ");
			printf(" PLUS");
		}else{
			fprintf(codeFile, " / ");
			printf(" MINUS");
		}
		fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
		yyval.semNode->inReg = 1;
		yyval.semNode->regNum = regist;
		
			
	}else if((yyvsp[-2].semNode->isNum == 1)&&(yyvsp[0].semNode->isNum == 0)){
		int regist = getRegister();
		if(yyvsp[0].semNode->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "contents b, %d\n", yyvsp[0].semNode->offset);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
	}else if((yyvsp[-2].semNode->isNum == 0)&&(yyvsp[0].semNode->isNum == 1)){
		int regist = getRegister();
		if(yyvsp[-2].semNode->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, yyvsp[-2].semNode->regNum);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), regist, yyvsp[-2].semNode->offset);
			if(yyvsp[-1].integer == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
			yyval.semNode->inReg = 1;
			yyval.semNode->regNum = regist;
		}
	}
}
break;
case 76:
#line 788 "ada.y"
{
	yyval.semNode = yyvsp[0].semNode;
	
}
break;
case 77:
#line 793 "ada.y"
{
	yyval.semNode = yyvsp[-2].semNode;
}
break;
case 78:
#line 797 "ada.y"
{
	yyval.semNode = (semInfo*)malloc(sizeof(semInfo*));
	currReg = getRegister();
	fprintf(codeFile, "%d r%d := not ", getInstruction(), currReg);
	yyval.semNode->inReg = 1;
	yyval.semNode->regNum = currReg;
	fprintf(codeFile, "r%d\n", yyvsp[0].semNode->regNum);
	if(yyvsp[0].semNode->value == 0){
		yyval.semNode->value = 1;
	}else{
		yyval.semNode->value = 0;
	}
}
break;
case 79:
#line 811 "ada.y"
{
	yyval.semNode = (semInfo*)malloc(sizeof(semInfo*));
	yyval.semNode = semConstruct();
	int neg = 0 - yyvsp[0].semNode->value;
	yyval.semNode->value = neg;
	yyval.semNode->isVar = 0;
	yyval.semNode->inReg = 1;
	yyval.semNode->regNum = getRegister();
	yyval.semNode->isArray = 0;
	yyval.semNode->isNum = 1;
	fprintf(codeFile, "%d r%d := - r%d\n", getInstruction(), yyval.semNode->regNum, yyvsp[0].semNode->regNum);
}
break;
case 80:
#line 827 "ada.y"
{
	yyval.semNode = (semInfo*)malloc(sizeof(semInfo*));
	yyval.semNode = semConstruct();
	emitImmData(yyval.semNode, yyvsp[0].integer, codeFile);
	yyval.semNode->isNum = 1;
	
}
break;
case 81:
#line 835 "ada.y"
{
	yyval.semNode = (semInfo*)malloc(sizeof(treeNode*));
	yyval.semNode = semConstruct();
	int d;
	treeNode* lookup = walkBack(yyvsp[0].var, &d);
	if(lookup != NULL){
		if(strcmp(lookup->data.name, "false") == 0){
				printf("FOUND A FALSE\n");
				yyval.semNode->value = 0;
				yyval.semNode->isBool = 1;
		}else if(strcmp(lookup->data.name, "true") == 0){
				printf("FOUND A TRUE\n");
				lookup->data.value = 1;
				yyval.semNode->isBool = 1;
		}
		printf("Value of %s is %d\n", lookup->data.name, lookup->data.value);
		if(strcmp(lookup->data.kind, "boolean") == 0){
			printf("FOUND A BOOLEAN\n");
			yyval.semNode->isBool = 1;
			treeNode* bool = parentSearch(yyvsp[0].var);
			printf("Found a %s\n", yyvsp[0].var);
			
			yyval.semNode->isLocal = 1;
			yyval.semNode->regNum = lookup->data.inReg;
			yyval.semNode->offset = lookup->data.offSet;
			yyval.semNode->depth = d;
		}else{
			yyval.semNode->value = lookup->data.value;
			yyval.semNode->isLocal = 1;
			yyval.semNode->regNum = lookup->data.inReg;
			yyval.semNode->offset = lookup->data.offSet;
			yyval.semNode->depth = d;
		}
	}else{
		printf("OOPS");
	}
	yyval.semNode->isNum = 0;
	yyval.semNode->isLocal = 0;
}
break;
case 82:
#line 875 "ada.y"
{
yyval.semNode = (semInfo*)malloc(sizeof(semInfo*));
}
break;
case 83:
#line 881 "ada.y"
{
	yyval.integer = 0;
}
break;
case 84:
#line 885 "ada.y"
{
	yyval.integer = 1;
}
break;
case 85:
#line 890 "ada.y"
{ yyval.integer = 1; }
break;
case 86:
#line 891 "ada.y"
{ yyval.integer = 2; }
break;
case 87:
#line 892 "ada.y"
{ yyval.integer = 3; }
break;
case 88:
#line 893 "ada.y"
{ yyval.integer = 4; }
break;
case 89:
#line 894 "ada.y"
{ yyval.integer = 5; }
break;
case 90:
#line 895 "ada.y"
{ yyval.integer = 6; }
break;
case 91:
#line 899 "ada.y"
{
	yyval.integer = 1;
}
break;
case 92:
#line 903 "ada.y"
{
	yyval.integer = -1;
}
break;
case 93:
#line 909 "ada.y"
{
	yyval.integer = 1;
}
break;
case 94:
#line 913 "ada.y"
{
	yyval.integer = -1;
}
break;
#line 1453 "y.tab.c"
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
    return (1);

yyaccept:
    return (0);
}
