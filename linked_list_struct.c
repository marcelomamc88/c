#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct t_node node;
struct t_node{
    int number;
    node *next;
};

typedef struct t_linkedlist linkedList;
struct t_linkedlist{
    node *head;
    int size;
};

/* ok */ node* push(linkedList *list, int number);
/* ok */ node* insert(linkedList *list, int number, int position);
/* ok */ node* pop(linkedList *list); //informa o head
/* ok */ void erase(linkedList *list, int position); //remove um no
/* ok */ void clear(linkedList *list); //limpa lista
/* ok */ int indexOf(linkedList *list, node *noRef); //indice de um no
/* ok */ node* atPos(linkedList *ll, int position); //node em uma posicao
node *min(linkedList *list, int position); //menor valor a partir de posicao
node *max(linkedList *list, int position); //maior valor a partir de posicao
/* ok */ void xchgNodes(linkedList *list, node *no_a, node *no_b); //troca posicoes dos nos
void sort(linkedList *list);
/* ok */ int isEmpty(linkedList *list);
/* ok */ void createList(linkedList *list);
/* ok */ node* createNode(int number);
/* ok */ node* prevNode(linkedList *list, node *noRef);
/* ok */ void print(linkedList *list);
/* ok */ void printNode(node *no);


void main (void){
    linkedList ll;

    createList(&ll);
    printf("is empty? %d \r\n", isEmpty(&ll));

    push(&ll, 10); //3
    push(&ll, 30); //2
    push(&ll, 50); //1

    print(&ll);

    insert(&ll, 20, 3);
    push(&ll, 100);

    print(&ll);

    xchgNodes(&ll, atPos(&ll, 3), atPos(&ll, 5));

    print(&ll);

    erase(&ll, 5);

    print(&ll);

    clear(&ll);

    print(&ll);

}

node* pop(linkedList *list){
    if (isEmpty(list)) return NULL;

    return list->head;
}

void erase(linkedList *list, int position){
    if (isEmpty(list)) return;

    node *current = atPos(list, position);

    if (position == 1){
        list->head = current->next;

        free(current);
    }else{
        node *previous = atPos(list, position - 1);
        previous->next = current->next;

        free(current);
    }

    --list->size;

    return;
}

void clear(linkedList *list){

    node *noh = list->head;

    for (int i=1; i <= list->size; ++i){
        node *next = noh->next;

        free(noh);

        noh = next;
    }
    free(list);
    list = NULL;
}

node* prevNode(linkedList *list, node *noRef){

    if (isEmpty(list)) return NULL;

    int idxNo = indexOf(list, noRef);

    if (idxNo == 1) return NULL;

    node *prevNoh = atPos(list, idxNo-1);

    return prevNoh;
}

void createList(linkedList *list){
    list->head = (node *) malloc(sizeof(node));

    list->head = NULL;
    list->size = 0;
}

node* createNode(int number){
    node* noh = (node *) malloc(sizeof(node));

    noh->number = number;
    noh->next = NULL;

    return noh;
}

void xchgNodes(linkedList *list, node *no_a, node *no_b){

    if (isEmpty(list)) return;

    node *prev_a = prevNode(list, no_a);
    node *prev_b = prevNode(list, no_b);

    node *next_b = no_b->next;

    if (abs(indexOf(list, no_a) - indexOf(list, no_b)) == 1){
        if (indexOf(list, no_a) == 1){
            list->head = no_b;
        }else{
            prev_a->next = no_b;
        }

        no_b->next = no_a;
    }else{

        if (indexOf(list, no_a) == 1){
            list->head = no_b;
        }else{
            prev_a->next = no_b;
        }
        prev_b->next = no_a;

        no_b->next = no_a->next;
    }

    no_a->next = next_b;
}

node* push(linkedList *list, int number){
    node *newNoh = createNode(number);

    node *head = list->head;

    newNoh->next = head;
    list->head = newNoh;
    ++list->size;

    return newNoh;
}

node* insert(linkedList *list, int number, int position){

    node *newNoh = createNode(number);

    if (isEmpty(list)){
        list->head = newNoh;
    }else{
        node *noh = atPos(list, position);

        node *prev = prevNode(list, noh);
        prev->next = newNoh;
        newNoh->next = noh;
    }

    ++list->size;

    return newNoh;
}

node* atPos(linkedList *ll, int position){
    if (position > ll->size || position == 0) return NULL;

    node *noh = ll->head;

    if (position == 1) return noh;

    for (int i = 2; i<=position; ++i){
        noh = noh->next;
    }
    return noh;
}

int indexOf(linkedList *list, node *noRef){

    if (isEmpty(list)) return -1;

    node *head = list->head;

    if (noRef == head) return 1;

    node *no = head->next;

    for (int i = 2; i<=list->size; ++i){
        if (no == noRef) return i;

        no = no->next;
    }

    return -1;
}

int isEmpty(linkedList *list){
    return list->size == 0;
}

void print(linkedList *list){
    node *noh = list->head;

    printf("\r\n %d, ", noh->number);

    for (int i = 2; i<=list->size; ++i){
        noh = noh->next;

        printf("%d, ", noh->number);
    }
}

void printNode(node *no){
    printf("\r\n %d \r\n", no->number);
}