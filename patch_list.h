//Alex Voitik
//Patch_list.h


struct patchList {
   int data;
   int lineNo;
   struct patchList *next;
};

struct patchList *head = NULL;
struct patchList *current = NULL;


void printList(FILE *f) {
   struct patchList *ptr = head;
   while(ptr != NULL) {
      fprintf(f, "Line %d : %d\n",ptr->lineNo, ptr->data);
      ptr = ptr->next;
   }
}

int length() {
   int length = 0;
   struct patchList *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

void sort() {

   int i, j, k, tempKey, tempData;
   struct patchList *current;
   struct patchList *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   
		
         if ( current->lineNo > next->lineNo) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->lineNo;
            current->lineNo = next->lineNo;
            next->lineNo = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void insertPatch(int lineNo, int data) {

   struct patchList *link = (struct patchList*) malloc(sizeof(struct patchList));
	
   link->lineNo = lineNo;
   link->data = data;
   link->next = head;
   head = link;
   sort();
}

void integratePatchList(){
    char ch;
    int num = 0;
    struct patchList *ptr = head;
    FILE *input = fopen("code.txt", "r");
    FILE *output = fopen("integrated.txt","w");
    while(!feof(input)){
        ch = fgetc(input);
        if(ch == '?'){
            num = num + 1;
            fprintf(output, "%d",ptr->data);
            ptr = ptr->next;
        }else if(ch == 'P'){
            break;
        }else if(ch != '?'){
            fputc(ch, output);
        }
    }
}
