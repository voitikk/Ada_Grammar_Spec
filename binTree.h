/*

Alex Voitik
Compiler Construction
Stack of Binary Trees
Last Edit: 10/30/2016

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode treeNode;
typedef struct symbol_table_node symbol_table_node;
typedef struct node node;

struct symbol_table_node{
        char *name;
        char *kind;
        int size;
        treeNode *parent_type;
        int value;
        int ins_ctr;
        char *mode;
        treeNode *next;
        treeNode *component_type;
        int lower;
        int upper;
        int depth;
        int offSet;
        int ARsize;
        int inReg;
        int nextARsize;
        int begin;
};

struct treeNode{
        symbol_table_node data;
        struct treeNode *left;
        struct treeNode *right;
};

struct node{
        char *name;
        int begin;
        treeNode *root;
};

void push_tree( char* );
treeNode* search( char*, treeNode* );
void printTree(treeNode*);
void Insert(char*, treeNode**);
int add(char*);
void pop();

int sCtr = 0;
int insCtr = 0;
int offset = 4;
int beg_main = 0;
int regCt = 0;
node stack[1000];

void push_tree(char *name){
	printf("\nPushing new scope for %s\n", name);
	printf("***************************************************************\n");   
	if(sCtr < (999)){   
		stack[sCtr].root = NULL;
		char *str = malloc(sizeof(name)+1);
		strcpy(str, name);
		stack[sCtr].name = str;
        //stack[sCtr].root->data.size;
		sCtr++;
	}else{
        printf("The Stack is Full!");
	}
	printTree(stack[ sCtr-1 ].root);
}

void Insert(char *name, treeNode **temp){
	if(*temp == NULL){ 
		*temp = (treeNode*)malloc(sizeof(treeNode));
		(*temp) -> right = NULL;
		(*temp) -> left = NULL;
		char *str = malloc(sizeof(name)+1);
		strcpy(str, name);
		(*temp) -> data.name = str;
	}else{
		int comp = strncmp(name, (*temp)->data.name, 1000 );
		if (comp < 0) {
			Insert(name, &((*temp)->left));
		} else { 
			Insert(name, &((*temp)->right));
		}
	}
}

treeNode* search(char *name, treeNode *leaf) {
	if ( leaf != NULL ) {
		int comp = strcmp( name, leaf->data.name);
		if(comp < 0){
			return search( name, leaf->left);
		}else if(comp > 0) {
			return search(name, leaf->right); 
		}else{
			return leaf;
		}
	} 
	return NULL;
}


void printTree( treeNode *tree)
{
	if ( tree == NULL ) {
		return;
	}else{
        if(tree->data.parent_type != NULL){
                printTree(tree->left);
                printf("%s : %s - offset = %d : final value in scope = %d\n", tree->data.name, tree->data.parent_type->data.name, tree->data.offSet, tree->data.value);
                printTree(tree->right);
        }else {
                printTree(tree->left);
                printf("%s : %s\n", tree->data.name, tree->data.kind);
                printTree(tree->right);
        }
        
    }
    return;
}

void pop(){
	if(sCtr == 0){
		printf("ERROR: Stack Empty");
 	}else{
		sCtr--;
	}
}


treeNode* lookupSym(char *symbol){
        if(sCtr <=0){
                printf("Error: The stack is empty\n");
                return NULL;
        }
        char *location = "\0";
        int i;
        for (i = sCtr; i >= 0; i--){
                treeNode *found = search(symbol, stack[i-1].root);
                if(found != NULL){
                        location = stack[i-1].name;
                        int depth = sCtr - i;
                        found->data.depth = depth;
                        return found;
                }
        }
        if(location == "\0"){
                printf("Error: %s was not found\n", symbol);
                return NULL;
        }
}

int add(char *symbol){
	if(sCtr <= 0){
		printf("The stack is empty\n");
		return -1;
	}
	treeNode *found = search(symbol, stack[sCtr-1].root);
	if(found != NULL){
		printf("Error: Duplicate ID's\n");
		return -1;
	}else{
		Insert(symbol, &(stack[sCtr-1].root));
		return 0;
	}
}

