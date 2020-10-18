#include <stdio.h>
#include <malloc.h>

#define MAX_TAM 10

typedef struct t_stack stack;
struct t_stack{
    int *elements;
    int top;
};

/* ok */ void createStack(stack *s);
/* ok */ void push(int x, stack *s);
/* ok */ int pop(stack *s);
/* ok */ int top(stack *s);
/* ok */ int size(stack *s);
/* ok */ int isEmpty(stack *s);
/* ok */ int isFull(stack *s);
/* ok */ void print(stack *s);



void push(int x, stack *s){
    if (isFull(s)) return;

    if (size(s) == MAX_TAM) return;

    s->elements[++s->top] = x;
}

void createStack(stack *s){
    s->elements = (int *) malloc(MAX_TAM * sizeof(int));
    s->top = -1;
}

int top(stack *s){
    if (isEmpty(s)) return -1;

    return s->elements[s->top];
}

int pop(stack *s){
    if (isEmpty(s)) return -1;

    return s->elements[s->top--];
}

int isEmpty(stack *s){
    return s->top < 0;
}

int isFull(stack *s){
    return size(s) == MAX_TAM;
}

int size(stack *s){
    return s->top+1;
}

void print(stack *s){

    printf("\r\nSTACK PRINT (%d)", size(s));

    for (int i = size(s)-1; i>=0; --i){
        printf("\r\n- %d", s->elements[i]);
    }

    printf("\r\n***********");
}