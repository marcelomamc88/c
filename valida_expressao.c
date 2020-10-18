#include <stdio.h>
#include <string.h>
#include "stack_struct.c"

int isCharOpening(char c, stack *s);
int isBalanced(char c, stack *s);

void main (void){
    //char* expression = "{()})";
    stack *s = createStack();
    static const char expression[] = "{()[{{}}]}()";

    int i=0;
    while(expression[i]){
        isCharOpening(expression[i], s);

        isBalanced(expression[i], s);

        ++i;
    }

    if (s->size > 0){
        printf("Expressao Desbalanceada!");
    }else{
        printf("Expressao Balanceada!");
    }

    print(s);
}

int isCharOpening(char c, stack *s){
    switch (c) {
        case '{': push("{", s); return 1;
        case '[': push("[", s); return 1;
        case '(': push("(", s); return 1;
    }

    return 0;
}

int isBalanced(char c, stack *s){

    if (c != '}' && c != ']' && c != ')'){
        return 1;
    }

    if (isEmpty(s)){
        return 0;
    }

    if (c == '}'){
        if (*(top(s))->value != '{'){
            return 0;
        }

    }else if (c == ')'){
        if (*(top(s))->value != '('){
            return 0;
        }
    }else if (c == ']'){
        if (*(top(s))->value != '['){
            return 0;
        }
    }

    pop(s);
}
