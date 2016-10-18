%{
	/* Alex Voitik          */
	/* ada.l                */
	/* Last Edit: 9/21/2016 */

	#include "y.tab.h"
	#include <stdio.h>
	#include <string.h>

	int lineno = 0;
%}
%%
[ \t]+                      /*ignore*/
"is"                        { return IS;}
"--".*\n                    /*ignore*/
[\n]                        { lineno++; }
"end if"                    { return ENDIF;}
"end record"                { return ENDREC;}
"end loop"                  { return ENDLOOP;}
"exit when"                 { return EXITWHEN;}
"of"                        { return OF;}
"begin"                     { return BEG;}
"end"                       { return END;}
".."                        { return DOTDOT;}
"'"                         { return TICK;}
"procedure"                 { return PROCEDURE;}
"type"                      { return TYPE;}
"array"                     { return ARRAY; }
"record"                    { return RECORD; }
"in"                        { return IN; }
"out"                       { return OUT; }
"range"                     { return RANGE; }
"constant"                  { return CONSTANT; }
":="                        { return ASSIGN; }
"exception"                 { return EXCEPTION; }
"null"                      { return NULLWORD; }
"loop"                      { return LOOP; }
"if"                        { return IF; }
"then"                      { return THEN; }
"elsif"                     { return ELSEIF; }
"else"                      { return ELSE; }
"exit"                      { return EXIT; }
"when"                      { return WHEN; }
"and"                       { return AND; }
"or"                        { return OR; }
"not"                       { return NOT; }
"="                         { return EQ; }
"/="                        { return NEQ; }
">"                         { return GT; }
"<"                         { return LT; }
">="                        { return GTE; }
"<="                        { return LTE; }
"**"                        { return EXP; }
"raise"                     { return RAISE; }
"others"                    { return OTHERS; }
"=>"                        { return ARROW; }
[0-9]+                      {yylval.integer = atoi(yytext); return NUMBER;}
[a-z][a-zA-Z0-9\_]*         {yylval.var = malloc(sizeof(yytext)); yylval.var = strdup(yytext); return ID;} 
.                           {return yytext[0];}

   
%%
