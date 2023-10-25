#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diary.h"
#include "fileHandler.h"
#include "inputHandler.h"
#include <time.h>
#include <windows.h>

int exitPage(){
    printf("    _____\n");
    printf("   /    /|_ ___________________________________________\n");
    printf("  /    // /|                                          /|\n");
    printf(" (====|/ // It's not how much time you have, _QP_    / |\n");
    printf("  (=====|/     it's how you use it.         (  ' )  / .|\n");
    printf(" (====|/                                     \\__/  / /||\n");
    printf("/_________________________________________________/ / ||\n");
    printf("|  _____________________________________________  ||  ||\n");
    printf("| ||                                            | ||\n");
    printf("| ||                                            | ||\n");
    printf("| |                                             | | \n\n\n");

    printf("%d ", 3);
    delay(1);
    printf("%d ", 2);
    delay(1);
    printf("%d\n", 1);
    delay(1);
    // printf("%s", "See you space cowboy");
    // delay(1);
    return 0;
}