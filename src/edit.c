#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
#include <ctype.h>

int edit(Diary *file_data){

    int day, month, year;
    char* userInput;

    printf("*** Edit ***\n\n");
    // insert cool ASCII pic
    printf("What date you want to edit? (DD-MM-YYYY) : ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Edit content? : (yes/no)");
    getchar();
    gets(userInput);
}