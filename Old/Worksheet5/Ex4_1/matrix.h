#ifndef _MATRIX_H_
#define _MATRIX_H_

float **matrix_new(int n_rows, int n_cols);
void matrix_del(float **matrix_rows, int n_rows, char *string);
void matrix_fill(float** matrix_rows, int n_rows, int n_cols, float value, char *string);
void matrix_print(float** matrix_rows, int n_rows, int n_cols, char *string);
float **matrix_mul(float **matrix_1, float **matrix_2, int n_rows1, int n_columns1, int n_columns2);

#endif
