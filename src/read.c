#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
#include <windows.h>

int createFromRead(Diary *allDiaries, int day, int month, int year);

int read(Diary *allDiaries){

    int day, month, year;
    bool continueReading = true;
    int continueReadingInput;
    int createFromNull;

    system("cls");
    printf("      ______ ______\n");
    printf("    _/      Y      \\_\n");
    printf("   // ~~ ~~ | ~~ ~  \\\\\n");
    printf("  // ~ ~ ~~ | ~~~ ~~ \\\\\n");
    printf(" //________.|.________\\\\\n");
    printf("`----------`-'----------'\n");

    while(continueReading){

    printf("\n\n");
    printf("Which diary you wanna see?\nInput your date here (DD/MM/YYYY) : ");
    scanf("%d/%d/%d", &day, &month, &year);

    int index = getIndexFromDate(day, month, year);

    if(!allDiaries[index].day == 0){
        printf("------------------------------------------------------\n");
        printDiary(allDiaries, index);
        printf("------------------------------------------------------\n");
    } else {
        printf("You didn't write the diary that day.\nDo you want to write? (y/n) : ");
        scanf("%c", &createFromNull);
        createFromNull = getchar();

        if(createFromNull == 'y'){
            createFromRead(allDiaries,day,month,year);
            return 0;
        }
    }



    printf("Continue reading? (y/n): ");
    scanf("%c", &continueReadingInput);
    continueReadingInput = getchar();

    if(continueReadingInput == 'n'){
        continueReading = false;
        printf("\n");
    }

    }
    system("pause");

    return 0;


}