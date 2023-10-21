#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
bool dateInputHanlder(int date, int month, int year);
int create(Diary *file_data){
    time_t t;
    struct tm *tm_info;
    int year, month, date, happiness_rate;
    char content[1000];
    time(&t);
    tm_info = localtime(&t);

    printf("create from create.c\n");
    printf("*** Write ***\n");
    //  printf("Today's date: %02d/%02d/%04d\n", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
    printf("Today's Date (dd/mm/yyyy) : ");
    scanf("%d/%d/%d", &date, &month, &year);
    while(!dateInputHanlder(date, month, year)){
        printf("Wrong datetime please try again : ");
        scanf("%d/%d/%d", &date, &month, &year);
    }
    printf("Today's content : ");
    getchar();
    gets(content);
    printf("Content is : %s\n", content);
    printf("Rate your happiness today! : ");
    scanf("%d", &happiness_rate);
    int index = (year-2023)*365 + (month-1)*31 + date-1;

    file_data[index].day = date;
    file_data[index].month = month;
    file_data[index].year = year;
    strcpy(file_data[index].description, content);
    file_data[index].happiness = happiness_rate;
    if (write_data("note.bin", file_data, 4))
            printf("Write data OK.\n");
    else {
        printf("Error writing to file.\n");
        // return 1;
    }
    system("pause");
    printDiaries(file_data, 4);
    return 0;
}

bool dateInputHanlder(int date, int month, int year){
    if(month == 2 && date > 29){
        return false;
    }
    bool con1 = date > 0 && date <= 31;
    bool con2 = month > 0 && month <= 12;
    bool con3 = year >= 2023 && year <= 2025;
    
    if(con1&&con2&&con3){
        printf("All true\n");
        return true;
    }else{
        printf("false\n");
        return false;
    };
  return false;
};