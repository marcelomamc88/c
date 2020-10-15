#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct t_node node;
struct t_node{
    char caracter[1];
    node *next;
};

void main (void){
    node *node_1 = (node *) malloc(sizeof(node));
    node *node_2 = (node *) malloc(sizeof(node));

    strcpy(node_1->caracter, "(");
    strcpy(node_2->caracter, "{");

    node_1->next = node_2;

    printf("%s", node_1->caracter);
    printf("%s", node_1->next->caracter);
}