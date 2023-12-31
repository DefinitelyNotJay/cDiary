#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include "inputHandler.h"
#include <time.h>
#include <windows.h>

void printASCIIWrite(void);

int create(Diary *file_data)
{
    time_t t;
    struct tm *tm_info;
    int year, month, date, hour, min, happiness_rate;
    char content[1000];
    char userWriteToday[1];
    time(&t);
    tm_info = localtime(&t);

    system("cls");

    printf("*** Write ***\n");
    printASCIIWrite();
    printf("Write today content? (y/n) : ");
    getchar();
    gets(userWriteToday);

    if ((strcmp(userWriteToday, "y") == 0) || (strcmp(userWriteToday,"Y") == 0))
    {
        date = tm_info->tm_mday;
        month = tm_info->tm_mon + 1;
        year = tm_info->tm_year + 1900;
    }
    else
    {
        printf("Today's Date (dd/mm/yyyy) : ");
        scanf("%d/%d/%d", &date, &month, &year);
        while (!dateInputHanlder(date, month, year))
        {
            printf("Wrong datetime please try again : ");
            scanf("%d/%d/%d", &date, &month, &year);
        }
    }

    int index = getIndexFromDate(date, month, year);

    system("cls");
    printf("Today's content : ");
    getchar();
    gets(content);
    system("cls");
    printf("Happiness rate must be 1-10\n");
    printf("Rate your happiness today ?: ");
    scanf("%d", &happiness_rate);
    while ((happiness_rate > 10) || (happiness_rate < 1))
    {
        printf("\n");
        printf("Please try again\nHappiness rate must be 1-10: ");
        scanf("%d", &happiness_rate);
    }

    file_data[index].day = date;
    file_data[index].month = month;
    file_data[index].year = year;
    strcpy(file_data[index].description, content);
    file_data[index].happiness = happiness_rate;
    file_data[index].hour = tm_info->tm_hour;
    file_data[index].minute = tm_info->tm_min;

    printf("\n");

    if (write_data("note.bin", file_data, getTotalYear()))
        printf("Write data OK.\n");
    else
    {
        printf("Error writing to file.\n");
        return 1;
    }
    system("pause");


    return 0;
}

void printASCIIWrite(){
    printf("  __\n");
    printf(" (`/\\ \n");
    printf(" `=\\/\\ __...--~~~~~-._   _.-~~~~~--...__ \n");
    printf("  `=\\/\\               \\ /               \\ \n");
    printf("   `=\\/                V                 \\ \n");
    printf("   //_\\___--~~~~~~-._  |  _.-~~~~~~--...__\\ \n");
    printf("  //  ) (..----~~~~._\\ | /_.~~~~----.....__\\ \n");
    printf(" ===( INK )==========\\\\|//==================== \n");
    printf("     \\___/           `---`\n\n");
}

