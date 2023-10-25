#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <Windows.h>

int create(Diary *file_data);
int edit(Diary *file_data);
int read(Diary *allDiaries);

int main(){
    Diary *note;
    int total = 365*5;
    note = malloc(sizeof(Diary)*total);

    // for(int i = 0; i < total; ++i){
    //     printf("%d\n", i);
    //     note[i].day = 0;
    //     note[i].month = 0;
    //     note[i].year = 0;
    //     strcpy(note[i].description, "");
    //     note[i].happiness = 0;
    // }

    //  if (write_data("note.bin", note, total))
    //         printf("Write data OK.\n");
    // else {
    //     printf("Error writing to file.\n");
    //     return 1;
    // }
    // free(note);


    int option;

    /* instruction : 
        1 create
        2 read
        3 edit
        4 delete
        5 exit
    */
   printf("*** Main Menu ***\n");
    while(option != 4){
        Diary *file_data;
        file_data = read_data("note.bin", &total);
        system("cls");
        printf("1 : Write\n2 : Edit\n3 : Read\n4 : Exit\nSelect An Option : ");
   scanf("%d", &option);
        switch (option){
        case 1:
            create(file_data);
            break;
        case 3:
            read(file_data);
            break;
        case 4:
            exit(0);
            free(file_data);
            break;
        default:
            printf("Please enter 1-4 number\n");
        }
    }
    return 1;
}

int constructor(){

}





