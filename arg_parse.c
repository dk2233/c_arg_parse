#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "arg_parse.h"

void parser_arguments(int argc, char * argv[])
{
    #define START_ARGC_LOOP 1U

    uint8_t first_loop = 0;
    /* first loop suits a method of call no parameter function 
    that may have influence on other arguments*/
    for(int i = START_ARGC_LOOP; i < argc; i++)
    {

        for (int arg = 0; (arg_config[arg].function_to_parse.function_arg_char != NULL); arg++)
        {
            char *found_one_of_option = strstr(argv[i], arg_config[arg].parameter);

            if (found_one_of_option != NULL)
            {
                char *data_from_commandline = calloc(strlen((char *)&argv[i][0]) + 1 , sizeof(char));

                if (data_from_commandline != NULL)
                {
                    if((first_loop != 0 ) && (arg_config[arg].arg_without_value == 0) )
                    {
                        char *parameter_begin = (char *)argv[i] + strlen(arg_config[arg].parameter);
                        data_from_commandline = strcpy(data_from_commandline, parameter_begin);

                        if (strlen(data_from_commandline) < 1)
                        {
                            /* data is in next argv[]*/
                            i++;
                            data_from_commandline = (char *)realloc(data_from_commandline, strlen(argv[i]) + 1);
                            data_from_commandline = strcpy(data_from_commandline, argv[i]);
                        }

                        arg_config[arg].function_to_parse.function_arg_char(data_from_commandline);
                        free(data_from_commandline);
                    }
                    else if ( (first_loop == 0) && ( arg_config[arg].arg_without_value == 1 ) )
                    {
                        arg_config[arg].function_to_parse.function_arg_void();
                        
                    }
                    else
                    {
                        /* nothing*/
                    }
                }
                else 
                {
                    perror("Cannot allocate memory for \n");
                }
            }
        }

        /* check if last cmd parameter was reached and if first loop start from the beginning*/
        if ( (i == (argc -1 ) ) 
        && (first_loop < 1) )
        {
            i = START_ARGC_LOOP - 1;
            first_loop++;
        }
    }

    if (argc < 2)
    {
        int i = 0;
        while(arg_config[i].function_to_parse.function_arg_char != NULL)
        {
            printf("%s %s\n",arg_config[i].parameter,arg_config[i].help_str);
            i++;

        }

    }
}