#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(int argc, char **argv)
{
    struct arguments arguments;
    arguments.in = 0;
    arguments.proto = NULL;
    arguments.srcip = NULL;
    arguments.destip = NULL;
    arguments.srcnetmask = NULL;
    arguments.port = 0;
    arguments.action = NULL;
    arguments.print = 0;
    arguments.del = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    if (arguments.print){
        printf("print\n");
    }

    if (arguments.del){
        int delete = atoi(arguments.del);
        printf("deleting rule: %d\n", delete);
    }

    if (arguments.in){
        printf("--in\n");

        /*
        TODO
        */

    }

    return 0;
}