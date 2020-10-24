
#include "queue_struct.c"

void main(void){

    queue *q = createQueue();

    enqueue(2, q);
    enqueue(4, q);
    enqueue(6, q);
    enqueue(8, q);
    print(q);

    dequeue(q);
    dequeue(q);

    print(q);
}