#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3

int sum (int v[][TAMANHO], int n){
    if (n == 0) return 0;

    return sum(v, n-1) + v[n-1][n-1];
}

void main(void) {
    int v[][TAMANHO] = {{5,2,3},{3,1,3},{3,1,4}};

    printf("%d" , sum(v, TAMANHO));
}


