#include <stdio.h>
#include "diary.h"
#include <stdbool.h>

bool write_data(char *filename, Diary *data, int total);
void printDiaries(struct Diary *note, int total);
void printDiary(struct Diary *note, int index);
Diary *read_data(char *filename, int *total);
int getIndexFromDate(int day, int month, int year);
int getTotalYear();
void delay(int);