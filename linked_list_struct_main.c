#include "linked_list_struct.c"

void main (void){
    linkedList ll;

    createList(&ll);
    printf("is empty? %d \r\n", isEmpty(&ll));

    push(&ll, "joaozinho"); //3
    push(&ll, "30"); //2
    push(&ll, "maria"); //1

    print(&ll);

    insert(&ll, "20", 3);
    push(&ll, "100");

    print(&ll);

    xchgNodes(&ll, atPos(&ll, 3), atPos(&ll, 5));

    print(&ll);

    erase(&ll, 5);

    print(&ll);

    clear(&ll);



}