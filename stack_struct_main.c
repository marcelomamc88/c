#include <stdio.h>
#include "stack_struct.c"

void main(void){
    stack *s = createStack();

    push(5, s);
    push(10, s);
    push(525, s);

    print(s);

    printf("\r\nPOP:");
    printf(format(), pop(s)->value);

    print(s);
}