#include "deque_struct.c"

void main (void){
    deque *d = createDeque();

    insertFirst(d, 10);
    print(d);
    insertFirst(d, 12);
    print(d);
    insertLast(d, 99);
    print(d);
    removeFirst(d);
    print(d);
    removeLast(d);
    print(d);
    insertLast(d, 37);
    print(d);
    insertFirst(d, 243);
    print(d);

}