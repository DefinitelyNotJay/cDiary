#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"

int create(Diary *file_data);

int main(){
    Diary *note;
    int total = 365;
    note = malloc(sizeof(Diary)*4);

    // note[0].day = 1;
    // note[0].month = 1;
    // note[0].year = 2023;
    // strcpy(note[0].description, "This is one of my best reckless moment in league of legend");
    // note[0].happiness = 1;

    // note[1].day = 2;
    // note[1].month = 1;
    // note[1].year = 2023;
    // strcpy(note[1].description, "This is one of my best reckless moment in Point Blank");
    // note[1].happiness = 2;

    //  if (write_data("note.bin", note, 4))
    //         printf("Write data OK.\n");
    // else {
    //     printf("Error writing to file.\n");
    //     return 1;
    // }
    // free(note);

    Diary *file_data;
    file_data = read_data("note.bin", &total);
    free(file_data);
    printDiaries(file_data, total);
    int option;

    /* instruction : 
        1 create
        2 read
        3 edit
        4 delete
        5 exit
    */
   printf("%d\n", sizeof(file_data));
   printf("*** Main Menu ***\n");
    while(option != 4){
        printf("1 : Write\n2 : Edit\n3 : Read\n4 : Exit\nSelect An Option : ");
   scanf("%d", &option);
        switch (option){
        case 1:
            create(file_data);
            system("pause");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please enter 1-4 number\n");
        }
    }
    return 1;
}

int constructor(){

}





