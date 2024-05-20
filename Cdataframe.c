#include "cdataframe.h"
#include <stdio.h>


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

