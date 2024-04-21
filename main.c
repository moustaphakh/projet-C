//
// Created by Mousti on 3/29/2024.
//

#include "main.h"
#include<stdio.h>
#include<stdlib.h>
#define REALOC_SIZE 256
#include "functions.h"

int main() {
    COLUMN *col = create_column(char* title)
    insert_value(col);
    print_col(col);
    delete_column(&col);
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    printf("Occurrences de %d : %d\n", x, countOccurrences(arr, size, x));
    printf("Valeur à l'index %d : %d\n", x, getValueAtIndex(arr, size, x));
    printf("Nombre de valeurs supérieures à %d : %d\n", x, countValuesGreaterThanX(arr, size, x));
    printf("Nombre de valeurs inférieures à %d : %d\n", x, countValuesLessThanX(arr, size, x));
    printf("Nombre de valeurs égales à %d : %d\n", x, countValuesEqualToX(arr, size, x));






















    return 0;
}

