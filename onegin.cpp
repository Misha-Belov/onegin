#include "onegin.h"

int main(int argc, const char* argv[])
{
    int num_str;
    char file_name[10] = "file.txt";//read_file_name(*argv, argc);
    char* arr_pointer[] = {};

    read_from_file(file_name, &num_str, arr_pointer);

//     for (size_t i = 0; i < num_str; i++)
//     {
//         printf("%s", arr_pointer[i]);
//     }
//
//     sort_mas(&arr_pointer, num_str);
//
//     for (size_t i = 0; i < num_str; i++)
//     {
//         printf("%s", arr_pointer[i]);
//     }
//
//     sort_from_end(&arr_pointer, num_str);
//
//     for (size_t i = 0; i < num_str; i++)
//     {
//         printf("%s", arr_pointer[i]);
//     }
}

void sort_mas(char* arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if(strcmp(arr[j], arr[j + 1]) > 0)
            {
                char* tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void sort_from_end(char* arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (strcmp_rev(arr[j], arr[j + 1]) > 0)
            {
                char* tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int strcmp_rev(char* s1, char* s2)
{
    int pos = 0, s1_size = 0, s2_size = 0, i = 0;

    while(s1[pos] != '\0')
    {
        s1_size++;
        pos++;
    }
    pos = 0;
    while(s2[pos] != '\0')
    {
        s2_size++;
        pos++;
    }

    for (i = 1; i <= s1_size || i <= s2_size; i++)
    {
        if (s1[s1_size - i] != s2[s2_size - i])
        {
            return (s1[s1_size - i] - s2[s2_size - i]);
        }
    }
    return 0;
}


