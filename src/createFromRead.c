#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include "inputHandler.h"
#include <time.h>
#include <windows.h>

void printASCIIWrite(void);

int createFromRead(Diary *file_data, int day, int month, int year){
    system("cls");

    printf("*** Write ***\n");
    printASCIIWrite();
    char content[1000];
    int index = getIndexFromDate(day, month, year);
    int happiness_rate;
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);

    system("cls");
    printf("%02d/%02d/%d\n", day, month, year);
    printf("Content : ");
    getchar();
    gets(content);
    printf("Happiness rate must be 1-10\nRate your happiness today? : ");
    scanf("%d", &happiness_rate);
    while (!happinessInputHandler(happiness_rate))
    {
        printf("Please try again\nHappiness rate must be 1-10 : ");
        scanf("%d", &happiness_rate);
    }

    file_data[index].day = day;
    file_data[index].month = month;
    file_data[index].year = year;
    strcpy(file_data[index].description, content);
    file_data[index].happiness = happiness_rate;
    file_data[index].hour = tm_info->tm_hour;
    file_data[index].minute = tm_info->tm_min;

    if (write_data("note.bin", file_data, getTotalYear()))
        printf("Write data OK.\n");
    else
    {
        printf("Error writing to file.\n");
        return 1;
    }

    system("pause");
    return 0;
}