#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef struct {
	float **matrix;
	int n_columns;
	int n_rows;
} Matrix;

void matrix_new(Matrix *matrix, int n_rows, int n_columns);
void matrix_fill(Matrix *matrix, float value);
void matrix_delete(Matrix *matrix);
void matrix_print(Matrix *matrix);
void matrix_mul(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3);

#endif
