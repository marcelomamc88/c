#include "queue_struct.c"

void josephus_queue(int n);
void josephus_vector(int n);
void print_jewishes(int *v, int n);
int launch(int *jewishes, int knife, int n);

void main(void){
    int n = 50;

    josephus_queue(n);
    josephus_vector(n);
}

int launch(int *jewishes, int jewish_knife, int n){
    int jewish_target = jewish_knife+1;

    while (jewish_target % n != jewish_knife % n){
        if (jewishes[jewish_target % n] == 1 ){
            jewishes[jewish_target % n] = 0;
            return 1;
        }
        ++jewish_target;
    }
    return 0;
}

void josephus_vector(int n){
    int *jewishes = (int *) malloc(n * sizeof(int));

    for (int i=0; i < n; ++i){
        jewishes[i] = 1;
    }

    int dead = 0;
    int jewish_knife = 0;

    while(dead < n-1){
        if (jewishes[jewish_knife%n] == 0){
            ++jewish_knife;
            continue;
        }

        if (launch(jewishes, jewish_knife, n)){
            jewish_knife = ++jewish_knife % n;
            ++dead;
            continue;
        }

        break;
    }

    printf("\r\nJOSEPHUS VECTOR: %d", jewish_knife == 0 ? n : jewish_knife);
}


void josephus_queue(int n){
    queue *q = createQueue();

    for (int i=1; i <= n; ++i){
        enqueue(i, q);
    }

    int j = 0;
    int jewish_dead = -1;

    while(size(q) > 0){
        print(q);
        ++j;
        node *jewish = dequeue(q);

        enqueue(jewish->value, q);

        node *j_dead = dequeue(q);
        jewish_dead = j_dead->value;
    }

    printf("\r\nJOSEPHUS QUEUE: %d", jewish_dead);
}

void print_jewishes(int *v, int n){
    printf("\r\nITERATION");
    for (int i = 0; i < n; ++i){
        printf("\r\n %d -> %d", i+1, v[i]);
    }
}
