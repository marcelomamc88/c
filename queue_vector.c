#include <stdio.h>
#include <malloc.h>

#define MAX_QUEUE 5

typedef struct t_queue queue;
struct t_queue{
    int *elements;
    int front;
    int rear;
};

/* ok */ queue* createQueue();
/* ok */ void enqueue(int number, queue *q);
/* ok */ int dequeue(queue *q);
/* ok */ int isEmpty(queue *q);
/* ok */ int isFull(queue *q);
/* ok */ void print(queue *q);
/* ok */ int first(queue *q);
/* ok */ int rear(queue *q);
/* ok */ int size(queue *q);
/* ok */ void print(queue *q);



void main (void){
    queue *q = createQueue();

    printf("\r\n****\r\nENQUEUE: 23");
    enqueue(23, q);
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nENQUEUE: 88");
    enqueue(88, q);
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nENQUEUE: 83");
    enqueue(83, q);
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nENQUEUE: 7");
    enqueue(7, q);
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nDEQUEUE: %d", dequeue(q));
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nENQUEUE: 93");
    enqueue(93, q);
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nDEQUEUE: %d", dequeue(q));
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\nENQUEUE: 135");
    enqueue(135, q);
    printf("\r\nSIZE: %d", size(q));
    print(q);

    printf("\r\n****\r\n%d FIRST ", first(q));
    printf("\r\n****\r\n%d REAR", rear(q));

}

queue* createQueue(){
    queue *q = (queue *) malloc(sizeof(queue));

    q->elements = (int *) malloc(MAX_QUEUE * sizeof(int));
    q->front = q->rear = 0;

    return q;
}

int isEmpty(queue *q){
    return q->front == q->rear;
}

int isFull(queue *q){
    return (q->rear+1)%MAX_QUEUE == q->front;
}

void enqueue(int number, queue *q){
    if (isFull(q)) return;

    q->elements[q->rear] = number;
    printf("\r\nREAR %d", q->rear);
    q->rear = (q->rear+1)%MAX_QUEUE;
}

int dequeue(queue *q){
    if (isEmpty(q)) return -1;

    int element = q->elements[q->front];

    q->front = (q->front+1)%MAX_QUEUE;

    return element;
}

void print(queue *q){
    printf("\r\n");

    for (int i = q->front; i < q->front+size(q); ++i){
        printf("%d:%d, ", i%MAX_QUEUE, q->elements[i%MAX_QUEUE]);
    }
}

int size(queue *q){
    return (MAX_QUEUE - q->front + q->rear) % MAX_QUEUE;
}

int first(queue *q){
    if (isEmpty(q)) return -1;

    return q->elements[q->front];
}

int rear(queue *q){
    if (isEmpty(q)) return -1;

    return q->elements[(q->rear-1) % MAX_QUEUE];
}