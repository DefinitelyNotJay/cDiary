#include <stdio.h>
#include "diary.h"
#include "fileHandler.h"
#include <windows.h>

int exitPage(){
    system("cls");
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
    return 0;
}