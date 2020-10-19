#include <stdio.h>
#include <malloc.h>
#include <string.h>

//***** CONFIGS *****
//TYPE_NAME: "int"|"float"|"char"
//typedef: int|float|char*
#define TYPE_NAME "int"
typedef int TYPE;
//***** CONFIGS *****

typedef struct t_node node;
struct t_node{
    TYPE value;
    node* next;
    node* previous;
};

typedef struct t_deque deque;
struct t_deque{
    node* first;
    node* last;
    int size;
};

/* ok */ deque* createDeque();
/* ok */ node* createNode(TYPE value);
/* ok */ void insertFirst(deque *d, TYPE value);
/* ok */ void insertLast(deque *d, TYPE value);
/* ok */ int isEmpty(deque *d);
/* ok */ node* first(deque *d);
/* ok */ node* last(deque *d);
/* ok */ int size(deque *d);
/* ok */ node* removeFirst(deque *d);
/* ok */ node* removeLast(deque *d);
/* ok */ void print(deque *d);
/* ok */ const char* format();

deque* createDeque(){
    deque *d = (deque *) malloc(sizeof(deque));

    d->size = 0;
    d->first = NULL;
    d->last = NULL;

    return d;
}

node* createNode(TYPE value){
    node *n = (node *) malloc(sizeof(node));

    n->value = value;
    n->next = NULL;
    n->previous = NULL;
}

void insertFirst(deque *d, TYPE value){
    node *n = createNode(value);

    if (!isEmpty(d)){
        d->first->previous = n;
    }else{
        d->last = n;
    }

    n->next = d->first;
    d->first = n;

    d->size++;
}

void insertLast(deque *d, TYPE value){
    node *n = createNode(value);

    if (isEmpty(d)){
        d->first = n;
    }else{
        n->previous = d->last;
        n->previous->next = n;
    }

    d->last = n;
    d->size++;
}

node* removeFirst(deque *d){
    if (isEmpty(d)) return NULL;

    node *n = d->first;

    d->first = n->next;
    free(d->first->previous);

    d->size--;

    return n;
}

node* removeLast(deque *d){
    if (isEmpty(d)) return NULL;

    node *n = d->last;

    if (d->size == 1){
        free(d->first);
        free(d->last);
    }else{
        d->last = d->last->previous;
        free(d->last->next);
    }

    d->size--;

    return n;
}

node* first(deque *d){
    if (isEmpty(d)) return NULL;

    return d->first;
}

node* last(deque *d){
    if (isEmpty(d)) return NULL;

    return d->last;
}

int isEmpty(deque *d){
    return d->size == 0;
}

void print(deque *d){
    if (isEmpty(d)) return;

    node *noh = d->first;

    printf("\r\n==> ");
    printf(format(), noh->value);

    while(noh = noh->next){
        printf(format(), noh->value);
    }
}

const char* format() {

    if (strcmp(TYPE_NAME, "float") == 0){
        return "%.2f, ";
    }else if(strcmp(TYPE_NAME, "char") == 0){
        return "%s, ";
    }else{
        return "%d, ";
    }
}