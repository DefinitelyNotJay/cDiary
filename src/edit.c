#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
#include <ctype.h>

bool happinessInputHandler(int value);

int createFromRead(Diary *allDiaries, int day, int month, int year);

int edit(Diary *file_data){

    char content[1000];
    int day, month, year, happiness_rate;
    bool continueEditing = true;
    int selection;
    int createFromNull,userInput;
    while(continueEditing){
        system("cls");
        printf("*** Edit ***\n\n");
        printf("(\\ \n");
        printf("\\'\\ \n");
        printf(" \\'\\     __________  \n");
        printf(" / '|   ()_________) \n");
        printf(" \\ '/    \\ ~~~~~~~~ \\ \n");
        printf("   \\       \\ ~~~~~~   \\ \n");
        printf("   ==).      \\__________\\ \n");
        printf("  (__)       ()__________) \n");
        printf("\n\n");

        printf("What date you want to edit? (DD/MM/YYYY) : ");

        scanf("%d/%d/%d", &day, &month, &year);

        int index = getIndexFromDate(day, month, year);

        if(!file_data[index].day == 0){
            printf("------------------------------------------------------\n");
            printDiary(file_data, index);
            printf("------------------------------------------------------\n");
        } else {
            printf("\nYou didn't write the diary that day.\nDo you want to write? (y/n) : ");
            scanf("%c", &createFromNull);
            createFromNull = getchar();

            if(createFromNull == 'y'){
                createFromRead(file_data,day,month,year);
                return 0;
            }
        }


        printf("Are you sure to edit it? (y/n): ");
        scanf("%c", &selection);
        selection = getchar();

        if (selection == 'y' || selection == 'Y'){
            system("cls");
            printf("The diary you are editing...\n");
            printf("------------------------------------------------------\n");
            printDiary(file_data, index);
            printf("------------------------------------------------------\n");
            printf("content : ");
            getchar();
            gets(content);
            printf("\nHappiness rate must be 1-10\n");
            printf("Rate your happiness today ?: ");
            scanf("%d", &happiness_rate);

            while (!(happinessInputHandler(happiness_rate))){
                printf("\n");
                printf("Please try again\nHappiness rate must be 1-10: ");
                scanf("%d", &happiness_rate);
            }
            file_data[index].day = day;
            file_data[index].month = month;
            file_data[index].year = year;
            strcpy(file_data[index].description, content);
            file_data[index].happiness = happiness_rate;
            printf("\n");

            if (write_data("note.bin", file_data, getTotalYear())){
                system("cls");
                printf("Your diary has been edited.\n\n");
                printDiary(file_data, index);
            }
            else
            {
                printf("Error writing to file.\n");
                return 1;
            }
        }
       
            day = 0;
            month = 0;
            year = 0;
        

        printf("\n");
        printf("Do you want to continue editing another diary? (y/n): ");
        scanf("%c", &userInput);
        userInput = getchar();
        if(userInput == 'n'){
            continueEditing  = false;
        }
    }
    system("pause");
    return 0;
}