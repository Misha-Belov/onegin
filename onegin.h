#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>

void sort_mas(char* arr[], int len);
void sort_from_end(char* arr[], int len);
int strcmp_rev(char* s1, char* s2);
void read_from_file(char* file_name, int* num_str, char* arr_pointer[]);
bool read_file_name(char* command[], int len, char** file_name);
int comp(void* a, void* b);
void swap(void* a, void* b, int size);
void sort_all(void* arr, int (*comp)(void*, void*), int size, int number);
