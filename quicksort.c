#include <stdio.h>
#include <malloc.h>

void quicksort(int *vector, int min, int max);
int partition(int *vector, int p_min, int p_max);
void print(int *vector, int n);

void main (void){
    int n = 15;
    int vector[15] = {4,3,6,9,2,4,3,1,2,1,4,9,3,5,6};

    print(vector, n);
    quicksort(vector, 0, n-1);

}

void quicksort(int *vector, int min, int max){
    if (min < max) {
        int p_pivot = partition(vector, min, max);
        quicksort(vector, min, p_pivot-1);
        quicksort(vector, p_pivot+1, max);
    }
}

int partition(int *vector, int min, int max){
    int p_min = min+1;
    int p_max = max;
    int p_pivot = min;
    int aux;

    while (1){
        while(p_min < max && vector[p_min] < vector[p_pivot]) ++p_min;
        while(p_max > min && vector[p_max] >= vector[p_pivot]) --p_max;

        if (p_min >= p_max) break;

        aux = vector[p_min];
        vector[p_min] = vector[p_max];
        vector[p_max] = aux;
    }

    int pivot = vector[p_pivot];

    vector[min] = vector[p_max];
    vector[p_max] = pivot;

    return p_max;
}


void print(int *vector, int n){
    int i = 0;

    printf("\r\nElements: ");
    while(vector[i] < n){
        printf("%d, ", vector[i]);
        ++i;
    }
}

