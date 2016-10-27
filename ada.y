%{
	/* Alex Voitik          */
	/* ada.y                */
	/* Last Edit: 10/24/2016 */

	extern int lineno;

%}

%token IS BEG END PROCEDURE ID NUMBER TYPE ARRAY RAISE OTHERS
%token RECORD IN OUT RANGE CONSTANT ASSIGN EXCEPTION NULLWORD LOOP IF
%token THEN ELSEIF ELSE EXIT WHEN AND OR EQ NEQ LT GT GTE LTE TICK
%token NOT EXP ARROW OF DOTDOT ENDIF ENDREC ENDLOOP EXITWHEN
%type <integer> NUMBER 
%type <var> ID
%type <var> type_name
%type <listptr> id_list
%union {
    int integer;
    char *var;
    struct idnode *listptr;	
}
%%

program	: main_body {printf ("\n*****\nDone.\n*****\n");}
;		
main_body : main_spec IS
declarative_part BEG
seq_of_stmts
except_part END ';'
;

main_spec : PROCEDURE ID
;

procedure_body : procedure_spec IS
declarative_part BEG
seq_of_stmts
except_part END ';'
;

procedure_spec : PROCEDURE ID formal_param_part
;
formal_param_part : '(' parameters ')'
| /*empty*/
;
parameters : id_list ':' mode type_name ';' parameters
| id_list ':' mode type_name 
;


id_list : ID ',' id_list 
{
	aList = malloc(sizeof(struct idnode));
	(*aList).next = $3;
	(*aList).name = malloc(strlen($1)+1);
	strcpy((*aList).name, $1);
	$$ = aList;
}

| ID
{
	aList = malloc(sizeof(struct idnode));
	(*aList).next = NULL;
	(*aList).name = malloc(strlen($1)+1);
	strcpy((*aList).name, $1);
	$$ = aList;
}

;
mode : IN
| OUT
| IN OUT
| /*empty -- default is in*/
; 

type_name : ID 
{
	$$ = malloc(sizeof(strlen($1)+1));
	strcpy($$, $1);
}
 
; 

declarative_part : array_type ';' declarative_part
				   | record_type ';' declarative_part
				   | name_type ';' declarative_part
				   | variable_decl ';' declarative_part
				   | constant_type ';' declarative_part
				   | exception_type ';' declarative_part
| procedure_body declarative_part
| /*empty*/
;

array_type : TYPE ID IS ARRAY '(' constant DOTDOT constant ')' OF type_name
;
constant : ID
| NUMBER
;

record_type : TYPE ID IS RECORD component_list ENDREC
;

component_list : variable_decl ';' component_list
| /*empty*/
;


variable_decl : id_list ':' type_name
{
	printf("Line no %d: ", lineno + 1);
	print_list($1);
	printf(" : %s\n", $<var>3);
}

;

name_type : TYPE ID IS RANGE constant DOTDOT constant
;

constant_type : id_list ':' CONSTANT ASSIGN constant_expr
;

exception_type : id_list ':' EXCEPTION
;

constant_expr : NUMBER ;


seq_of_stmts : stmt_type seq_of_stmts
| /*empty*/
;

stmt_type : NULLWORD ';'
| assignment_stmt ';'
| procedure_call ';'
| loop_stmt ';'
| if_stmt ';'
| raise_exc ';'
| expression ';'
;

assignment_stmt : ID ASSIGN expression; 


loop_stmt : LOOP seq_of_stmts loop_exit ENDLOOP
;

loop_exit : EXIT ';'
| EXITWHEN expression ';'
| /*empty*/
;

if_stmt : IF expression THEN seq_of_stmts if_cont ENDIF
;

if_cont : ELSEIF expression THEN seq_of_stmts if_cont
| ELSE seq_of_stmts
| /*empty*/
;

raise_exc : RAISE ID;

procedure_call : ID optional_actual_parameter_part
;

expression :  relation bool_list
;

bool_list : boolean_op relation bool_list
| /*empty*/
;

relation : simple_expr relational_op_list
;

relational_op_list : relational_op simple_expr relational_op_list
| /*empty*/
;

simple_expr : term adding_op_list
| '-' term adding_op_list
;

adding_op_list : adding_op term adding_op_list
| /*empty*/
;

term : factor mult_op_list
;

mult_op_list : multiplying_op factor mult_op_list
| /*empty*/
;

factor : primary exp_list
| NOT primary
;

exp_list : EXP primary exp_list
| /*empty*/
;
primary : NUMBER 
| ID 
| '(' expression ')'
;

boolean_op : AND 
| OR
;

relational_op : EQ 
| NEQ 
| LT 
| LTE 
| GT 
| GTE
;

adding_op : '+' 
| '-'
;

multiplying_op : '*' 
| '/'
;

optional_actual_parameter_part : '(' actual_parameter ')'
;

actual_parameter : expression ',' actual_parameter
| expression
;

except_part : EXCEPTION exception_body
| /*empty*/
;

exception_body : WHEN choice_sequence ARROW seq_of_stmts exception_body
| WHEN OTHERS ARROW seq_of_stmts
| /*empty*/
;

choice_sequence : ID choice_sequence
| '|' ID choice_sequence
| /*empty*/
;			 

%%
#include <stdio.h>
#include <string.h>
#include "struct_def.h"
main()
{
	yyparse();
	
}
