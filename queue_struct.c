#include <stdio.h>
#include <malloc.h>

typedef struct t_node node;
struct t_node{
    int value;
    node *next;
};

typedef struct t_queue queue;
struct t_queue{
    node *head;
    node *tail;
};


/* ok */ queue* createQueue();
/* ok */ node* createNode(int value);
/* ok */ void enqueue(int value, queue *q);
/* ok */ node* dequeue(queue *q);
/* ok */ int isEmpty(queue *q);
/* ok */ void print(queue *q);
/* ok */ node* front(queue *q);
/* ok */ node* rear(queue *q);


void main(void){
    queue *q = createQueue();

    enqueue(10, q);
    enqueue(20, q);
    enqueue(40, q);
    enqueue(50, q);
    print(q);

    dequeue(q);
    dequeue(q);

    print(q);
}

queue* createQueue(){
    queue *q = (queue *) malloc(sizeof(queue));

    q->head = NULL;
    q->tail = NULL;
}

node* createNode(int value){
    node *n = (node *) malloc(sizeof(node));

    n->value = value;
    n->next = NULL;

    return n;
}

int isEmpty(queue *q){
    return q->head == NULL;
}

void enqueue(int value, queue *q){
    node *n = createNode(value);

    if (isEmpty(q)){
        q->head = n;
    }else{
        q->tail->next = n;
    }

    q->tail = n;
}

node* dequeue(queue *q){
    if (isEmpty(q)) return NULL;

    node *head = q->head;

    q->head = head->next;

    return head;
}

void print(queue *q){
    if (isEmpty(q)){
        printf("\r\nFILA VAZIA");
        return;
    }

    printf("\r\n%d, ", q->head->value);

    node *next = q->head->next;

    while(next != NULL){
        printf("%d, ", next->value);

        next = next->next;
    }
}

node* front(queue *q){
    return q->head;
}

node* rear(queue *q){
    return q->tail;
}