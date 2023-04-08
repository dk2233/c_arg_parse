#ifndef ARG_PARSE_H 
#define ARG_PARSE_H


typedef struct argument_config_structure
{
    char * parameter;
    union {
        void (*function_arg_char) (char *argv_parameter); 
        void (*function_arg_void) (void); 
        } function_to_parse;
    char * help_str;
    unsigned char arg_without_value:1;
    unsigned char reserved:7;
}
argument_config_t; 

extern argument_config_t arg_config[];

extern void parser_arguments(int argc, char * argv[]);

#endif