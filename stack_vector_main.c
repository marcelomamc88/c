#include <stdio.h>
#include "stack_vector.c"

void main(void){
    stack s;

    createStack(&s);

    push(5, &s);
    push(10, &s);
    push(19, &s);
    push(100, &s);
    print(&s);

    printf("\r\nTOP: %d", top(&s));

    printf("\r\nPOP: %d", pop(&s));

    print(&s);

    printf("\r\nsize: %d - top: %d", size(&s), top(&s));

    printf("\r\nPOP: %d", pop(&s));

    print(&s);

    printf("\r\nPOP: %d", pop(&s));

    print(&s);

    printf("\r\nPOP: %d", pop(&s));

    print(&s);
}