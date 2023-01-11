#include <stdio.h>
#include "arg_parse.h"
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

bool create_array(void ** tab, int size_of_array, size_t size_of_one_element );

int main(int argc, char *argv[])
{
    parser_arguments(argc, argv);


    return 0;
}



void argument_array(char * argv_parameter)
{
        int nr;
        char *new_tab = NULL;

        nr = atoi(argv_parameter);

        if (nr>0)
        {
            printf("array size %d \n",nr);


            if (create_array((void **)&new_tab, nr, sizeof(char)) == true)
            {
                new_tab[0] = 10;
            }
            for(int i = 0 ; i < nr; i++ )
            {
                printf("%d\n",new_tab[i]);
            }
            create_array((void **)&new_tab, 0, 1);
        }

}
/*
this function allocates array and returns its pointer **

if call second time it should free buffer
*/
bool create_array(void ** tab, int size_of_array, size_t size_of_one_element )
{
    bool state = false;

    if ((*tab == NULL) && (size_of_array > 0))
    {
        *tab = calloc(size_of_array, size_of_one_element);
        if (*tab != NULL)
        {
            printf("array allocated %p \n", *tab);
            state = true;
        }
        else
        {
            printf("error\n");
            state = false;
        }
    }
    else
    {
    free(*tab);
    }

    return state;

}



void argument_sum(char *param)
{
    char *nr1 ;
    int iter = 0;
    int sum = 0;

    int *tab = (int*)calloc(2, sizeof(int));

    nr1 = strtok(param, "+");
    do 
    {
        if (nr1 == NULL)
        {
            break;
        }
        tab[iter] = atoi(nr1);
        sum += tab[iter];
        iter++;
        if (iter > 1)
        {
            tab = (int*)realloc( tab, (iter + 1)* sizeof(int));
        }

        nr1 = strtok(NULL,"+");

    }while (nr1 != NULL);

    printf("sum %d \n",sum);
    free(tab);


}