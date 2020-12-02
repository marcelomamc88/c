#include <stdio.h>

#define MAX 6

void insertionsort(int *vetor);
void print(int *vetor);

void main (void){
    int vetor[MAX] = {34,8,64,51,32,21};

    print(vetor);

    insertionsort(vetor);
}

void insertionsort(int *vetor){

    int temp;

    for (int i=1; i<MAX; ++i){
        int reference = vetor[i];
        int j = i;
        for (j; j>0 && reference < vetor[j-1]; --j){
            vetor[j] = vetor[j-1];
        }
        vetor[j] = reference;
    }
}

void print(int *vetor){
    printf("\r\n");

    for (int i = 0; i<MAX; ++i){
        printf("%d, ", vetor[i]);
    }
}

