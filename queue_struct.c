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
    node *next;
};

typedef struct t_queue queue;
struct t_queue{
    node *head;
    node *tail;
    int size;
};


/* ok */ queue* createQueue();
/* ok */ node* createNode(TYPE value);
/* ok */ void enqueue(TYPE value, queue *q);
/* ok */ node* dequeue(queue *q);
/* ok */ int isEmpty(queue *q);
/* ok */ void print(queue *q);
/* ok */ node* front(queue *q);
/* ok */ node* rear(queue *q);
/* ok */ const char* format();
/* ok */ int size(queue *q);


queue* createQueue(){
    queue *q = (queue *) malloc(sizeof(queue));

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

node* createNode(TYPE value){
    node *n = (node *) malloc(sizeof(node));

    n->value = value;
    n->next = NULL;

    return n;
}

int isEmpty(queue *q){
    return q->head == NULL;
}

void enqueue(TYPE value, queue *q){
    node *n = createNode(value);

    if (isEmpty(q)){
        q->head = n;
    }else{
        q->tail->next = n;
    }

    q->tail = n;
    ++q->size;
}

node* dequeue(queue *q){
    if (isEmpty(q)) return NULL;

    node *head = q->head;

    q->head = head->next;
    --q->size;

    return head;
}

void print(queue *q){
    if (isEmpty(q)){
        printf("\r\nFILA VAZIA");
        return;
    }

    printf("\r\n");
    printf(format(), q->head->value);

    node *next = q->head->next;

    while(next != NULL){
        printf(format(), next->value);

        next = next->next;
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


node* front(queue *q){
    return q->head;
}

node* rear(queue *q){
    return q->tail;
}

int size(queue *q){
    return q->size;
}
