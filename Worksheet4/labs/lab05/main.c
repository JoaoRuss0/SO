/**
 * Program exemplo_opt
 * Patricio R. Domingues, 2016.03.16
 */
#include <stdio.h>
#include <stdlib.h>
#include "args.h" /* created by gengetopt */

#define EXIT_CMDLINE_PARSER_ERROR (1)

int main(int argc, char *argv[]) {
    struct gengetopt_args_info args_info;
    if (cmdline_parser(argc, argv, &args_info) != 0) {
        exit(EXIT_CMDLINE_PARSER_ERROR);
    }

    if (args_info.nome_given) {
        printf("'nome' parameter detected: '%s'\n", args_info.nome_arg);
    }
    if (args_info.valor_given) {
        printf("'valor' parameter detected: '%d'\n", args_info.valor_arg);
    }
    if (args_info.idade_given) {
        printf("'idade' parameter detected: '%d'\n", args_info.idade_arg);
    }
    if (args_info.habitantes_given) {
        printf("'habitantes' parameter detected: '%ld'\n",
               args_info.habitantes_arg);
    }

    if (args_info.tonelagem_given) {
        printf("'tonelagem' parameter detected: '%f'\n",
               args_info.tonelagem_arg);
    }

    if (args_info.margem_given) {
        printf("'margem' parameter detected: '%f'\n", args_info.margem_arg);
    }

    /* Libertar dos recursos afetos ao gengetopt */
    cmdline_parser_free(&args_info);

    return EXIT_SUCCESS;
}
