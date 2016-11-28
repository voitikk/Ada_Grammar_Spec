%{
	/* Alex Voitik          */
	/* ada.y                */
	/* Last Edit: 10/30/2016 */

#include <stdio.h>
#include "include_list.h"
	extern int lineno;
	int currReg;
	

%}

%token IS BEG END PROCEDURE ID NUMBER TYPE ARRAY RAISE OTHERS
%token RECORD IN OUT RANGE CONSTANT ASSIGN EXCEPTION NULLWORD LOOP IF
%token THEN ELSEIF ELSE EXIT WHEN AND OR EQ NEQ LT GT GTE LTE TICK
%token NOT EXP ARROW OF DOTDOT ENDIF ENDREC ENDLOOP EXITWHEN
%type <integer> NUMBER
%type <integer> adding_op
%type <integer> multiplying_op
%type <integer> relational_op
%type <integer> boolean_op
%type <var> ID
%type <var> type_name
%type <listptr> id_list
%type <var> identifier
%type <integer> constant
%type <var> procedure_head
%type <semNode> primary
%type <semNode> term
%type <semNode> expression
%type <writeList> function_params
%type <writeList> optional_params
%type <semNode> relation
%type <semNode> factor
%type <semNode> simple_expr
%type <semNode> proc_params

%union {
    	int integer;
    	char *var;
    	struct idnode *listptr;
		struct semInfo *semNode;
		struct writeNode *writeList;
}
%%

program	: main_body {printf ("\n*****\nDone.\n*****\n");}
;

main_body : main_spec IS
declarative_part BEG
{

	beg_main = insCtr;	
}

seq_of_stmts
except_part END ';'
{
	printf("\nPopping scope for %s, Printing Tree\n", stack[sCtr-1].name);
	printf("All Code in Code.txt file\n");
	printf("***************************************************************\n");
	printTree(stack[sCtr-1].root);
	if(sCtr > 0){
		int curr_reg = getRegister();
		
		//main Epilogue
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
;

main_spec : PROCEDURE ID
{
	push_tree($2);
	
}  
;

procedure_body : procedure_spec IS
{
	printf("%s declared by %s\n", stack[sCtr-1].name, stack[sCtr-2].name);
}
declarative_part BEG
{
	printf("\nBeginnning of %s's Code at line %d\n\n", stack[sCtr-1].name, insCtr);
}
seq_of_stmts
except_part END ';'
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
;

procedure_spec : procedure_head '(' formal_param_part ')'
{
	if ( sCtr > 2 ) {
		Insert( $1, &( stack[ sCtr-2 ].root ) );
		treeNode *find_inserted = search( $1, stack[ sCtr-2 ].root );
		char *str = malloc(sizeof("procedure")+1);
		strcpy(str, "procedure");
        find_inserted->data.kind = str;
		find_inserted->data.ins_ctr = insCtr;
	}
}
| procedure_head
{
	if ( sCtr > 2 ) {
		Insert( $1, &( stack[ sCtr-2 ].root ) );
		treeNode *find_inserted = search( $1, stack[ sCtr-2 ].root );
		char *str = malloc(sizeof("procedure")+1);
		strcpy(str, "procedure");
        find_inserted->data.kind = str;
		find_inserted->data.ins_ctr = insCtr;
	}
}
;

procedure_head : PROCEDURE ID
{
	$$ = $2;
	offset = 4;
	push_tree($2);
}

formal_param_part : parameters
| /*empty*/
;

parameters : id_list ':' mode type_name ';' parameters
| id_list ':' mode type_name 
;

identifier : ID
{ 
	$$ = $1; 
}
;

id_list : identifier ',' id_list 
{
	aList = malloc(sizeof(struct idnode));
	(*aList).next = $3;
	(*aList).name = malloc(strlen($1)+1);
	strcpy((*aList).name, $1);
	$$ = aList;
}

| identifier
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

type_name : identifier 
{
	$$ = $1;
}
; 

declarative_part : decl_list procedure_decl_list
;

procedure_decl_list : procedure_body procedure_decl_list
|
;

decl_list : decl ';' decl_list
|
{
	if(sCtr > 2){
		treeNode *search = parentSearch(stack[sCtr-1].name);
		search->data.offSet = offset;
		search->data.ARsize = offset;
	}
}
;
decl : array_type
| record_type
| name_type
| variable_decl
| constant_type
| exception_type;
;

array_type : TYPE ID IS ARRAY '(' constant DOTDOT constant ')' OF type_name
{
	int legal = add($2);
	if(legal != -1){
		treeNode* newArr = search( $2,stack[sCtr-1].root );
		char *str = malloc(sizeof("array")+1);
        	strcpy(str, "array");
		newArr->data.kind = str;
		newArr->data.lower = $6;
		newArr->data.upper = $8;
		//find parent type
		treeNode *findType = parentSearch( $11 );
		//add to component type
		newArr->data.component_type = findType;
		//calculate the length, put in size
		int length = $8-$6+1;
		newArr->data.size = length * findType->data.size;
	}
}
;

constant : NUMBER
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
	int num = 0;
	set_Type($1, $3, &num);
	printf("There are %d vars in %s\n", num, stack[sCtr-1].name);
	stack[sCtr-1].root->data.nextARsize = num;
	printf("NEXTAR: %d\n", stack[sCtr-1].root->data.nextARsize);
}
;

name_type : TYPE ID IS RANGE constant DOTDOT constant
;

constant_type : id_list ':' CONSTANT ASSIGN constant_expr
;

exception_type : id_list ':' EXCEPTION
;

constant_expr : NUMBER ;


seq_of_stmts : stmt_type ';' seq_of_stmts
| stmt_type ';' 
;

stmt_type : NULLWORD
| assignment_stmt
| procedure_call
| loop_stmt
| if_stmt
| raise_exc
;

assignment_stmt : identifier ASSIGN expression
{
	int d;
	treeNode* lookup = walkBack($1, &d);
	printf("VAL OF ISBOOL FOR %s := %d\n", lookup->data.name, $3->isBool);
	if(d == 0){
		if(lookup != NULL){
			if($3->isBool == 1){
				lookup->data.value = $3->value;
				printf("Assigning %d to var %s at offset %d\n", $3->value, lookup->data.name, lookup->data.offSet);
				if($3->value == 1){
					fprintf(codeFile, "%d contents b, %d := true\n",getInstruction(), lookup->data.offSet);
				}else if($3->value == 0){
					fprintf(codeFile, "%d contents b, %d := false\n",getInstruction(), lookup->data.offSet);
				}
				lookup->data.inReg = $3->regNum;
			}else{
				if($3->depth > 0){
					int currReg = getRegister();
					fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
					fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
					fprintf(codeFile, "%d contents b, %d := contents r%d, %d\n", getInstruction(), lookup->data.offSet, currReg, $3->offset);
				}else{
					lookup->data.value = $3->value;
					printf("Assigning %d to var %s at offset %d\n", $3->value, lookup->data.name, lookup->data.offSet);
					fprintf(codeFile, "%d contents b, %d := r%d\n",getInstruction(), lookup->data.offSet, $3->regNum);
					lookup->data.inReg = $3->regNum;
				}
			}
		}
	}else if(d == 1){
		if(lookup != NULL){
			lookup->data.value = $3->value;
			currReg = getRegister();
			fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
			fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
			if($3->isNum == 0){
				fprintf(codeFile, "%d contents r%d, %d := contents b, %d\n", getInstruction(), currReg, lookup->data.offSet, $3->offset);
			}else{
				fprintf(codeFile, "%d contents r%d, %d := r%d\n", getInstruction(), currReg, lookup->data.offSet, currReg-1);
			}
		}
		lookup->data.inReg = $3->regNum;
	}else{
		if(lookup != NULL){
			lookup->data.value = $3->value;
			currReg = getRegister();
			fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
			fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
			int i = 1;
			while(i < d){
				printf("going back %d links....\n", i);
				fprintf(codeFile, "%d r%d := contents r%d, 2\n", getInstruction(), currReg, currReg);
				i = i + 1;
			}
			if($3->isNum == 0){
				fprintf(codeFile, "%d contents r%d, %d := contents b, %d\n", getInstruction(), currReg, lookup->data.offSet, $3->offset);
			}else{
				fprintf(codeFile, "%d contents r%d, %d := r%d\n", getInstruction(), currReg, lookup->data.offSet, currReg-1);
			}
		}
		lookup->data.inReg = $3->regNum;
	}
}
; 


loop_stmt : LOOP seq_of_stmts loop_exit ENDLOOP
{
	int startloop = insCtr;
}
;

loop_exit : EXIT ';'
{
	//fprintf(codeFile, "%d pc := %d)
}
| EXITWHEN expression ';'
|
;


if_stmt : IF expression THEN seq_of_stmts if_cont ENDIF
;

if_cont : ELSEIF expression THEN seq_of_stmts if_cont
| ELSE seq_of_stmts
| /*empty*/
;

raise_exc : RAISE ID;

procedure_call : proc_params

;

proc_params: identifier optional_params
{
	treeNode* find = parentSearch($1);
	int d;
	char *name;
	treeNode* lookup = walkBack($1, &d);
	if($2->isBool == 1){
		name = "boolean";
	}else{
		name = "integer";
	}
	if(strcmp(find->data.kind, "read_routine") == 0){
		fprintf(codeFile, "%d read_%s contents b, %d\n", getInstruction(), name, $2->offset);
	}else if(strcmp(find->data.kind, "write_routine") == 0){
		emitWrite($2, codeFile);
	}
}
| identifier
{
	//check if the proc. is in the scope
	int d;
	printf("THE STACK CTR IS %d\n", sCtr);
	treeNode* found = walkBack($1, &d);
	if(found != NULL){
		printf("The value of d is %d\n", d);
		//start to build AR for proc. call
		if((d == 1)||(d == 0)){ //dyn. link is main
			
			int currReg = getRegister();
			fprintf(codeFile, "%d r%d := b\n", getInstruction(), currReg);
			//THIS ADJUSTS THE NEW BASE OF THE AR
			fprintf(codeFile, "%d b := contents r%d, 0\n", getInstruction(), currReg);
			fprintf(codeFile, "%d contents b, 3 := r%d\n", getInstruction(), currReg); //DYN LINK
			
			
			
			
			if(d >= 1){
				printf("The depth is %d\n", d);
				fprintf(codeFile, "%d contents b, 2 := contents r%d, 2\n", getInstruction(), currReg);
				//Static Link is the same as the previous AR's static link.
			}else if(d == 0){
				fprintf(codeFile, "%d contents b, 2 := r%d\n", getInstruction(), currReg);
				//Static link is the same as the dynamic link
			}
			
			
			
			
			
			
			//FIX NEXT BASE
			currReg = getRegister();
			fprintf(codeFile, "%d r%d = ?\n", getInstruction(), currReg);
			fprintf(codeFile, "%d contents b, 0 := b + r%d\n", getInstruction(), currReg);
			//FIX RETURN ADDRESS
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
;

optional_params : '(' function_params ')'
{
	$$ = $2;
}
;

function_params : expression ',' function_params
{
	wrList = malloc(sizeof(struct writeNode));
	(*wrList).next = $3;
	(*wrList).rNum = $1->regNum;
	(*wrList).isBool = $1->isBool;
	(*wrList).offset = $1->offset;
	$$ = wrList;
}

| expression
{
	wrList = malloc(sizeof(struct writeNode));
	(*wrList).next = NULL;
	(*wrList).rNum = $1->regNum;
	(*wrList).isBool = $1->isBool;
	(*wrList).offset = $1->offset;
	$$ = wrList;
}
;


expression : relation
{
	$$ = $1;

}
| expression boolean_op relation
{
	int currReg = getRegister();
	int a;
	emitBoolInstruct($1, $3, $2, currReg, codeFile, &a);
	$$->regNum = currReg;
	$$->value = a;
}
;

relation : simple_expr
{
	$$ = $1;
}
| relation relational_op simple_expr
{
	int currReg = getRegister();
	int a;
	emitRelInstruct($1, $3, $2, currReg, codeFile, &a);
	$$->regNum = currReg;
	$$->value = a;
}	
;

simple_expr :
 term
{
	$$ = $1;
}
| simple_expr adding_op term
{
	if($2 == 1){
		$$->value = $1->value + $3->value;
	}else{
		$$->value = $1->value - $3->value;
	}
	
	if(($1->isNum == 0)&&($3->isNum == 0)){
	
		int regist = getRegister();
		
		if($3->inReg == 1){
			if($1->inReg == 1){
				fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
				if($2 == 1){
					fprintf(codeFile, " + ");
				}else{
					fprintf(codeFile, " - ");
				}
				fprintf(codeFile, "r%d\n", $3->regNum);
				$$->inReg = 1;
				$$->regNum = regist;
			}else{
				fprintf(codeFile, "%d r%d := contents b, %d", getInstruction(), regist, $1->offset);
				if($2 == 1){
					fprintf(codeFile, " + ");
				}else{
					fprintf(codeFile, " - ");
				}
				fprintf(codeFile, "r%d\n", $3->regNum);
				$$->inReg = 1;
				$$->regNum = regist;
			}
		}
		
		else if($1->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}
		
		else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), getRegister(), $1->offset);

			if($2 == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "contents b, %d\n", $3->offset);
			$$->inReg = 1;
			$$->regNum = regCt;
		}
		
		
		
		
	}else if(($1->isNum == 1)&&($3->isNum == 1)){
		int regist = getRegister();
		fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, $1->regNum);
		if($2 == 1){
			fprintf(codeFile, " + ");
			printf(" PLUS");
		}else{
			fprintf(codeFile, " - ");
			printf(" MINUS");
		}
		fprintf(codeFile, "r%d\n", $3->regNum);
		$$->inReg = 1;
		$$->regNum = regist;
		
			
	}else if(($1->isNum == 1)&&($3->isNum == 0)){
		int regist = getRegister();
		if($3->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "contents b, %d\n", $3->offset);
			$$->inReg = 1;
			$$->regNum = regist;
		}
	}else if(($1->isNum == 0)&&($3->isNum == 1)){
		int regist = getRegister();
		if($1->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), regist, $1->offset);
			if($2 == 1){
				fprintf(codeFile, " + ");
			}else{
				fprintf(codeFile, " - ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}
	}
}
;

term : factor
{
	$$ = $1;
	
}
| term multiplying_op factor
{
	if($2 == 1){
		$$->value = $1->value * $3->value;
		
	}else{
		$$->value = $1->value / $3->value;
		
	}
	if(($1->isNum == 0)&&($3->isNum == 0)){
	
		int regist = getRegister();
		
		if($3->inReg == 1){
			if($1->inReg == 1){
				fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
				if($2 == 1){
					fprintf(codeFile, " * ");
				}else{
					fprintf(codeFile, " / ");
				}
				fprintf(codeFile, "r%d\n", $3->regNum);
				$$->inReg = 1;
				$$->regNum = regist;
			}else{
				fprintf(codeFile, "%d r%d := contents b, %d", getInstruction(), regist, $1->offset);
				if($2 == 1){
					fprintf(codeFile, " * ");
				}else{
					fprintf(codeFile, " / ");
				}
				fprintf(codeFile, "r%d\n", $3->regNum);
				$$->inReg = 1;
				$$->regNum = regist;
			}
		}
		
		else if($1->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}
		
		else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), regist, $1->offset);

			if($2 == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "contents b, %d\n", $3->offset);
			$$->inReg = 1;
			$$->regNum = regist;
		}
		
		
		
		
	}else if(($1->isNum == 1)&&($3->isNum == 1)){
		int regist = getRegister();
		fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, $1->regNum);
		if($2 == 1){
			fprintf(codeFile, " * ");
			printf(" PLUS");
		}else{
			fprintf(codeFile, " / ");
			printf(" MINUS");
		}
		fprintf(codeFile, "r%d\n", $3->regNum);
		$$->inReg = 1;
		$$->regNum = regist;
		
			
	}else if(($1->isNum == 1)&&($3->isNum == 0)){
		int regist = getRegister();
		if($3->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := r%d",getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "contents b, %d\n", $3->offset);
			$$->inReg = 1;
			$$->regNum = regist;
		}
	}else if(($1->isNum == 0)&&($3->isNum == 1)){
		int regist = getRegister();
		if($1->inReg == 1){
			fprintf(codeFile, "%d r%d := r%d", getInstruction(), regist, $1->regNum);
			if($2 == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}else{
			fprintf(codeFile, "%d r%d := contents b, %d",getInstruction(), regist, $1->offset);
			if($2 == 1){
				fprintf(codeFile, " * ");
			}else{
				fprintf(codeFile, " / ");
			}
			fprintf(codeFile, "r%d\n", $3->regNum);
			$$->inReg = 1;
			$$->regNum = regist;
		}
	}
}
;


factor : primary
{
	$$ = $1;
	
}
| primary EXP primary
{
	$$ = $1;
}
| NOT primary
{
	$$ = (semInfo*)malloc(sizeof(semInfo*));
	currReg = getRegister();
	fprintf(codeFile, "%d r%d := not ", getInstruction(), currReg);
	$$->inReg = 1;
	$$->regNum = currReg;
	fprintf(codeFile, "r%d\n", $2->regNum);
	if($2->value == 0){
		$$->value = 1;
	}else{
		$$->value = 0;
	}
}
| '-' primary
{
	$$ = (semInfo*)malloc(sizeof(semInfo*));
	$$ = semConstruct();
	int neg = 0 - $2->value;
	$$->value = neg;
	$$->isVar = 0;
	$$->inReg = 1;
	$$->regNum = getRegister();
	$$->isArray = 0;
	$$->isNum = 1;
	fprintf(codeFile, "%d r%d := - r%d\n", getInstruction(), $$->regNum, $2->regNum);
}

;

primary : NUMBER
{
	$$ = (semInfo*)malloc(sizeof(semInfo*));
	$$ = semConstruct();
	emitImmData($$, $1, codeFile);
	$$->isNum = 1;
	
}
| identifier
{
	$$ = (semInfo*)malloc(sizeof(treeNode*));
	$$ = semConstruct();
	int d;
	treeNode* lookup = walkBack($1, &d);
	if(lookup != NULL){
		if(strcmp(lookup->data.name, "false") == 0){
				printf("FOUND A FALSE\n");
				$$->value = 0;
				$$->isBool = 1;
		}else if(strcmp(lookup->data.name, "true") == 0){
				printf("FOUND A TRUE\n");
				lookup->data.value = 1;
				$$->isBool = 1;
		}
		printf("Value of %s is %d\n", lookup->data.name, lookup->data.value);
		if(strcmp(lookup->data.kind, "boolean") == 0){
			printf("FOUND A BOOLEAN\n");
			$$->isBool = 1;
			treeNode* bool = parentSearch($1);
			printf("Found a %s\n", $1);
			
			$$->isLocal = 1;
			$$->regNum = lookup->data.inReg;
			$$->offset = lookup->data.offSet;
			$$->depth = d;
		}else{
			$$->value = lookup->data.value;
			$$->isLocal = 1;
			$$->regNum = lookup->data.inReg;
			$$->offset = lookup->data.offSet;
			$$->depth = d;
		}
	}else{
		printf("OOPS");
	}
	$$->isNum = 0;
	$$->isLocal = 0;
}
| '(' expression ')'
{
$$ = (semInfo*)malloc(sizeof(semInfo*));
}
;

boolean_op : AND
{
	$$ = 0;
}
| OR
{
	$$ = 1;
}
;

relational_op : EQ { $$ = 1; }
| NEQ { $$ = 2; }
| LT { $$ = 3; }
| LTE { $$ = 4; }
| GT { $$ = 5; }
| GTE{ $$ = 6; }
;

adding_op : '+'
{
	$$ = 1;
}
| '-'
{
	$$ = -1;
}
;

multiplying_op : '*'
{
	$$ = 1;
}
| '/'
{
	$$ = -1;
}
;

/*optional_actual_parameter_part : '(' actual_parameter ')'*/
/*;*/

/*optional_assign : ASSIGN expression*/
/*|*/
/*;*/


/*actual_parameter : expression ',' actual_parameter*/
/*| expression*/
/*;*/

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
