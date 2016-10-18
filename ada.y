%{
	/* Alex Voitik          */
	/* ada.y                */
	/* Last Edit: 9/21/2016 */
%}

%token IS BEG END PROCEDURE ID NUMBER TYPE ARRAY RAISE OTHERS
%token RECORD IN OUT RANGE CONSTANT ASSIGN EXCEPTION NULLWORD LOOP IF
%token THEN ELSEIF ELSE EXIT WHEN AND OR EQ NEQ LT GT GTE LTE TICK
%token NOT EXP ARROW OF DOTDOT ENDIF ENDREC ENDLOOP EXITWHEN
%type <integer> NUMBER
%type <var> ID
%union {
    int integer;
    char *var;
}
%%

program                                                : main_body {printf ("\n*****\nDone.\n*****\n");}
                                                       ;
			
main_body                                              : main_specification IS
                                                         declarative_part BEG
                                                       | main_specification IS BEG
                                                       ;
			
main_specification /*DONE*/                            : PROCEDURE ID
;
						   

declarative_part                                       : /*subprogram_body_decl|*/ decl
                                                       ;
							
decl 						                           : object_decl
							                         /*| type_decl */
							                         /*| subtype_decl */
							                         /*| pragma */
							                         /*| subprogram_decl */
							                         /*| id_list EXCEPTION */
                                                       ;
							
object_decl /*DONE*/ 				                   : id_list ':' constant_option type_or_subtype initialization_option ';'
							                           ;
							
id_list /*DONE*/ 					                   : id ',' id_list
                                                       | id 
							                           ;
							
id /*DONE*/                                            : ID
;

constant_option	/*DONE*/		                       : NUMBER
                                                       | /* Empty */
							                           ;
		
type_or_subtype	/*DONE*/		  	                   : type
                                                       | subtype_def
							                           ;
			
type /*DONE*/                                          : type_name
                                                       | type_def
                                                       ;

type_name /*DONE*/                                     : id
                                                       ;

type_def /*DONE*/                                      : record_type_def
                                                       | array_type_def
                                                       | enum_type_def
		                                             /*| ACCESS subtype */
                                                       ;

record_type_def /*DONE*/                               : RECORD component_list ENDREC
                                                       | RECORD component_null ENDREC
						                             /*| RECORD component_list variant_part ENDREC */
                                                       ;

component_list /*DONE*/                                : component_decl
                                                       | component_decl component_list
                                                       ;

component_null /*DONE*/                                : NULLWORD ';'
                                                       ;

component_decl /*DONE*/                                : id_list ':' type_or_subtype initialization_option ';'
                                                       ;

/*variant_part : DO NOT HAVE CASE OR END CASE IN .L FILE  */

array_type_def /*DONE*/                                : unconstrained_array_def
                                                       | constrained_array_def
                                                       ;

unconstrained_array_def /*DONE*/                       : ARRAY unconstrained_index_list OF element_type
                                                       ;

unconstrained_index_list /*DONE*/                      : '(' index_subtype_def ')'
                                                       | '(' index_subtype_def ',' unconstrained_index_list_end
                                                       ;

unconstrained_index_list_end /*DONE*/                  : index_subtype_def ')'
                                                       | index_subtype_def ',' unconstrained_index_list_end
                                                       ;

index_subtype_def /*DONE*/                             : type_name RANGE /* <> NEED BOX? */
                                                       ;

element_type /*DONE*/                                  : type_or_subtype
                                                       ;

constrained_array_def /*DONE*/                         : ARRAY constrained_index_list OF element_type
                                                       ;

constrained_index_list /*DONE*/                        : '(' discreet_range ')'
                                                       | '(' discreet_range ',' constrained_index_end
                                                       ;

constrained_index_end /*DONE*/                         : discreet_range ')'
                                                       | discreet_range ',' constrained_index_end
                                                       ;

discreet_range /*DONE*/                                : subtype
                                                       | range
                                                       ;

subtype /*DONE*/                                       : type_name
                                                       | subtype_def
                                                       ;

range /*DONE*/                                         : simple_expression DOTDOT simple_expression
                                                       ;

simple_expression /*DONE*/                             : unary_adding_op
                                                       | term
                                                       | term adding_op term
                                                       | unary_adding_op term
                                                       | unary_adding_op term adding_op term
                                                       ;

unary_adding_op                                        : RAISE
                                                       ;

term                                                   : NUMBER
                                                       ;

adding_op                                              : EQ
                                                       ;

enum_type_def                                          : AND
                                                       ;

subtype_def                                            : ELSE
                                                       ;
 				
initialization_option	                               : EXP
						                               ;
				 

%%
#include <stdio.h>
#include <string.h>
extern FILE *yyin;
main()
{
    printf("About to scan. . . . . .\n");
	// open a file handle to a particular file:
	FILE *myfile = fopen("test.adb", "r");
	// make sure it is valid:
	if (!myfile) {
		printf("I can't open the file!\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}
