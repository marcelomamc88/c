#include <stdio.h>

#define MAX 8

void mergesort(int i, int f);
void merge(int i, int m, int f);
void print();

int vetor[MAX] = {18,26,32,6,43,15,9,1};
int aux[MAX] = {};

void main (void){
    print();

    mergesort(0, MAX-1);

}

void mergesort(int i, int f){
    if (i < f){
        int m = (i+f)/2;
        mergesort(i,m);
        mergesort(m+1, f);
        merge(i,m,f);
    }
}

void merge(int i, int m, int f){
    int iAux = i;
    int iEsq = i;
    int iDir = m+1;

    while(iEsq <= m && iDir <= f){
        if (vetor[iEsq] < vetor[iDir]){
            aux[iAux++] = vetor[iEsq++];
        }else{
            aux[iAux++] = vetor[iDir++];
        }
    }
    while(iEsq<=m){
        aux[iAux++] = vetor[iEsq++];
    }
    while(iDir<=f){
        aux[iAux++] = vetor[iDir++];
    }
    for(int j=i; j<=f;++j){
        vetor[j] = aux[j];
    }
    print();
}

void print(){
    printf("\r\n");

    for (int i = 0; i<MAX; ++i){
        printf("%d, ", vetor[i]);
    }
}

