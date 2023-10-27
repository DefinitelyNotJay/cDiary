#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "diary.h"
#include <time.h>
#include <string.h>

int total_year = 365 * 5;




Diary *read_data(char *filename, int *total)
{
    FILE *file;

    file = fopen(filename, "rb"); // read from binary file

    if (file == NULL)
        return NULL;

    if (fread(total, sizeof(int), 1, file) != 1)
        return NULL;

    Diary *data = malloc(sizeof(Diary) * *total);

    if (fread(data, sizeof(Diary), *total, file) != *total)
    {
        free(data);
        return NULL;
    }

    if (fclose(file) == EOF)
    {
        free(data);
        return NULL;
    }
    printf("from read_data\n");
    return data;
}

bool write_data(char *filename, Diary *data, int total)
{
    FILE *file;

    file = fopen(filename, "wb");

    if (file == NULL)
        return false;

    if (fwrite(&total, sizeof(int), 1, file) != 1)
        return false;

    if (fwrite(data, sizeof(Diary), total, file) != total)
        return false;

    if (fclose(file) == EOF)
        return false;

    return true;
}

void printDiaries(struct Diary *note, int total)
{
    printf("\nData read OK.\n\n");
    for (int i = 0; i < total; i++)
    {
        printf("Diary %d\n", i + 1);
        printf("Date: %02d/%02d/%04d\n", note[i].day, note[i].month, note[i].year);
        printf("Text: %s\n", note[i].description);
        printf("Happiness: %d", note[i].happiness);
        printf("\n\n");
    }
}

void printDiary(struct Diary *note, int index)
{
    printf("Diary No.%d\n", index + 1);
    printf("Date: %02d/%02d/%04d %02d:%02d\n", note[index].day, note[index].month, note[index].year, note[index].hour, note[index].minute);
    printf("Text: %s\n", note[index].description);
    printf("Happiness: %d", note[index].happiness);
    printf("\n");
}

int getIndexFromDate(int day, int month, int year)
{
    return (year - 2023) * 365 + (month - 1) * 31 + day - 1;
}

int getTotalYear()
{
    return total_year;
}

void delay(float number_of_seconds)
{
    // Converting time into milli_seconds
    float milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void loading()
{
    char progressBar[33] = "[-----------------------------]";
    system("cls");
    for (int i = 1; i < 21; i++)
    {
        printf("Saving your data.\n\n");
        if (i % 3 == 0)
        {
            printf("Loding...\n");
        }
        else if (i % 2 == 0)
        {
            printf("Loding..\n");
        }
        else if (i % 1 == 0)
        {
            printf("Loding.\n");
        }
        progressBar[i] = '=';
        printf("%s", progressBar);
        delay(0.02);
        system("cls");
    }
    strcpy(progressBar, "[------------------------------]");
}

char *getTodayDate(int day){
    char *date = malloc(10);
    switch (day)
    {
    case 1:
        strcpy(date, "Monday");
        break;
    case 2:
        strcpy(date, "Tuesday");
        break;
    case 3:
        strcpy(date, "Wednesday");
        break;
    case 4:
        strcpy(date, "Thursday");
        break;
    case 5:
        strcpy(date, "Friday");
        break;
    case 6:
        strcpy(date, "Saturday");
        break;
    case 7:
        strcpy(date, "Sunday");
        break;
    }
    return date;
}

char *getTodayMonth(int month_num){
    char *month = malloc(10);
    switch (month_num)
    {
    case 1:
        strcpy(month, "January");
        break;
    case 2:
        strcpy(month, "February");
        break;
    case 3:
        strcpy(month, "March");
        break;
    case 4:
        strcpy(month, "April");
        break;
    case 5:
        strcpy(month, "May");
        break;
    case 6:
        strcpy(month, "June");
        break;
    case 7:
        strcpy(month, "July");
        break;
    case 8:
        strcpy(month, "August");
        break;
    case 9:
        strcpy(month, "September");
        break;
    case 10:
        strcpy(month, "October");
        break;
    case 11:
        strcpy(month, "November");
        break;
    case 12:
        strcpy(month, "December");
        break;
    }
    return month;
}
