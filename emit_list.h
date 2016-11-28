typedef struct writeNode {
	int rNum;
    int isBool;
    int offset;
	struct writeNode *next;

} *writeNodeptr;

writeNodeptr wrList = NULL;


void emitImmData(semInfo *change, int value, FILE *f){
    change->value = value;
	change->isVar = 0;
	change->inReg = 1;
	change->regNum = getRegister();
	change->isArray = 0;
    printf("Stuffing %d into register %d\n", change->value, change->regNum);
    fprintf(f, "%d r%d := %d\n", getInstruction(), change->regNum, change->value);
}
void emitRelInstruct(semInfo *arg1, semInfo *arg2, int op, int reg, FILE *f, int *value){
    char *symb;
    if(op == 1){
        symb = "=";
        if(arg1->value == arg2->value){
            *value = 1;
        }else{
            *value = 0;
        }
    }else if(op == 2){
        symb = "/=";
        if(arg1->value != arg2->value){
            *value = 1;
        }else{
            *value = 0;
        }
    }else if(op == 3){
        symb = "<";
        if(arg1->value < arg2->value){
            *value = 1;
        }else{
            *value = 0;
        }
    }else if(op == 4){
        symb = "<=";
        if(arg1->value <= arg2->value){
            *value = 1;
        }else{
            *value = 0;
        }
    }else if(op == 5){
        symb = "<";
        if(arg1->value > arg2->value){
            *value = 1;
        }else{
            *value = 0;
        }
    }else if(op == 6){
        symb = "<=";
        if(arg1->value >= arg2->value){
            *value = 1;
        }else{
            *value = 0;
        }
    }
    if((op == 6)||(op == 5)){
        fprintf(f, "%d r%d := r%d %s r%d\n", getInstruction(), reg, arg2->regNum, symb, arg1->regNum);
    }else{
        fprintf(f, "%d r%d := r%d %s r%d\n", getInstruction(), reg, arg1->regNum, symb, arg2->regNum);
    }
	
}

void emitBoolInstruct(semInfo *arg1, semInfo *arg2, int op, int reg, FILE *f, int *value){
    char *symb;
    if(op == 0){
        symb = "and";
        *value = arg1->value && arg2->value;
    }else if(op == 1){
        symb = "or";
        *value = arg1->value || arg2->value;
    }
    if((arg1->regNum == 0)&&(arg2->regNum == 0)){
        fprintf(f, "%d r%d := contents b, %d %s contents b, %d\n", getInstruction(), reg, arg1->offset, symb, arg2->offset);
    }else{
        fprintf(f, "%d r%d := r%d %s r%d\n", getInstruction(), reg, arg1->regNum, symb, arg2->regNum);
    }
}

void emitWrite(writeNodeptr node, FILE *f){

	writeNodeptr check = node;
	while(check != NULL){
        if(check->rNum == 0){
            fprintf(f, "%d write contents b, %d\n", getInstruction(), check->offset);
        }else{
            fprintf(f, "%d write r%d\n", getInstruction(), check -> rNum);
        }
        check = check->next;
	}
}









