//Alex Voitik
//symbol_table.h
//Last Edit: 10/30/2016

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

treeNode* parentSearch(char* type);

void set_Type( idnodeptr list, char *typeName, int *num)
{
    treeNode *newInsert;
    treeNode *parent;
    while(list != NULL){
        int added = add(list->name);
        if(added != -1){
            newInsert = search(list->name, stack[sCtr-1].root);
            parent = parentSearch(typeName);
			char *str = malloc(sizeof(typeName)+1);
            strcpy(str, typeName);
            newInsert->data.kind = str;
            int comp = strcmp(newInsert->data.kind, "array");
            if(parent != NULL){
                newInsert->data.parent_type = parent;
                newInsert->data.size = parent->data.size;
                if(comp == 0){
                    newInsert->data.offSet = parent->data.offSet;
                    offset += newInsert->data.size;
                }else{
                    newInsert->data.offSet = offset;
                    offset += newInsert->data.size;
                }
            }
        }
        list = list -> next;
        *num = *num + 1;
        newInsert = NULL;
        parent = NULL;
    }
}

treeNode* parentSearch(char *type){
    int i;
    treeNode* found = NULL;
    for (i = sCtr-1; i>=0; i--){
        treeNode *temp = stack[i].root;
        found = search(type, temp);
        if(found != NULL){
            return found;
        }
    }
    return NULL;
}
