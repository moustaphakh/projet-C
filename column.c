<<<<<<< HEAD
//
// Created by steve on 21/04/2024.
//

#include "column.h"
#include<stdio.h>
#ifndef PROJET_C_COLUMN_H
#define PROJET_C_COLUMN_H
typedef struct {
    char* title;
    int physical_size;
    int logical_size;
    int* data;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int countOccurrences(int array[], int size, int x);
int getValueAtIndex(int array[], int size, int index);
int countValuesGreaterThanX(int array[], int size, int x);
int countValuesLessThanX(int array[], int size, int x);
int countValuesEqualToX(int array[], int size, int




#endif //PROJET_C_COLUMN_H










return 0;
}
