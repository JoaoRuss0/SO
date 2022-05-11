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

	int n_rows1 = args.rows_arg,
		n_columns1 = args.mul_arg,
		n_rows2 = args.mul_arg,
		n_columns2 = args.columns_arg;

	float value1 = args.value1_arg, value2 = args.value2_arg;

	Matrix matrix1;
    matrix_new(&matrix1, n_rows1, n_columns1);
	matrix_fill(&matrix1, value1);
	matrix_print(&matrix1);

	Matrix matrix2;
    matrix_new(&matrix2, n_rows2, n_columns2);
	matrix_fill(&matrix2, value2);
	matrix_print(&matrix2);

	Matrix matrix3;
    matrix_mul(&matrix1, &matrix2, &matrix3);
	matrix_print(&matrix3);

	matrix_delete(&matrix1);
	matrix_delete(&matrix2);
	matrix_delete(&matrix3);

	cmdline_parser_free(&args);

	return 0;
}

