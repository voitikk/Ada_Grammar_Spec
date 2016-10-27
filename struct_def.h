/*************************

Alex Voitik
struct_def.h
last edit: 11/27/2016
**************************/

typedef struct idnode {
	char *name;
	struct idnode *next;

} *idnodeptr;

idnodeptr aList = NULL;

void print_list(idnodeptr node){
	if(node != NULL){
		printf("%s ", node -> name);
		while(node -> next != NULL){
			node = node -> next;
			printf("%s ", node -> name);
		}
	}
}
