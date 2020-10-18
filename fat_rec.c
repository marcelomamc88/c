#include <stdio.h>


int fat_recursivo(int n){
    if (n == 0 || n == 1) return 1;

    return n * fat_recursivo(n-1);
}

int fat_iterativo(int n){
    int fat = 1;

    for (int i=1 ; i<=n ; i++){
        fat *= i;
    }

    return fat;
}

void main(void) {
    int opcao;

    printf("1- Fatorial Recursivo \r\n2- Fatorial Explicito \r\n");

    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Fatorial Recursivo \r\n");
        printf("%d", fat_recursivo(6));
    }else {
        printf("Fatorial Iterativo \r\n");
        printf("%d", fat_iterativo(6));
    }
}
