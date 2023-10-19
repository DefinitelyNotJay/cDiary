#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct Diary
{
    char date[8];
    int type;
    char description[1000];
    int happiness;
} Diary;

bool write_data(char *filename, Diary *data, int total);
void printDiaries(struct Diary *note, int total);

// char * dateTimeFormat(char *date);

Diary *read_data(char *filename, int *total);

int main(){
    Diary *note;
    note = malloc(sizeof(Diary)*365);
    int total = 365;

    strcpy(note[0].date, "20/01/25");
    note[0].type = 1;
    strcpy(note[0].description, "This is one of my best reckless moment in league of legend");
    note[0].happiness = 1;

    strcpy(note[1].date, "21/01/25");
    note[1].type = 2;
    strcpy(note[1].description, "This is one of my best reckless moment in Point Blank");
    note[1].happiness = 2;
 
    strcpy(note[2].date, "22/01/25");
    note[2].type = 3;
    strcpy(note[2].description, "This is one of my best reckless moment in HON");
    note[2].happiness = 3;

    strcpy(note[3].date, "23/01/25");
    note[3].type = 4;
    strcpy(note[3].description, "This is one of my best reckless moment in Genshin Impact");
    note[3].happiness = 4;

    int day;
    printf("Enter day : ");
    scanf("%d", &day);
    printf("Enter date : ");
    scanf("%s", note[day].date);
    printf("Enter type : ");
    scanf("%d", &note[day].type);
    printf("Enter description : ");
    scanf("%s", note[day].description);
    printf("Enter happiness : ");
    scanf("%d", &note[day].happiness);
 
    if (write_data("note.bin", note, 4))
    printf("Write data OK.\n");
    else {
        printf("Error writing to file.\n");
        return 1;
    }

    // free(note);
    Diary *file_data;
    file_data = read_data("note.bin", &total);

    if(file_data == NULL){
        printf("Error reading from file.\n");
        return 1;
    }
    free(file_data);
    // int x,y,z;
    // scanf("%d", &x);
    // scanf("%d", &y);
    // scanf("%d", &z);

    printDiaries(file_data, total);
    return 0;
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

    return data;

}