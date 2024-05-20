#include<stdio.h>
#include<stdlib.h>
#define REALOC_SIZE 256
#include "Cdataframe.c"
#include "column.c"

int main() {
    COLUMN *col = create_column("First col");
    insert_value(col,2);
    print_col(col);
    delete_column(&col);
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    printf("Occurrences de %d : %d\n", x, countOccurrences(arr, size, x));
    printf("Valeur a l'index %d : %d\n", x, getValueAtIndex(arr, size, x));
    printf("Nombre de valeurs superieures a %d : %d\n", x, countValuesGreaterThanX(arr, size, x));
    printf("Nombre de valeurs inferieures a %d : %d\n", x, countValuesLessThanX(arr, size, x));
    printf("Nombre de valeurs egales a %d : %d\n", x, countValuesEqualToX(arr, size, x));






















    return 0;
}

