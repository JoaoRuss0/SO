#ifndef __MATRIX_H__
#define __MATRIX_H__

float** matrix_new(int n_rows, int n_cols);
void matrix_fill(float **matrix, int n_rows, int n_cols, float value);
void matrix_delete(float **matrix, int n_rows);
void matrix_print(float **matrix, int n_rows, int n_cols);
float** matrix_mul(float **matrix1, int n_rows1, int n_cols1, float **matrix2, int n_cols2);

#endif
