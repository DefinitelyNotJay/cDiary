#ifndef DIARY_H
#define DIARY_H

typedef struct Diary
{
    int day, month, year, hour, minute;
    char description[1000];
    int happiness;
} Diary;

#endif