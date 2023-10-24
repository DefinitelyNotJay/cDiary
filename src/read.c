#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
#include <windows.h>

int read(Diary *allDiaries){

    int day, month, year;

    system("cls");
    printf("     ______ ______\n");
    printf("    _/      Y      \\_\n");
    printf("   // ~~ ~~ | ~~ ~  \\\\\n");
    printf("  // ~ ~ ~~ | ~~~ ~~ \\\\\n");
    printf(" //________.|.________\\\\\n");
    printf("`----------`-'----------'\n");

    printf("Which diary you wanna see?\nInput your date here (DD/MM/YY) : ");
    scanf("%d/%d/%d", &day, &month, &year);

    

    printDiary(allDiaries, getIndexFromDate(day, month, year));

    system("pause");

    return 0;


}