#include <stdio.h>

bool write_data(char *filename, Diary *data, int total);
void printDiaries(struct Diary *note, int total);
Diary *read_data(char *filename, int *total);