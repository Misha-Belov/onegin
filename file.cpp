#include "onegin.h"

// char* read_file_name(const char* command[], int len)
// {
//     const char file[] = "--file";
//
//     for(int i = 0; i < len; i++)
//     {
//         if(!strcmp(command[i], file))
//         {
//             return (command[i + 1]);
//         }
//     }
//     return "no file";
// }

void read_from_file(char* file_name, int* num_str, char* arr_pointer[])
{
    FILE* file_onegin = fopen(file_name, "rb");

    struct stat st;
    stat(file_name, &st);
    size_t size = st.st_size;
    printf("size of file: %d\n", size);

    fseek(file_onegin, 0, SEEK_END);
    size = ftell(file_onegin);
    rewind(file_onegin);
    printf("size of file 2: %d\n", size);

    size_t num = 1;

    char* string = (char*) calloc((size + 1), sizeof(char));

    fread(string, sizeof(char), size, file_onegin);

    printf("%s", string);
    printf("\n");

    for (size_t i = 0; i < size; i++)
    {
        if(string[i] == '\r')
        {
            string[i] = '\0';
            i++;
            num++;
        }
    }


    arr_pointer = (char**) calloc(num, sizeof(char*));

    arr_pointer[0] = &string[0];
    for (size_t i = 0; i < size; i++)
    {
        if(string[i] == '\0')
        {
            arr_pointer[num] = &string[i + 2];
            num++;
        }
    }

    *num_str = num;

    free(string);
    fclose(file_onegin);
}
