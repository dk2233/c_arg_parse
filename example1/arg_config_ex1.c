#include "arg_parse.h"
/*
such include may have function definitions*/
#include "arg_functions.h"
#include <stdio.h>

extern void argument_array(char * argv_parameter);
extern void argument_sum(char * argv_parameter);
extern void set_global_option(void);


/* 
such specific array is needed to be created

name is important
also always leave one empty line*/
argument_config_t arg_config[] = {
    {"-a" ,  .function_to_parse.function_arg_char = argument_array, "give an array size to be listed", 0, 0, },
    {"-sum" ,  .function_to_parse.function_arg_char = argument_sum, "give a number you want to sum like -sum4+5",0, 0},
    {"-v" ,  .function_to_parse.function_arg_void = set_global_option, "if you need verbose info",1, 0},
    {"", NULL,  NULL, 0 , 0}, /* this line is a marker of last element*/

};
