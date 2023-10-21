#ifndef DIARY_H
#define DIARY_H

typedef struct Diary
{
    int day;
    int month;
    int year;
    char description[1000];
    int happiness;
} Diary;

#endif