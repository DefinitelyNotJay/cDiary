#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include "inputHandler.h"
#include <time.h>
#include <windows.h>

int create(Diary *file_data);
int edit(Diary *file_data);
int read(Diary *allDiaries);
int exitPage(void);
void printASCII(void);

int main(){
    Diary *note;
    int total = 365*5;
    note = malloc(sizeof(Diary)*total);

    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);

    int option;

   printf("*** Main Menu ***\n");
    while(option != 4){
        Diary *file_data;
        file_data = read_data("note.bin", &total);
        system("cls");
        printASCII();
        printf("Welcome to cDiary!\n");
        printf("Today's Date : %s, %d %s, %d\n", getTodayDate(tm_info->tm_wday), tm_info->tm_mday, getTodayMonth(tm_info->tm_mon + 1), tm_info->tm_year + 1900);
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
