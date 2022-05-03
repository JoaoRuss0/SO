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
#include "conta_letra.h"

int main(int argc, char *argv[]){
	/* Disable warnings */
	(void)argc; (void)argv;

	/* Main code */
    struct gengetopt_args_info args;

    if(cmdline_parser(argc, argv, &args) != 0) {
        ERROR(1, "Error parsing command line parameters.");
    }

    if (strlen(args.character_arg) != 1) {
        ERROR(2, "Character (-c/--character) parameter is too long.");
    }

    int count = count_character_in_word(args.character_arg[0], args.string_arg);
    fprintf(stdout , "The character '%c' appears %d times in '%s'.\n", args.character_arg[0], count, args.string_arg);

    cmdline_parser_free(&args);

    return 0;
}

