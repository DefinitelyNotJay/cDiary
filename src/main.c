#include "stdio.h"
#include <stdlib.h>

int main(){
    char option;
    void create(){
        printf("create\n");
    }
    /* instruction : 
        1 create
        2 read
        3 edit
        4 delete
        5 exit
    */
    while(option != 5){
   scanf("%c", &option);
        // printf("type is : %lu\n", sizeof(option));
        switch (option){
        case 1:
            create();
            break;
        case 5:
            exit(0);
            break;
        default:
            // printf("Please insert 1-5 number\n");
            printf("default\n");
            break;
        }
        // scanf("%d", &option);
    }
    return 1;
}
