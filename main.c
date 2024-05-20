#include<stdio.h>
#include<stdlib.h>
#define REALOC_SIZE 256
#include "Cdataframe.c"
#include "column.c"
#include "cdataframe.h"
#include "column.h"

int main() {

    CDataframe *df = create_cdataframe(2);


    hard_fill_cdataframe(df,2,2);


    printf("Displaying the entire dataframe:\n");
    display_cdataframe(df);


    int new_row[] = {11, 12};
    add_row_to_cdataframe(df, new_row);
    printf("\nAfter adding a new row:\n");
    display_cdataframe(df);


    delete_row_from_cdataframe(df, 0);
    printf("\nAfter deleting the first row:\n");
    display_cdataframe(df);


    int new_col_values[] = {13, 14, 15};
    COLUMN *new_col = create_column("Column3");
    for (int i = 0; i < 3; i++) {
        insert_value(new_col, new_col_values[i]);
    }
    add_column_to_cdataframe(df, new_col);
    printf("\nAfter adding a new column:\n");
    display_cdataframe(df);


    delete_column_from_cdataframe(df, 1);
    printf("\nAfter deleting the second column:\n");
    display_cdataframe(df);


    rename_column_in_cdataframe(df, 0, "RenamedColumn1");
    printf("\nAfter renaming the first column:\n");
    display_cdataframe(df);


    int value_to_search = 14;
    int found = search_value_in_cdataframe(df, value_to_search);
    if (found) {
        printf("\nValue %d found in the dataframe.\n", value_to_search);
    } else {
        printf("\nValue %d not found in the dataframe.\n", value_to_search);
    }


    replace_value_in_cdataframe(df, 0, 1, 99);
    printf("\nAfter replacing a value in the dataframe:\n");
    display_cdataframe(df);


    printf("\nDataframe statistics:\n");
    display_cdataframe_stats(df);


    delete_cdataframe(df);

    return 0;
}

