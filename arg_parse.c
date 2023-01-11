#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "arg_parse.h"

void parser_arguments(int argc, char * argv[])
{
    for(int i = 1; i < argc; i++)
    {

        for (int arg = 0; (arg_config[arg].function_to_parse.function_arg_array != NULL); arg++)
        {
            char *found = strstr(argv[i], arg_config[arg].parameter);

            if (found != NULL)
            {
                char *number = calloc(strlen((char *)&argv[i][0]) + 1 , sizeof(char));

                if (number != NULL)
                {
                    char *parameter_begin = (char *)argv[i] + strlen(arg_config[arg].parameter);
                    number = strcpy(number, parameter_begin);

                    arg_config[arg].function_to_parse.function_arg_array(number);
                    free(number);
                }
            }
        }
    }

    if (argc < 2)
    {
        int i = 0;
        while(arg_config[i].function_to_parse.function_arg_array != NULL)
        {
            printf("%s %s\n",arg_config[i].parameter,arg_config[i].help_str);
            i++;

        }

    }
}