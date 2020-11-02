#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define NO_OF_CHARS 3

int isSuffixOf(char *substr_a, char *substr_b);
void strslice_to_buffer(char *text, int i, int n, char *buffer);
void clear_buffer(char *buffer);
void print_AF(int AF[][NO_OF_CHARS], int states);


char alphabet[NO_OF_CHARS] = {'A', 'B', 'C'};
char buffer_1[1000];
char buffer_2[1000];

int get_char_alphabet(char letter){
    for (int i=0; i<NO_OF_CHARS; ++i)
        if (letter == alphabet[i]) return i;

    return -1;
}

void AFConstruct(char *pattern, int m, int AF[][NO_OF_CHARS]){

    for (int state=0; state<=m; ++state){ //para cada estado
        for (int pos_alphabet = 0; pos_alphabet<NO_OF_CHARS; ++pos_alphabet){ //para cada simbolo do alfabeto
            char symbol = alphabet[pos_alphabet];

            int k = state+2 < m+1 ? state+2 : m+1;

            do {
                --k;
                clear_buffer(buffer_1);
                clear_buffer(buffer_2);

                if (k-1 >= 0) {
                    strslice_to_buffer(pattern, 0, k, buffer_1);
                }else{
                    buffer_1[0] = '\0';
                }

                if (state-1 >= 0) {
                    strslice_to_buffer(pattern, 0, state, buffer_2);
                }

                buffer_2[strlen(buffer_2)] = symbol;
                buffer_2[strlen(buffer_2)+1] = '\0';

                printf("s: %d | symbol: %c | k: %d | _%s_ isSuffixOf _%s_? %d\r\n", state, symbol, k, buffer_1, buffer_2, isSuffixOf(buffer_1, buffer_2));
            }while (!isSuffixOf(buffer_1, buffer_2));
            //is suffix a in b+newchar
            printf("\r\nstate %d | pos_alph %d | k %d\r\n", state, pos_alphabet, k);
            AF[state][pos_alphabet] = k;
        }
    }
}

void strslice_to_buffer(char *text, int i, int n, char *buffer){

    int pos_buffer = 0;
    int pos_ini_text = i;

    for (int x=0; x<n; ++x){
        buffer[pos_buffer++] = text[pos_ini_text+x];
    }
    buffer[pos_buffer] = '\0';
}



int isSuffixOf(char *substr_a, char *substr_b){
    int len_a = strlen(substr_a);
    int len_b = strlen(substr_b);
    int diff_size_ab = len_b - len_a;

    //se uma string ou outra for vazia (epsilon), serão sufixos
    if (len_a == 0 || len_b == 0) return 1;

    if (len_a > len_b) return 0;

    for (int i=len_a-1; i>=0; --i){
        if (substr_a[i] != substr_b[i+diff_size_ab]) return 0;
    }

    return 1;
}

/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt, int AF[][NO_OF_CHARS])
{
    int M = strlen(pat);
    int N = strlen(txt);

    AFConstruct(pat, M, AF);

    // Process txt over AF.
    /*int i, state=0;
    for (i = 0; i < N; i++)
    {
        state = *AF[state][get_char_alphabet(txt[i])];
        if (state == M)
            printf ("\n Pattern found at index %d", i-M+1);
    }*/
}

// Driver program to test above function
int main()
{
    char *txt = "ABABABACABA";
    char *pat = "ABABACA";

    int states = strlen(pat)+1;

    int AF[states][NO_OF_CHARS];

    search(pat, txt, AF);

    print_AF(AF, states);

    return 0;
}

void clear_buffer(char *buffer){
    buffer[0] = '\0';
}

void print_AF(int AF[][NO_OF_CHARS], int states){
    for(int i=0; i<states; ++i){
        printf("\r\n%d | ", i);
        for (int j=0; j<NO_OF_CHARS; ++j){
            printf("%d ", AF[i][j]);
        }
    }
    printf("\r\n");
}