#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_tree tree;
struct t_tree{
    tree *root;
    tree *left;
    tree *right;
    int value;
};

#define TYPE_NAME "tree"


typedef struct t_node node;
struct t_node{
    tree value;
    node *next;
};

typedef struct t_queue queue;
struct t_queue{
    node *head;
    node *tail;
};

tree* createNodeTree(tree *root, int value);
void run_breadth_first_search(tree *root);
void run_pre_ordem_r(tree *root);
void run_in_ordem_r(tree *root);
void run_pos_ordem_r(tree *root);
queue* createQueue();
node* createNode(tree value);
void enqueue(tree value, queue *q);
node* dequeue(queue *q);
int isEmpty(queue *q);
void print(queue *q);
node* front(queue *q);
node* rear(queue *q);
const char* format();
int isComplete(tree *root, int level); //todas folhas tem mesma altura /// nao eh completa < 0 <= eh completa
int isBinarySearch(tree *root); //esq < raiz < dir
int isLeaf(tree *node);
tree* build_tree_1(); //binary search - nao completa
tree* build_tree_2(); //not binary search - nao completa
tree* build_tree_3(); //binary search - completa
tree* build_tree_4(); //binary search - nao completa
tree* build_tree_5(); //not binary search


void main(void){
    tree *root = build_tree_5();

    printf("BFS - Breadth First Search: ");
    run_breadth_first_search(root); //percurso em largura

    printf("\r\nPRE ORDEM: ");
    run_pre_ordem_r(root);

    printf("\r\nIN ORDEM: ");
    run_in_ordem_r(root);

    printf("\r\nPOS ORDEM: ");
    run_pos_ordem_r(root);

    printf("\r\nIS BINARY SEARCH?: %s", isBinarySearch(root) == 0 ? "NAO" : "SIM");

    printf("\r\nTREE : %s", isComplete(root, 0) < 0 ? "NAO COMPLETA" : "COMPLETA");

}

tree* createNodeTree(tree *root, int value){
    tree *n = (tree *) malloc(sizeof(tree));

    n->root = root;
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

//red
void run_pre_ordem_r(tree *root){
    printf("%d, ", root->value);

    if (root->left != NULL){
        run_pre_ordem_r(root->left);
    }

    if (root->right != NULL){
        run_pre_ordem_r(root->right);
    }
}

//erd
void run_in_ordem_r(tree *root){
    if (root->left != NULL){
        run_in_ordem_r(root->left);
    }

    printf("%d, ", root->value);

    if (root->right != NULL){
        run_in_ordem_r(root->right);
    }
}

//edr
void run_pos_ordem_r(tree *root){
    if (root->left != NULL){
        run_pos_ordem_r(root->left);
    }

    if (root->right != NULL){
        run_pos_ordem_r(root->right);
    }

    printf("%d, ", root->value);
}

void run_breadth_first_search(tree *root){

    queue *q = createQueue();

    enqueue(*root, q);

    while (!isEmpty(q)){
        node *n = dequeue(q);
        tree *root = &n->value;
        printf("%d, ", root->value);

        if (root->left != NULL) {
            enqueue(*root->left, q);
        }

        if (root->right != NULL){
            enqueue(*root->right, q);
        }
    }

}

// nao eh completa < 0 <= eh completa
int isComplete(tree *root, int level){

    if (root->left == NULL && root->right == NULL) return level;

    ++level;

    int level_left = level;
    int level_right = level;

    if (root->left != NULL) level_left = isComplete(root->left, level);
    if (root->right != NULL) level_right = isComplete(root->right, level);

    //se receber profundidade diferentes do ramo direito e esquerdo, ou se algum ramo mais profundo já esteja desbalanceado
    if (level_left != level_right || level_left  == -1 || level_right == -1) return -1;

    return level_left;

}

//red
int isBinarySearch(tree *node){

    if (isLeaf(node)) return 1;

    int binarySearch;
    binarySearch = 1;

    if (node->left != NULL){
        if (node->value < node->left->value) return 0;
    }

    if (node->right != NULL){
        if (node->value > node->right->value) return 0;
    }

    if (node->left != NULL){
        binarySearch = isBinarySearch(node->left);
        if (binarySearch == 0) return 0;
    }

    if (node->right != NULL){
        binarySearch = isBinarySearch(node->right);
        if (binarySearch == 0) return 0;
    }

    return binarySearch;



}

int isLeaf(tree *node){
    return node->left == NULL && node->right == NULL;
}


/************/
/** QUEUE **/
/***********/

queue* createQueue(){
    queue *q = (queue *) malloc(sizeof(queue));

    q->head = NULL;
    q->tail = NULL;
}

node* createNode(tree value){
    node *n = (node *) malloc(sizeof(node));

    n->value = value;
    n->next = NULL;

    return n;
}

int isEmpty(queue *q){
    return q->head == NULL;
}

void enqueue(tree value, queue *q){
    node *n = createNode(value);

    if (isEmpty(q)){
        q->head = n;
    }else{
        q->tail->next = n;
    }

    q->tail = n;
}

node* dequeue(queue *q){
    if (isEmpty(q)) return NULL;

    node *head = q->head;

    q->head = head->next;

    return head;
}

void print(queue *q){
    if (isEmpty(q)){
        printf("\r\nFILA VAZIA");
        return;
    }

    printf("\r\n");
    printf(format(), q->head->value.value);

    node *next = q->head->next;

    while(next != NULL){
        printf(format(), next->value.value);

        next = next->next;
    }
}

const char* format() {

    if (strcmp(TYPE_NAME, "float") == 0){
        return "%.2f, ";
    }else if(strcmp(TYPE_NAME, "char") == 0) {
        return "%s, ";
    }else{
        return "%d, ";
    }
}


node* front(queue *q){
    return q->head;
}

node* rear(queue *q){
    return q->tail;
}

/*
 Binary Search
                13
            ´         `
         10              25
       ´    `          ´     `
    2         12    20          31
                              ´
                            29
*/
tree* build_tree_1(){
    tree *root = createNodeTree(NULL, 13);

    root->left = createNodeTree(root, 10);
        root->left->left = createNodeTree(root->left, 2);
        root->left->right = createNodeTree(root->left, 12);
    root->right = createNodeTree(root, 25);
        root->right->left = createNodeTree(root, 20);
        root->right->right = createNodeTree(root, 31);
            root->right->right->left = createNodeTree(root, 29);

    return root;
}

/*
 Not Binary Search
                13
            ´         `
         10              25
       ´    `          ´     `
    11        12    20          31
                              ´
                            29
*/
tree* build_tree_2(){
    tree *root = createNodeTree(NULL, 13);

    root->left = createNodeTree(root, 10);
        root->left->left = createNodeTree(root->left, 11);
        root->left->right = createNodeTree(root->left, 12);
    root->right = createNodeTree(root, 25);
        root->right->left = createNodeTree(root, 20);
        root->right->right = createNodeTree(root, 31);
            root->right->right->left = createNodeTree(root, 29);

    return root;
}

/*
 Binary Search - completa
                13
            ´         `
         10              25
       ´    `          ´     `
    2         12    20          31
*/
tree* build_tree_3(){
    tree *root = createNodeTree(NULL, 13);

    root->left = createNodeTree(root, 10);
        root->left->left = createNodeTree(root->left, 2);
        root->left->right = createNodeTree(root->left, 12);
    root->right = createNodeTree(root, 25);
        root->right->left = createNodeTree(root, 20);
        root->right->right = createNodeTree(root, 31);

    return root;
}

/*
 Binary Search - nao completa
                13
            ´         `
         10              25
       ´    `
    2         12
*/
tree* build_tree_4(){
    tree *root = createNodeTree(NULL, 13);

    root->left = createNodeTree(root, 10);
        root->left->left = createNodeTree(root->left, 2);
        root->left->right = createNodeTree(root->left, 12);
    root->right = createNodeTree(root, 25);

    return root;
}

/*
 Not Binary Search
                13
            ´         `
         10              19
       ´    `          ´     `
    8         12    20          31
                              ´
                            29
*/
tree* build_tree_5(){
    tree *root = createNodeTree(NULL, 13);

    root->left = createNodeTree(root, 10);
        root->left->left = createNodeTree(root->left, 8);
        root->left->right = createNodeTree(root->left, 12);
    root->right = createNodeTree(root, 19);
        root->right->left = createNodeTree(root, 20);
        root->right->right = createNodeTree(root, 31);
        root->right->right->left = createNodeTree(root, 29);

    return root;
}