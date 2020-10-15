#include <stdio.h>

void main(void){
    int *p; //definindo um ponteiro para int.

    int a = 5;

    p = &a;

    printf("%d", *p);
}