#include <stdio.h>
#include <malloc.h>

#define MAX_TAM 10

typedef struct t_linkedlist linkedList;
struct t_linkedlist{
    int *elements;
    int last;
};

/* ok */ void push(linkedList *list, int number);
/* ok */ void insert(linkedList *list, int number, int position);
/* ok */ int pop(linkedList *list); //informa o head
/* ok */ void erase(linkedList *list, int position); //remove um no
/* ok */ void clear(linkedList *list); //limpa lista
/* ok */ int indexOf(linkedList *list, int number); //indice de um no
/* ok */ int isEmpty(linkedList *list);
/* ok */ int isFull(linkedList *list);
/* ok */ void createList(linkedList *list);
/* ok */ void print(linkedList *list);


void main (void){
    linkedList ll;

    createList(&ll);

    print(&ll);

    push(&ll, 5);
    push(&ll, 9);

    print(&ll);

    insert(&ll, 6, 1);

    print(&ll);

    insert(&ll, 4, 0);

    print(&ll);

    printf("\r\nPOP: %d", pop(&ll));

    printf("\r\nINDEXOF 6: %d", indexOf(&ll, 5));

    printf("\r\nLast: %d", ll.last);
    erase(&ll, 2);
    printf("\r\nLast: %d", ll.last);

    print(&ll);

    clear(&ll);

    print(&ll);

}

void clear(linkedList *list){
    list->last = 0;
}

void erase(linkedList *list, int position){
    if (isEmpty(list)) return;

    for (int i=position; i<list->last; ++i){
        list->elements[i] = list->elements[i+1];
    }

    --list->last;
}

int indexOf(linkedList *list, int number){
    if (isEmpty(list)) return -1;

    for (int i=0 ; i < list->last; i++){
        if (list->elements[i] == number) return i;
    }

    return -1;
}

int pop(linkedList *list){
    if (isEmpty(list)) return -1;

    return list->elements[0];
}

void insert(linkedList *list, int number, int position){
    if (isFull(list)){
        printf("\r\n%s", "Lista Cheia");
        return;
    }

    if (position >= MAX_TAM || position > list->last){
        printf("\r\n%s", "Não é possível atribuir nesta posição");
        return;
    }

    for (int i=list->last ; i>=position; --i){
        list->elements[i] = list->elements[i-1];
    }

    list->elements[position] = number;
    ++list->last;
}

void push(linkedList *list, int number){
    if (isFull(list)){
        printf("\r\n%s", "Lista Cheia");
        return;
    }

    list->elements[list->last] = number;
    ++list->last;
}

void createList(linkedList *list){
    list->elements = (int *) malloc(MAX_TAM * sizeof(int));
    list->last = 0;
}

int isEmpty(linkedList *list){
    return list->last == 0;
}

int isFull(linkedList *list){
    return list->last == MAX_TAM;
}

void print(linkedList *list){
    if (isEmpty(list)){
        printf("\r\n%s", "Lista Vazia");
        return;
    }

    printf("\r\n");

    for (int i=0 ; i<list->last; ++i){
        printf("%d, ", list->elements[i]);
    }
}

