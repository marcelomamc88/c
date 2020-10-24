#include <stdio.h>

#define MAX 6

void selectionsort(int *vetor);
void print(int *vetor);

void main (void){
    int vetor[MAX] = {5,6,2,3,4,1};

    print(vetor);

    selectionsort(vetor);
}

void selectionsort(int *vetor){
    int temp;
    int posMenor;

    for (int i=0; i<MAX-1; ++i){
        posMenor = i;

        for (int j=i+1; j<MAX; ++j){
            if (vetor[j] < vetor[posMenor]){
                posMenor = j;
            }
        }

        temp = vetor[posMenor];
        vetor[posMenor] = vetor[i];
        vetor[i] = temp;

        print(vetor);
    }
}

void print(int *vetor){
    printf("\r\n");

    for (int i = 0; i<MAX; ++i){
        printf("%d, ", vetor[i]);
    }
}

