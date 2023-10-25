#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
#include <windows.h>

bool dateInputHanlder(int date, int month, int year);
bool happinessInputHandler(int value);

int create(Diary *file_data)
{
    time_t t;
    struct tm *tm_info;
    int year, month, date, happiness_rate;
    char content[1000];
    char userWriteToday[1];
    int total = 365 * 5;
    time(&t);
    tm_info = localtime(&t);

    system("cls");

    printf("*** Write ***\n");
    //  printf("Today's date: %02d/%02d/%04d\n", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
    printf("Write today content? (y/n) : ");
    getchar();
    gets(userWriteToday);

    if (strcmp(userWriteToday, "y") == 0)
    {
        date = tm_info->tm_mday;
        month = tm_info->tm_mon + 1;
        year = tm_info->tm_year + 1900;
    }
    else
    {
        printf("Today's Date (dd/mm/yyyy) : ");
        scanf("%d/%d/%d", &date, &month, &year);
        while (!dateInputHanlder(date, month, year))
        {
            printf("Wrong datetime please try again : ");
            scanf("%d/%d/%d", &date, &month, &year);
        }
    }

    int index = getIndexFromDate(date, month, year);

    system("cls");
    printf("Today's content : ");
    gets(content);
    system("cls");
    printf("Rate your happiness today! : ");
    scanf("%d", &happiness_rate);
    while (!happinessInputHandler(happiness_rate))
    {
        printf("Please try again\nHappiness rate should be 1-10 : ");
        scanf("%d", &happiness_rate);
    }


    file_data[index].day = date;
    file_data[index].month = month;
    file_data[index].year = year;
    strcpy(file_data[index].description, content);
    file_data[index].happiness = happiness_rate;

    if (write_data("note.bin", file_data, total))
        printf("Write data OK.\n");
    else
    {
        printf("Error writing to file.\n");
        return 1;
    }
    system("pause");


    return 0;
}

int createFromRead(Diary *file_data, int day, int month, int year){
    printf("testtest\n");
    system("pause");
    return 0;
}

bool dateInputHanlder(int date, int month, int year)
{
    if (month == 2 && date > 29)
    {
        return false;
    }
    bool con1 = date > 0 && date <= 31;
    bool con2 = month > 0 && month <= 12;
    bool con3 = year >= 2023 && year <= 2028;
    bool con4 = &date != NULL && &month != NULL && &year != NULL;
    if (con1 && con2 && con3 && con4)
        return true;
    return false;
};

bool happinessInputHandler(int value)
{
    if (&value == NULL || value < 1 || value > 10)
        return false;
    return true;
}