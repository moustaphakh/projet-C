#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

typedef struct {
    COLUMN **columns;
    int num_columns;  
    int capacity;     
} CDataframe;


CDataframe *create_cdataframe(int initial_capacity);
void delete_cdataframe(CDataframe *df);


void fill_cdataframe_with_input(CDataframe *df);
void hard_fill_cdataframe(CDataframe *df); 


void display_cdataframe(const CDataframe *df);
void display_partial_cdataframe(const CDataframe *df, int start_row, int end_row, int start_col, int end_col);


void add_row_to_cdataframe(CDataframe *df, int *row_values); 
void delete_row_from_cdataframe(CDataframe *df, int row_index);
void add_column_to_cdataframe(CDataframe *df, COLUMN *col); 
void delete_column_from_cdataframe(CDataframe *df, int col_index);
void rename_column_in_cdataframe(CDataframe *df, int col_index, char *new_title);
int search_value_in_cdataframe(const CDataframe *df, int value);
int replace_value_in_cdataframe(CDataframe *df, int row, int col, int new_value);


void display_cdataframe_stats(const CDataframe *df);

#endif // CDATAFRAME_H

