#include "onegin.h"

int main(int argc, char* argv[])
{
    int num_str;
    char* file_name = {};

    if (read_file_name(argv, argc, &file_name))
        printf("%s\n", file_name);


    char** arr_pointer = (char**) calloc(1, sizeof(char*));

    read_from_file(file_name, &num_str, arr_pointer);

    for (size_t i = 0; i < num_str; i++)
    {
        printf("%s", arr_pointer[i]);
    }

    sort_mas(arr_pointer, num_str);

    for (size_t i = 0; i < num_str; i++)
    {
        printf("%s", arr_pointer[i]);
    }

    sort_from_end(arr_pointer, num_str);

    for (size_t i = 0; i < num_str; i++)
    {
        printf("%s", arr_pointer[i]);
    }
    free (arr_pointer);
}


