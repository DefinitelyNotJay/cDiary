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
int exitPage(void);
void printASCII(void);

int main(){
    Diary *note;
    int total = 365*5;
    note = malloc(sizeof(Diary)*total);

    // for(int i = 0; i < total; ++i){
    //     printf("%d\n", i);
    //     note[i].hour = 0;
    //     note[i].minute = 0;
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
        printASCII();
        printf("Welcome to cDiary!\n");
        printf("1 : Write\n2 : Edit\n3 : Read\n4 : Exit\nSelect An Option : ");
   scanf("%d", &option);
        switch (option){
        case 1:
            create(file_data);
            break;
        case 2:
            edit(file_data);
            break;
        case 3:
            read(file_data);
            break;
        case 4:
            exitPage();
            exit(0);
            free(file_data);
            break;
        default:
            printf("Please enter 1-4 number\n");
        }
    }
    return 1;
}

void printASCII(){
    // printf("   ____________________________________________________\n");
    // printf("  |____________________________________________________|\n");
    // printf("  | __     __   ____   ___ ||  ____    ____     _  __  |\n");
    // printf("  ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |\n");
    // printf("  ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |\n");
    // printf("  ||  |##||  | | || | |JRO|||-|  | |==|+|+||-|-|~||__| |\n");
    // printf("  ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|\n");
    printf("  ______________________________________________________\n");
    printf("  | _____________________  ||      __   __  _  __    _ |\n");
    printf("  ||=|=|=|=|=|=|=|=|=|=|=| __..\\/ |  |_|  ||#||==|  / /|\n");
    printf("  || | | | | | | | | | | |/\\ \\  \\\\|++|=|  || ||==| / / |\n");
    printf("  ||_|_|_|_|_|_|_|_|_|_|_/_/\\_.___\\__|_|__||_||__|/_/__|\n");
    printf("  |____________________ /\\~()/()~//\\ __________________|\n");
    printf("  | __   __    _  _     \\_  (_ .  _/ _    ___     _____|\n");
    printf("  ||~~|_|..|__| || |_ _   \\ //\\ /  |=|__|~|~|___| | |  |\n");
    printf("  ||--|+|^^|==|1||2| | |__/\\ __ /\\__| |==|x|x|+|+|=|=|=|\n");
    printf("  ||__|_|__|__|_||_|_| /  \\ \\  / /  \\_|__|_|_|_|_|_|_|_|\n");
    printf("  |_________________ _/    \\/\\/\\/    \\_ _______________|\n");
    printf("  | _____   _   __  |/      \\../      \\|  __   __   ___|\n");
    printf("  ||_____|_| |_|##|_||   |   \\/ __|   ||_|==|_|++|_|-|||\n");
    printf("  ||______||=|#|--| |\\   \\   o    /   /| |  |~|  | | |||\n");
    printf("  ||______||_|_|__|_|_\\   \\  o   /   /_|_|__|_|__|_|_|||\n");
    printf("  |_________ __________\\___\\____/___/___________ ______|\n");
    printf("  |__    _  /    ________     ______           /| _ _ _|\n");
    printf("  |\\ \\  |=|/   //    /| //   /  /  / |        / ||%%|%%|%%|\n");
    printf("  | \\/\\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|\n");
    printf("  |  \\/\\|/   /(____|/ //                    /  /||~|~|~|  \n");
    printf("  |___\\_/   /________//   ________         /  / ||_|_|_|\n");
    printf("  |___ /   (|________/   |\\_______\\       /  /| |______|\n");
    printf("      /                  \\|________)     /  / | |\n\n");
}





