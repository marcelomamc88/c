#include <stdio.h>

#define MAX 8

void bubblesort(int *vetor);
void print(int *vetor);

void main (void){
    int vetor[MAX] = {44,55,12,42,94,18,6,67};

    print(vetor);

    bubblesort(vetor);
}

void bubblesort(int *vetor){
    int temp;

    for (int i=0; i<MAX-1; ++i){
        for (int j=0; j<MAX-i; ++j){
            if (vetor[j] > vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }

        print(vetor);
    }
}

void print(int *vetor){
    printf("\r\n");

    for (int i = 0; i<MAX; ++i){
        printf("%d, ", vetor[i]);
    }
}

