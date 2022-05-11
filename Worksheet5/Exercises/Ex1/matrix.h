#ifndef __MATRIX_H__
#define __MATRIX_H__

float** matrix_new(int n_rows, int n_columns);
void matrix_fill(float **matrix, int n_rows, int n_columns, float value);
void matrix_delete(float **matrix, int n_rows);
void matrix_print(float **matrix, int n_rows, int n_columns);
float** matrix_mul(float **matrix1, int n_rows1, int n_columns1, float **matrix2, int n_columns2);

#endif
