#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "matrix.h"

void matrix_new(Matrix *matrix, int n_rows, int n_columns) {
	matrix->matrix = (float **) malloc(sizeof(float *) * n_rows);
    matrix->n_rows = n_rows;
    matrix->n_columns = n_columns;

	if(matrix == NULL) {
		ERROR(10, "Failed to allocated memory for matrix's row array.");
	}

	for (int i = 0; i < n_rows; ++i) {
		matrix->matrix[i] = (float *) malloc(sizeof(float) * n_columns);

		if(matrix->matrix[i] == NULL) {
			ERROR(20, "Failed to allocate memory for row %d.", i);
		}
	}

	fprintf(stdout, "New %dx%d matrix\n", n_rows, n_columns);
}

void matrix_fill(Matrix *matrix, float value) {
	fprintf(stdout, "Filling matrix with '%.2f'\n", value);

	for (int i = 0; i < matrix->n_rows; ++i) {
		for (int j = 0; j < matrix->n_columns; ++j) {
			matrix->matrix[i][j] = value;
		}
	}
}

void matrix_delete(Matrix *matrix) {
	fprintf(stdout, "Freeing matrix's rows ...\n");

	for (int i = 0; i < matrix->n_rows; ++i) {
		free(matrix->matrix[i]);
		fprintf(stdout, "\tRow %d done\n", i);
	}

	fprintf(stdout, "\n");
}

void matrix_print(Matrix *matrix) {
	fprintf(stdout, "Printing matrix ...\n");

	for (int i = 0; i < matrix->n_rows; ++i) {
		fprintf(stdout, "[");

		for (int j = 0; j < matrix->n_columns; ++j) {
			fprintf(stdout, " %.2f", matrix->matrix[i][j]);
		}

		fprintf(stdout, "]\n");
	}

	fprintf(stdout, "\n");
}

void matrix_mul(Matrix *matrix1, Matrix *matrix2, Matrix *matrix3) {
    matrix_new(matrix3, matrix1->n_rows , matrix2->n_columns);

    fprintf(stdout, "Multiplying matrices ...\n");

	for (int i = 0; i < matrix1->n_rows; ++i) {
		for (int j = 0; j < matrix2->n_columns; ++j) {
			for (int k = 0; k < matrix1->n_columns; ++k) {
				matrix3->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
			}
		}
	}
}