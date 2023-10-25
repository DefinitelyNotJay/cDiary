#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "diary.h"
#include <time.h>

int total_year = 365 * 5;


Diary *read_data(char *filename, int *total){
    FILE* file;

    file = fopen(filename, "rb"); //read from binary file

    if(file == NULL) return NULL;

    if (fread(total, sizeof(int), 1, file) != 1)
    return NULL;

    Diary *data = malloc(sizeof(Diary) * *total);

    if (fread(data, sizeof(Diary), *total, file) != *total){
        free(data);
        return NULL;
    }

    if (fclose(file) == EOF){
        free(data);
        return NULL;
    }
    printf("from read_data\n");
    return data;
}

bool write_data(char *filename, Diary *data, int total){
    FILE *file;

    file = fopen(filename, "wb");

    if(file == NULL) return false;

    if(fwrite(&total, sizeof(int), 1, file) != 1)
    return false;

    if (fwrite(data, sizeof(Diary), total, file) != total)
    return false;

    if (fclose(file) == EOF) return false;

    return true;
}

void printDiaries(struct Diary *note, int total){
    printf("\nData read OK.\n\n");
    for (int i = 0; i<total; i++){
        printf("Diary %d\n", i+1);
        printf("Date: %02d/%02d/%04d\n", note[i].day, note[i].month, note[i].year);
        printf("Text: %s\n", note[i].description);
        printf("Happiness: %d", note[i].happiness);
        printf("\n\n");
    }
}
    
void printDiary(struct Diary *note, int index){
        printf("Diary No.%d\n", index+1);
        printf("Date: %02d/%02d/%04d\n", note[index].day, note[index].month, note[index].year);
        printf("Text: %s\n", note[index].description);
        printf("Happiness: %d", note[index].happiness);
        printf("\n\n");
}

int getIndexFromDate(int day, int month, int year){
    return (year-2023)*365 + (month-1)*31 + day-1;
}

int getTotalYear(){
    return total_year;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


