#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CDataframe *create_cdataframe(int initial_capacity) {
    CDataframe *df = (CDataframe *)malloc(sizeof(CDataframe));
    if (df == NULL) {
        return NULL;
    }

    df->columns = (COLUMN **)malloc(initial_capacity * sizeof(COLUMN *));
    if (df->columns == NULL) {
        free(df);
        return NULL;
    }

    df->num_columns = 0;
    df->capacity = initial_capacity;
    return df;
}

void delete_cdataframe(CDataframe *df) {
    if (df != NULL) {
        for (int i = 0; i < df->num_columns; i++) {
            delete_column(&df->columns[i]);
        }
        free(df->columns);
        free(df);
    }
}

void hard_fill_cdataframe(CDataframe *df, int num_columns, int num_rows) {
    for (int i = 0; i < num_columns; i++) {
        char title[20];
        sprintf(title, "Column%d", i + 1);

        COLUMN *col = create_column(title);
        for (int j = 0; j < num_rows; j++) {
            insert_value(col, i * num_rows + j + 1);
        }
        add_column_to_cdataframe(df, col);
    }
}

void display_cdataframe(const CDataframe *df) {
    for (int i = 0; i < df->num_columns; i++) {
        print_col(df->columns[i]);
    }
}

void display_partial_cdataframe(const CDataframe *df, int start_row, int end_row, int start_col, int end_col) {
    for (int i = start_col; i <= end_col && i < df->num_columns; i++) {
        printf("Column: %s\n", df->columns[i]->title);
        printf("Values: ");
        for (int j = start_row; j <= end_row && j < df->columns[i]->size; j++) {
            printf("%d ", df->columns[i]->values[j]);
        }
        printf("\n");
    }
}

void add_row_to_cdataframe(CDataframe *df, int *row_values) {
    for (int i = 0; i < df->num_columns; i++) {
        insert_value(df->columns[i], row_values[i]);
    }
}

void delete_row_from_cdataframe(CDataframe *df, int row_index) {
    for (int i = 0; i < df->num_columns; i++) {
        COLUMN *col = df->columns[i];
        if (row_index < col->size) {
            for (int j = row_index; j < col->size - 1; j++) {
                col->values[j] = col->values[j + 1];
            }
            col->size--;
            col->values = (int *)realloc(col->values, col->size * sizeof(int));
        }
    }
}

void add_column_to_cdataframe(CDataframe *df, COLUMN *col) {
    if (df->num_columns >= df->capacity) {
        int new_capacity = df->capacity * 2;
        COLUMN **new_columns = (COLUMN **)realloc(df->columns, new_capacity * sizeof(COLUMN *));
        if (new_columns == NULL) {
            return;
        }
        df->columns = new_columns;
        df->capacity = new_capacity;
    }
    df->columns[df->num_columns] = col;
    df->num_columns++;
}

void delete_column_from_cdataframe(CDataframe *df, int col_index) {
    if (col_index < df->num_columns) {
        delete_column(&df->columns[col_index]);
        for (int i = col_index; i < df->num_columns - 1; i++) {
            df->columns[i] = df->columns[i + 1];
        }
        df->num_columns--;
    }
}

void rename_column_in_cdataframe(CDataframe *df, int col_index, char *new_title) {
    if (col_index < df->num_columns) {
        COLUMN *col = df->columns[col_index];
        free(col->title);
        col->title = strdup(new_title);
    }
}

int search_value_in_cdataframe(const CDataframe *df, int value) {
    for (int i = 0; i < df->num_columns; i++) {
        for (int j = 0; j < df->columns[i]->size; j++) {
            if (df->columns[i]->values[j] == value) {
                return 1;
            }
        }
    }
    return 0;
}

int replace_value_in_cdataframe(CDataframe *df, int row, int col, int new_value) {
    if (col < df->num_columns && row < df->columns[col]->size) {
        df->columns[col]->values[row] = new_value;
        return 1;
    }
    return 0;
}

void display_cdataframe_stats(const CDataframe *df) {
    printf("Number of rows: %zu\n", df->columns[0]->size);
    printf("Number of columns: %d\n", df->num_columns);
}

