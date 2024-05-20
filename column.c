#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
COLUMN *create_column(char* title) {
    COLUMN *col = (COLUMN*)malloc(sizeof(COLUMN));
    if (col != NULL) {
        col->title = strdup(title);
        col->values = NULL;
        col->size = 0;
    }
    return col;
}

int insert_value(COLUMN* col, int value) {
    if (col == NULL) return 0;

    int* new_values = (int*)realloc(col->values, (col->size + 1) * sizeof(int));
    if (new_values == NULL) return 0;

    col->values = new_values;
    col->values[col->size++] = value;
    return 1;
}

void delete_column(COLUMN **col) {
    if (col != NULL && *col != NULL) {
        free((*col)->title);
        free((*col)->values);
        free(*col);
        *col = NULL;
    }
}

void print_col(COLUMN* col) {
    if (col != NULL) {
        printf("Column: %s\n", col->title);
        printf("Values: ");
        for (int i = 0; i < col->size; i++) {
            printf("%d ", col->values[i]);
        }
        printf("\n");
    }
}
int countOccurrences(int array[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
            count++;
        }
    }
    return count;
}

int getValueAtIndex(int array[], int size, int index) {
    if (index >= 0 && index < size) {
        return array[index];
    } else {
        return -1;
    }
}

int countValuesGreaterThanX(int array[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > x) {
            count++;
        }
    }
    return count;
}

int countValuesLessThanX(int array[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < x) {
            count++;
        }
    }
    return count;
}

int countValuesEqualToX(int array[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == x) {
            count++;
        }
    }
    return count;


}