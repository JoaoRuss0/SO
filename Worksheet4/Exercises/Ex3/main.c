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
#include "function.h"

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	/* Main code */
    struct gengetopt_args_info args;

    if (cmdline_parser(argc, argv, &args) != 0) {
        ERROR(1, "Error parsing command line parameters.");
    }

    if(args.num_arg < 0) {
        ERROR(2, "Only positive integers are allowed.\n");
    }

    fprintf(stdout, "%d bytes are needed to represent %d.\n", bytes_for_int(args.num_arg), args.num_arg);

    cmdline_parser_free(&args);

	return 0;
}

