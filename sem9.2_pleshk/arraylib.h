#ifndef arraylib_h
#define arraylib_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_int(int *number, int min, int max);
void arr_inicialization (int **arr, int *arr_size);
void arr_make (int **arr, int *arr_size);
void arr_print (int *arr, int arr_size);
void arr_max (int *arr, int arr_size);
void arr_sort (int *arr, int arr_size);
void arr_sum (int *arr, int arr_size);

#endif

