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


// char * dateTimeFormat(char *date);


int main(){
    Diary *note;
    note = malloc(sizeof(Diary)*365);
    int total = 365;

    // strcpy(note[0].date, "20/01/25");
    // note[0].type = 1;
    // strcpy(note[0].description, "This is one of my best reckless moment in league of legend");
    // note[0].happiness = 1;

    // strcpy(note[1].date, "21/01/25");
    // note[1].type = 2;
    // strcpy(note[1].description, "This is one of my best reckless moment in Point Blank");
    // note[1].happiness = 2;
 
    // strcpy(note[2].date, "22/01/25");
    // note[2].type = 3;
    // strcpy(note[2].description, "This is one of my best reckless moment in HON");
    // note[2].happiness = 3;

    // strcpy(note[3].date, "23/01/25");
    // note[3].type = 4;
    // strcpy(note[3].description, "This is one of my best reckless moment in Genshin Impact");
    // note[3].happiness = 4;

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

    free(note);
    Diary *file_data;

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



