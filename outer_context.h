	/* Alex Voitik           */
	/* outer_context         */
	/* Last Edit: 10/29/2016 */
    
void pushOuterContextElement(char *name, char *kind);

void outerContext() {
    push_tree("Outer Context");
    pushOuterContextElement("integer", "type");
    pushOuterContextElement("boolean", "type");
    pushOuterContextElement("false", "value");
    pushOuterContextElement("maxint", "value");
    pushOuterContextElement("true", "value");
    pushOuterContextElement("read", "read_routine");
    pushOuterContextElement("write", "write_routine");
    printTree(stack[ sCtr-1 ].root);
}

void pushOuterContextElement(char *name, char *kind){
    Insert( name, &( stack[ sCtr-1 ].root ) );
    treeNode *newCBlock = search( name, stack[ sCtr-1 ].root );
    char *str = malloc( sizeof( kind )+1);
    strcpy(str, kind);
    newCBlock->data.kind = str;
    newCBlock->data.size = 1;
}
