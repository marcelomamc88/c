#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct t_node{
    char caracter[10];
    struct t_node *next;
};



void main (void){
    struct t_node *node_1 = NULL;
    struct t_node *node_2 = NULL;

    node_1 = (struct t_node*) malloc(sizeof(struct t_node*));
    node_2 = (struct t_node*) malloc(sizeof(struct t_node*));

    strcpy(node_1->caracter, "Marcelo");
    strcpy(node_2->caracter, "MARIA");

    node_1->next = node_2;

    printf("%s", node_1->next->caracter);
}