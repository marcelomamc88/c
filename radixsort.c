#include <stdio.h>
#include "queue_struct.c"

#define MAX 8
#define BASE 10
#define DIGITOS 3

void print_vector();
void radixsort();
queue* createQueues();

int vetor[MAX] = {18,26,32,6,43,15,9,1};


void main (void){
    print_vector();

    radixsort();

    print_vector();
}

void radixsort(){
    queue *queues = createQueues();
    int index = 0;

    for (int i=0, fator = 1; i<DIGITOS; fator *= BASE, ++i){
        for(int j=0; j<MAX; ++j){
            index = (vetor[j]/fator)%BASE;
            enqueue(vetor[j], &queues[index]);
        }
        for(int q=0, j=0; q<BASE; ++q){
            while (!isEmpty(&queues[q])){
                vetor[j++] = dequeue(&queues[q])->value;
            }
        }
    }
}

queue* createQueues(){
    queue *q = (queue *) malloc(BASE*sizeof(queue*));

    for (int i = 0; i<BASE; ++i){
        q[i] = *createQueue();
    }

    return q;
}

void print_vector(){
    printf("\r\n");

    for (int i = 0; i<MAX; ++i){
        printf("%d, ", vetor[i]);
    }
}

