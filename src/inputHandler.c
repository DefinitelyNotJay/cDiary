#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include <time.h>
#include <windows.h>

bool dateInputHanlder(int date, int month, int year)
{
    if (month == 2 && date > 29)
    {
        return false;
    }
    bool con1 = date > 0 && date <= 31;
    bool con2 = month > 0 && month <= 12;
    bool con3 = year >= 2023 && year <= 2028;
    bool con4 = &date != NULL && &month != NULL && &year != NULL;
    if (con1 && con2 && con3 && con4)
        return true;
    return false;
};

bool happinessInputHandler(int value)
{
    if (&value == NULL || value < 1 || value > 10)
        return false;
    return true;
}