#include <stdio.h>
#include <malloc.h>

typedef struct t_element element;
struct t_element{
    int value;
    element *next;
};

typedef struct t_stack stack;
struct t_stack{
    int size;
    element *top;
};

/* ok */ stack* createStack();
/* ok */ element* createElement();
/* ok */ void push(int value, stack *s);
/* ok */ element* top(stack *s);
element* pop(stack *s);
/* ok */ int size(stack *s);
/* ok */ int isEmpty(stack *s);
/* ok */ void print(stack *s);

void main(void){
    stack *s = createStack();

    push(5, s);
    push(10, s);
    push(525, s);

    print(s);

    printf("\r\nPOP: %d", pop(s)->value);

    print(s);
}

element* pop(stack *s){
    if (isEmpty(s)) return NULL;

    element *e = s->top;
    s->top = e->next;
    --s->size;

    return e;
}

element* top(stack *s){
    if (isEmpty(s)) return NULL;

    return s->top;
}

void push(int value, stack *s){
    element *e = createElement();

    e->value = value;
    e->next = s->top;
    s->top = e;
    ++s->size;
}

stack* createStack(){
    stack *s = (stack *) malloc(sizeof(stack));

    s->size = 0;
    s->top = NULL;

    return s;
}

element* createElement(){
    element *e = (element *) malloc(sizeof(element));

    e->value = -1;
    e->next = NULL;

    return e;
}

void print(stack *s){

    printf("\r\nSTACK PRINT (%d)", s->size);

    if (isEmpty(s)) return;

    element *e = top(s);

    for (int i=0 ; i<s->size; i++){
        printf("\r\n- %d", e->value);

        e = e->next;
    }

    printf("\r\n***********");
}

int isEmpty(stack *s){
    return s->size == 0;
}