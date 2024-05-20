#include <string.h>
#include<stdio.h>
#ifndef PROJET_C_COLUMN_H
#define PROJET_C_COLUMN_H
typedef struct {
    char* title;
    int *values;
    size_t size;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int countOccurrences(int array[], int size, int x);
int getValueAtIndex(int array[], int size, int index);
int countValuesGreaterThanX(int array[], int size, int x);
int countValuesLessThanX(int array[], int size, int x);
int countValuesEqualToX(int array[], int size, int x);




#endif //PROJET_C_COLUMN_H


