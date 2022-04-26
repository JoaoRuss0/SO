/**
* @file main.c
* @brief Description
* @date 2018-1-1
* @author name of author
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "debug.h"
#include "memory.h"
#include "args.h"
#include "matrix.h"
#include "debug.h"

int main(int argc, char *argv[])
{
	/* Disable warnings */
	(void)argc; (void)argv;

	/* Main code */
	struct gengetopt_args_info ai;
	
	if(cmdline_parser(argc, argv, &ai) != 0)
	{
		ERROR(1, "Could not parse command line arguments");
	}

	int n_rows1 = ai.rows1_arg;
	int n_rows2 = ai.rows2_arg;
	int n_columns1 = ai.columns1_arg;
	int n_columns2 = ai.columns2_arg;
	float value_1 = ai.value1_arg;
	float value_2 = ai.value2_arg;
	
	#ifdef SHOW_DEBUG
	DEBUG("Rows_1: %d Columns_1: %d", n_rows1, n_columns1);
	DEBUG("Rows_2: %d Columns_2: %d", n_rows2, n_columns2);
	DEBUG("Value_1: %f Value_2: %f\n", value_1, value_2);
	#endif

	if(n_rows1 <= 0 || n_columns1 <= 0 || n_rows2 <= 0 || n_columns2 <= 0)
	{
		ERROR(2, "Number of rows and columns must be 1 or more.");
	}

	if(n_columns1 != n_rows2)
	{
		ERROR(3, "Number of columns on matrix 1 and number of rows on matrix 2 has to be the same");
	}
	
	float **matrix_1 = matrix_new(n_rows1, n_columns1);
	float **matrix_2 = matrix_new(n_rows2, n_columns2);
	
	#ifdef SHOW_DEBUG
	DEBUG("Matrix_1: %p", matrix_1);
	DEBUG("Matrix_2: %p\n", matrix_2);
	#endif
	
	matrix_fill(matrix_1, n_rows1, n_columns1, value_1, "matrix_1");
	matrix_fill(matrix_2, n_rows2, n_columns2, value_2, "matrix_2");
	
	printf("\n");

	matrix_print(matrix_1, n_rows1, n_columns1, "matrix_1");
	matrix_print(matrix_2, n_rows2, n_columns2, "matrix_2");

	float **res = matrix_mul(matrix_1, matrix_2, n_rows1, n_columns1, n_columns2);
		
	printf("\n");

	matrix_print(res, n_rows1, n_columns2, "multiplication result matrix");

	matrix_del(matrix_1, n_rows1, "matrix_1");
	matrix_del(matrix_2, n_rows2, "matrix_2");
	matrix_del(res, n_rows1, "multiplication result matrix");

	return 0;
}

