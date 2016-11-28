/*************************

Alex Voitik
struct_def.h
last edit: 10/30/2016
**************************/

typedef struct idnode {
	char *name;
	struct idnode *next;

} *idnodeptr;

idnodeptr aList = NULL;

void print_list(idnodeptr node){
	
	idnodeptr check = node;
	while(check != NULL){
		if(check -> name != NULL){
			printf("%s ", check -> name);
		}
	check = check->next;
	}
}

