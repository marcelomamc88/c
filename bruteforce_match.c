#include <stdio.h>

int bruteforce_match(int n, int m);

char vetor[11] = {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'c', 'a', 'b', 'a'};
char pattern[7] = {'a', 'b', 'a', 'b', 'a', 'c', 'a'};

void main (void){
    printf("Match Position: %d", bruteforce_match(11, 7));
}

int bruteforce_match(int n, int m){
    for (int i=0; i<n; ++i){
        int j=0;
        while(j<m && vetor[i+j] == pattern[j]){
            ++j;
        }
        if (j==m) return i;
    }

    return -1;
}