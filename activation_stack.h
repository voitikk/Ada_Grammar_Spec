struct semInfo{
    int value;
    int regNum;
    int isLocal;
    int inReg;
    int baseReg;
    int iVal;
    int isVar;
    int isArray;
    int isBool;
    int offset;
    int isNum;
    int depth;
    struct semInfo *next;
    struct semInfo *indexSem;
};

typedef struct semInfo semInfo;

semInfo* semConstruct(){
    semInfo *init = (semInfo*)malloc(sizeof(semInfo*));
    init->value = 0;
    init->regNum = 0;
    init->offset = 0;
    init->isLocal = 0;
    init->inReg = 0;
    init->iVal = 0;
    init->isBool = 0;
    init->baseReg = 0;
    init->isArray = 0;
    init->isVar = 0;
    return init;
}

void create_prologue(FILE *f){

    fprintf(f, "0 b := ?\n");
    //need to patch
    fprintf(f, "1 contents b, 0 := ?\n");
    //need to patch
    fprintf(f, "2 contents b, 1 := 4\n");
    fprintf(f, "3 pc := ?\n");
    //need to patch
    fprintf(f, "4 halt\n");
    insCtr = 5;
}

int getRegister(){
    return ++regCt;
}

int getInstruction(){
    return insCtr++;
}

treeNode* walkBack(char *var, int *depth){
    treeNode *found = NULL;
    int i;
    for(i = sCtr-1; i >=0; i--){
        treeNode *temp = stack[i].root;
        found = search(var, temp);
        if(found != NULL){
            *depth = sCtr-1-i;
            return found;
            break;
        }
    }
    if(found == NULL){
        printf("NOT FOUND");
        return found;
    }
}
    
    
    
    