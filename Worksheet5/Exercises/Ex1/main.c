#include "debug.h"
#include "args.h"
#include "matrix.h"

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	/* Main code */
	struct gengetopt_args_info args;

	if(cmdline_parser(argc, argv, &args) != 0) {
		ERROR(11, "Could not parse command line arguments.");
	}

	int rows1 = args.rows_arg,
		cols1 = args.mul_arg,
		rows2 = args.mul_arg,
		cols2 = args.columns_arg;

	float value1 = args.value1_arg, value2 = args.value2_arg;

	float **matrix1 = matrix_new(rows1, cols1);
	matrix_fill(matrix1, rows1, cols1, value1);
	matrix_print(matrix1, rows1, cols1);

	float **matrix2 = matrix_new(rows2, cols2);
	matrix_fill(matrix2, rows2, cols2, value2);
	matrix_print(matrix2, rows2, cols2);

	float **matrix3 = matrix_mul(matrix1, rows1, cols1, matrix2, cols2);
	matrix_print(matrix3, cols1, rows2);

	matrix_delete(matrix1, rows1);
	matrix_delete(matrix2, rows2);
	matrix_delete(matrix3, rows2);

	cmdline_parser_free(&args);

	return 0;
}

