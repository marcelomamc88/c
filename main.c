#include <stdio.h>

void bitwise_operators(void){
    //shift right - divide por 2^1
    printf("54>>1: %d \r\n", 54>>1);

    //shift left - multiplica por 2^1
    printf("54<<1: %d", 54<<1);
}

void main() {
    bitwise_operators();
}