#ifndef DIARY_H
#define DIARY_H

typedef struct Diary
{
    char date[8];
    int type;
    char description[1000];
    int happiness;
} Diary;

#endif