#include "linked_list_struct.c"

#define HASH_TABLE 17

linkedList* createHashTable();
void pushHashTable(linkedList *ht, int value);
void printHashTable(linkedList *ht);
void search(linkedList *ht, int value);

void main(void){
    linkedList *ht = createHashTable();

    //gera 500 numeros no intervalo de 0 - 700
    for (int i=0; i<500; ++i){
        pushHashTable(ht, rand() % 700 + 1);
    }

    printHashTable(ht);

    search(ht, 525);
}

linkedList* createHashTable(){
    linkedList *ht = (linkedList *) malloc(HASH_TABLE * sizeof(linkedList*));

    linkedList ll;

    for (int i=0; i<HASH_TABLE; ++i){
        createList(&ll);

        ht[i] = ll;
    }

    return ht;
}

void pushHashTable(linkedList *ht, int value){
    push(&ht[value % HASH_TABLE], value);
}

void printHashTable(linkedList *ht){
    printf("\r\n****** PRINT HASH TABLE WITH %d ENTRIES ******", HASH_TABLE);

    for (int i=0; i<HASH_TABLE; ++i){
        printf("\r\n%d:",i);
        print(&ht[i]);
    }

    printf("\r\n****** END HASH TABLE ****** ");
}

void search(linkedList *ht, int value){
    int position = indexOfByValue(&ht[value % HASH_TABLE], value);

    if (position < 0){
        printf("\r\nVALUE %d not found");
    }else {
        printf("\r\nVALUE %d found - ENTRY: %d | POSITION: %d", value, (value % HASH_TABLE), position);
    }
}