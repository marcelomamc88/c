#include <stdio.h>
#include <malloc.h>
#include <math.h>

int isComplete(int *tree);
int isLeaf(int *tree, int value);
int isHeapMin(int *tree); //menor elemento na raiz (ou igual ao filho)
int isHeapMax(int *tree); //maior elemento na raiz (ou igual ao filho)
void run_breadth_first_search(int *tree);
void in_order(int *tree, int node); //erd
void pre_order(int *tree, int node); //red
void post_order(int *tree, int node); //edr
int parent(int *tree, int value);
int sequential_search_i(int *tree, int value);
int binary_search_r(int *tree, int value, int root);
int* generic_build_tree(int *elements, int size);
void print(int *tree);
int qty_nodes(int *tree);
int find_end(int *tree);
int has_child(int *tree, int value);
int get_left(int *tree, int value);
int get_right(int *tree, int value);
int sift_r(int *tree, int root, int n);
int sift_i(int *tree, int root, int n);
void heapsort(int *tree);
void build(int *tree);
int* build_tree1();
int* build_tree2();
int* build_tree3(); //para o build

/* FILA DE PRIORIDADE */
int fp_max_min(int *tree);
int fp_extract_max_min(int *tree);
int fp_insert(int *tree, int value);
int fp_modify(int *tree, int k, int x); //k posicao, x prioridade

void main(void){
    int *tree = build_tree2();

    printf("\r\nQTY NODES: %d", qty_nodes(tree));
    printf("\r\nVALUE 12 (NOT) FOUND. POSITION: %d (sequential search)", sequential_search_i(tree, 12));

    /*
     * tree1 nao eh um heap e o 29 é uma folha q nao estah mais à esquerda.
     * Embora o 29 exista na tree, o algoritmo não conseguirá encontrá-lo.
     * Para isso, seria necessaria implementar um HEAP.
    */
    printf("\r\nVALUE 12 (NOT) FOUND. POSITION: %d (binary search)", binary_search_r(tree, 1, 0));

    printf("\r\nIs complete? %d", isComplete(tree));

    printf("\r\n8 Is Leaf? %d", isLeaf(tree, 8));
    printf("\r\n1 Is Leaf? %d", isLeaf(tree, 1));

    run_breadth_first_search(tree);

    printf("\r\nParent 8 is %d", parent(tree, 8));
    printf("\r\nParent 9 is %d", parent(tree, 9));
    printf("\r\nParent 16 is %d", parent(tree, 16));

    printf("\r\nIs Heap de Minimo? %d", isHeapMin(tree));
    printf("\r\nIs Heap de Maximo? %d", isHeapMax(tree));

    printf("\r\nIn Order: ");
    in_order(tree, 0);

    printf("\r\nPre Order: ");
    pre_order(tree, 0);

    printf("\r\nPost Order: ");
    post_order(tree, 0);

    print(tree);

    printf("\r\nSift: ");
    sift_i(tree, 0, qty_nodes(tree));
    print(tree);

    printf("\r\nBuild");
    build(tree);
    print(tree);

    printf("\r\nEXTRACT MAX: %d", fp_extract_max_min(tree));
    print(tree);

    printf("\r\n\r\nHEAPSORT");
    int vetor_heapsort[6] = {3,1,7,2,4,-1};
    print(vetor_heapsort);
    heapsort(vetor_heapsort);
    print(vetor_heapsort);
}

/* FILA DE PRIORIDADE */
int fp_max_min(int *tree){
    if (qty_nodes(tree) == 0) return -1;

    return tree[0];
}

int fp_extract_max_min(int *tree){
    int pos_end = find_end(tree)-1;
    int aux = tree[0];
    tree[0] = tree[pos_end];
    tree[pos_end] = -1;

    sift_i(tree,0, qty_nodes(tree));

    return aux;
}

int fp_insert(int *tree, int value){
    
};
int fp_modify(int *tree, int k, int x); //k posicao, x prioridade

/* HEAPSORT */
void heapsort(int *tree){
    build(tree);

    int p_last_element = qty_nodes(tree)-1;

    int last_element;

    while (p_last_element != 0){
        last_element = tree[p_last_element];
        tree[p_last_element--] = tree[0];
        tree[0] = last_element;

        sift_r(tree,0, p_last_element);
    }
}

int sift_r(int *tree, int root, int end){
    int esq = 2*(root)+1;
    int dir = 2*(root+1);
    int maior = root;

    int aux;

    if (esq <= end && tree[esq] > tree[root]){
        maior = esq;
    }
    if (dir <= end && tree[dir] > tree[maior]){
        maior = dir;
    }
    if (root != maior){
        aux = tree[root];
        tree[root] = tree[maior];
        tree[maior] = aux;
        sift_r(tree, maior, end);
    }else{
        if (++root < end){
            sift_r(tree, root, end);
        }
    }
}

int sift_i(int *tree, int root, int n){
    int aux;

    while (root < n){
        int esq = 2*(root)+1;
        int dir = 2*(root+1);

        int maior = root;

        if (esq <= n && tree[esq] > tree[root]) {
            maior = esq;
        }
        if (dir <= n && tree[dir] > tree[maior]) {
            maior = dir;
        }
        if (maior != root) {
            aux = tree[root];
            tree[root] = tree[maior];
            tree[maior] = aux;
        }

        ++root;
    }
}

void build(int *tree){
    for (int i = qty_nodes(tree)/2; i>=0; --i){ //build retrocede na árvore e chama o sift para realizar as trocas avançando.
        sift_r(tree, i, qty_nodes(tree));
    }
}

//raiz menor ou igual aos filhos
int isHeapMin(int *tree){
    for (int i = 0; i<qty_nodes(tree) && !isLeaf(tree, tree[i]); ++i){
        if (tree[i] > get_left(tree, tree[i]) || tree[i] > get_right(tree, tree[i])) return 0;
    }

    return 1;
}

//raiz maior ou igual aos filhos
int isHeapMax(int *tree){
    for (int i = 0; i<qty_nodes(tree) && !isLeaf(tree, tree[i]); ++i){
        if (tree[i] < get_left(tree, tree[i]) || tree[i] < get_right(tree, tree[i])) return 0;
    }

    return 1;
}

//erd
void in_order(int *tree, int node){

    if (qty_nodes(tree) > 2*(node)+1)
        in_order(tree, (2*(node)+1));

    printf("%d, ", tree[node]);

    if (qty_nodes(tree) > 2*(node+1))
        in_order(tree, (2*(node+1)));
}

//red
void pre_order(int *tree, int node){

    printf("%d, ", tree[node]);

    if (qty_nodes(tree) > 2*(node)+1)
        pre_order(tree, (2*(node)+1));

    if (qty_nodes(tree) > 2*(node+1))
        pre_order(tree, (2*(node+1)));
}

//edr
void post_order(int *tree, int node){

    if (qty_nodes(tree) > 2*(node)+1)
        post_order(tree, (2*(node)+1));

    if (qty_nodes(tree) > 2*(node+1))
        post_order(tree, (2*(node+1)));

    printf("%d, ", tree[node]);
}

void run_breadth_first_search(int *tree){
    printf("\r\nBREATH FIRST SEARCH: ");
    for (int i = 0; i<qty_nodes(tree); ++i){
        printf("%d, ", tree[i]);
    }
}

int get_left(int *tree, int value){
    int pos_elem = sequential_search_i(tree, value);

    if (pos_elem == -1 || isLeaf(tree, value)) return -1;

    return tree[(2*(pos_elem)+1)];
}

int get_right(int *tree, int value){
    int pos_elem = sequential_search_i(tree, value);

    if (pos_elem == -1 || isLeaf(tree, value)) return -1;

    return tree[(2*(pos_elem+1))];
}

int parent(int *tree, int value){
    int pos_element = sequential_search_i(tree, value);

    if (pos_element <= 0) return -1;

    if ((pos_element%2) == 0) return tree[(pos_element/2)-1];
    else return tree[pos_element/2];
}

int isLeaf(int *tree, int value){

    return !has_child(tree, value);
}

int has_child(int *tree, int value){
    int pos = sequential_search_i(tree, value);

    if (pos < 0) return 0;

    int nodes = qty_nodes(tree);
    return !(((2*(pos+1))-1) > nodes && (2*(pos+1) > nodes));
}

int sequential_search_i(int *tree, int value){
    for (int i=0; i<qty_nodes(tree); ++i){
        if(tree[i] == value) return i;
    }

    return -1;
}

int isComplete(int *tree){
    float log2 = (log10(qty_nodes(tree)+1)/log10(2));

    return (log2 - (int) log2) == 0;
}

//SOH FUNCIONA SE FOR UM HEAP - HEAP É UMA ÁRVORE COM TODAS AS FOLHAS MAIS À ESQUERDA
//TAMBEM FUNCIONA COM UMA ÁRVORE COMPLETA.
int binary_search_r(int *tree, int value, int root){
    if (root > qty_nodes(tree)) return -1;

    if (tree[root] == value) return root;

    if (value < tree[root]){
        return binary_search_r(tree, value, (2*(root+1))-1);
    }else{
        return binary_search_r(tree, value, (2*(root+1)));
    }
}

int qty_nodes(int *tree){
    return find_end(tree);
}


int* generic_build_tree(int *elements, int size){
    int *tree = (int *) malloc((size+1) * sizeof(int));

    int i = 0;
    while(i++<size)
        tree[i-1] = elements[i-1];

    tree[i-1] = -1;

    return tree;
}


void print(int *tree){
    int i = 0;

    printf("\r\nHeap Elements: ");
    while(tree[i] != -1){
        printf("%d, ", tree[i]);
        ++i;
    }
}

int find_end(int *tree){
    int i = 0;
    while(tree[i++] != -1);

    return --i;
}

/*
 Heap
                 16
            ´         `
         14              10
       ´    `          ´     `
    8          7     9          3
  ´   `      ´
2      4    1
*/
int* build_tree1(){
    int elements[10] = {16,14,10,8,7,9,3,2,4,1};

    return generic_build_tree(elements, 10);
}

/*
 Heap para SIFT
                 16
            ´         `
         8              14
       ´    `          ´     `
    8          15     9          3
  ´   `      ´
2      4    1
*/
int* build_tree2(){
    int elements[10] = {16,8,14,8,15,9,3,2,4,1};

    return generic_build_tree(elements, 10);
}

/*
                 4
            ´         `
         1              3
       ´    `          ´     `
    2          16     9          10
  ´   `      ´
14     8    7
*/
int* build_tree3(){
    int elements[10] = {4,1,3,2,16,9,10,14,8,7};

    return generic_build_tree(elements, 10);
}
