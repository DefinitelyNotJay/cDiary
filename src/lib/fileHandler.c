#include <stdio.h>
#include <stdbool.h>
#include "diary.h"

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
        printf("Date: %s\n", note[i].date);
        printf("Type: %d\n", note[i].type);
        printf("Text: %s\n", note[i].description);
        printf("Happiness: %d", note[i].happiness);
        printf("\n\n\n");
    }
}

