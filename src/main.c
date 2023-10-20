#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"

int create();
int constructor();


int main(){
    Diary *note;
    int total = 365;
    note = malloc(sizeof(Diary)*total);


    note[0].type = 1;
    strcpy(note[0].description, "This is one of my best reckless moment in league of legend");
    note[0].happiness = 1;

    strcpy(note[1].date, "21/01/25");
    note[1].type = 2;
    strcpy(note[1].description, "This is one of my best reckless moment in Point Blank");
    note[1].happiness = 2;

    int number = write_data("note.bin", note, 2);
    free(note);

    Diary *file_data;
    file_data = read_data("note.bin", &total);
    free(file_data);
    printf("%s\n", file_data[1].description);
    // printDiaries(file_data, total);
    int option;

    /* instruction : 
        1 create
        2 read
        3 edit
        4 delete
        5 exit
    */
    while(option != 5){
   scanf("%d", &option);
        switch (option){
        case 1:
            // create();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please insert 1-5 number\n");
        }
    }
    return 1;
}


int constructor(){

}



