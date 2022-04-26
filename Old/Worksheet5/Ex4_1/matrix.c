#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "debug.h"

float **matrix_new(int n_rows, int n_cols)
{
	// Allocate an array of pointers, each pointer stores the memory address of the first index of an allocated array of floats
	float **matrix_rows = (float **)malloc(n_rows * sizeof(float*));
	
	if(matrix_rows == NULL)
	{
		ERROR(4,"Error allocating memory for the matrix's auxiliary array");
	}

	#ifdef SHOW_DEBUG
	DEBUG("Size of float*: %zu", sizeof(float*));
	DEBUG("Number of rows: %zu", n_rows);
	DEBUG("Total size: %zu\n", n_rows * sizeof(float*));
	#endif

	// For each index of the array of pointers, allocate an array of floats
	for(int i = 0; i < n_rows; ++i)
	{
		matrix_rows[i] = (float *)malloc(n_cols * sizeof(float));

		if(matrix_rows[i] == NULL)
		{
			ERROR(5,"Error allocating memory for the rows");
		}


		#ifdef SHOW_DEBUG
		DEBUG("Row memory address: %p", matrix_rows[i]);
		DEBUG("Row Number: %d", i);
		DEBUG("Size of each row: %zu\n", n_cols * sizeof(float));
		#endif
	}

	return matrix_rows;
}

void matrix_fill(float** matrix_rows, int n_rows, int n_cols, float value, char *string)
{
	printf("Setting all positions to %f on %s\n", value, string);

	// Loop through each row array and set the position to the specified value
	for(int i = 0; i < n_rows; ++i)
	{
		for(int j = 0; j < n_cols; ++j)
		{
			matrix_rows[i][j] = value;
		}
	}
}

void matrix_print(float** matrix_rows, int n_rows, int n_cols, char *string)
{
	printf("Printing all the positions' values of %s\n", string);

	// Loop through each row array print each position's value
	for(int i = 0; i < n_rows; ++i)
	{
		printf("[%f", matrix_rows[i][0]);
		for(int j = 1; j < n_cols; ++j)
		{
			printf(" | %f",matrix_rows[i][j]);
		}
		printf("]\n");
	}

	printf("\n");	
}

float **matrix_mul(float **matrix_1, float **matrix_2, int n_rows1, int n_columns1, int n_columns2)
{
	printf("Multiplying both matrices ... ");

	float **res = matrix_new(n_rows1, n_columns2);

	for(int i = 0; i < n_rows1; ++i)
	{
		for(int j = 0; j < n_columns2; ++j)
		{

			res[i][j] = 0;

			for(int k = 0; k < n_columns1; ++k)
			{
				res[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}

	printf("Ended\n");

	return res;
}

void matrix_del(float **matrix_rows, int n_rows, char *string)
{
	printf("Freeing space allocated to %s ... ", string);

	// Free each of the allocated rows
	for(int i = 0; i < n_rows; ++i)
	{
		free((void *)(matrix_rows[i]));
	}
	
	// Free array holding the pointer to each row
	free(matrix_rows);

	printf("Ended\n");
}
