#include <stdio.h>
#include "stack_struct.c"

void dec_to_bin(stack *s, int number);
void print_bin(stack *s);

void main(void){
    stack *s = createStack();
    int number = 43;

    dec_to_bin(s, number);
    print_bin(s);
}

void dec_to_bin(stack *s, int number){
    while (number >= 2){

        push(number%2, s);
        number /= 2;
    }

    if (number <= 1) push(number, s);
}

void print_bin(stack *s){
    while(!isEmpty(s)){
        printf("%d", top(s)->value);
        pop(s);
    }
}