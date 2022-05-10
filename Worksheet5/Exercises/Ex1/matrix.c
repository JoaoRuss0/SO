#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "matrix.h"

float** matrix_new(int n_rows, int n_cols) {
	float **matrix = (float **) malloc(sizeof(float *) * n_rows);

	if(matrix == NULL) {
		ERROR(10, "Failed to allocated memory for matrix's row array.");
	}

	for (int i = 0; i < n_rows; ++i) {
		matrix[i] = (float *) malloc(sizeof(float) * n_cols);

		if(matrix[i] == NULL) {
			ERROR(20, "Failed to allocate memory for row %d.", i);
		}
	}

	fprintf(stdout, "New %dx%d matrix\n", n_rows, n_cols);

	return matrix;
}

void matrix_fill(float **matrix, int n_rows, int n_cols, float value) {
	fprintf(stdout, "Filling matrix with '%.2f'\n", value);

	for (int i = 0; i < n_rows; ++i) {
		for (int j = 0; j < n_cols; ++j) {
			matrix[i][j] = value;
		}
	}
}

void matrix_delete(float **matrix, int n_rows) {
	fprintf(stdout, "Freeing matrix's n_rows ...\n");

	for (int i = 0; i < n_rows; ++i) {
		free(matrix[i]);
		fprintf(stdout, "\tRow %d done\n", i);
	}

	fprintf(stdout, "\n");
}

void matrix_print(float **matrix, int n_rows, int n_cols) {
	fprintf(stdout, "Printing matrix ...\n");

	for (int i = 0; i < n_rows; ++i) {
		fprintf(stdout, "[");

		for (int j = 0; j < n_cols; ++j) {
			fprintf(stdout, " %.2f", matrix[i][j]);
		}

		fprintf(stdout, "]\n");
	}

	fprintf(stdout, "\n");
}

float** matrix_mul(float **matrix1, int n_rows1, int n_cols1, float **matrix2, int n_cols2) {
	float **matrix3 = matrix_new(n_rows1, n_cols2);

	for (int i = 0; i < n_rows1; ++i) {
		for (int j = 0; j < n_cols2; ++j) {
			for (int k = 0; k < n_cols1; ++k) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return matrix3;
}