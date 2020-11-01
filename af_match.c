#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 3

char alphabet[NO_OF_CHARS] = {'A', 'B', 'C'};

//entra aqui para cada STATE e cada CHARACTER do alfabeto
int getNextState(char *pat, int M, int state, char c_alphabet)
{
    // If the character c is same as next character
    // in pattern,then simply increment state
    if (state < M && c_alphabet == pat[state])
        return state+1;

    //NS is Next State
    // ns stores the result which is next state
    int ns, i;

    // ns finally contains the longest prefix
    // which is also suffix in "pat[0..state-1]c"

    // Start from the largest possible value
    // and stop when you find a prefix which
    // is also suffix
    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns-1] == c_alphabet)
        {
            for (i = 0; i < ns-1; i++)
                if (pat[i] != pat[state-ns+1+i])
                    break;
            if (i == ns-1)
                return ns;
        }
    }

    return 0;
}

int get_char_alphabet(char letter){
    for (int i=0; i<NO_OF_CHARS; ++i)
        if (letter == alphabet[i]) return i;
    
    return -1;
}

/* This function builds the TF table which represents4
	Finite Automata for a given pattern */
void computeTF(char *pat, int M, int TF[][NO_OF_CHARS])
{
    int state, c_alphabet;
    for (state = 0; state <= M; ++state)
        for (c_alphabet = 0; c_alphabet < NO_OF_CHARS; ++c_alphabet)
            TF[state][c_alphabet] = getNextState(pat, M, state, alphabet[c_alphabet]);



    printf("TF:\r\n");
    for (int i=0; i<state; ++i){
        printf("\r\n%d  |", i);
        for (int j=0; j<NO_OF_CHARS; ++j){
            printf("%d ", TF[i][j]);
        }
    }
}

/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M+1][NO_OF_CHARS];

    computeTF(pat, M, TF);

    // Process txt over FA.
    int i, state=0;
    for (i = 0; i < N; i++)
    {
        state = TF[state][get_char_alphabet(txt[i])];
        if (state == M)
            printf ("\n Pattern found at index %d", i-M+1);
    }
}

// Driver program to test above function
int main()
{
    char *txt = "ABABABACABA";
    char *pat = "ABABACA";
    search(pat, txt);
    return 0;
}