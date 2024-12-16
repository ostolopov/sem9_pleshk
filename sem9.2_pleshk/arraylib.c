#include "arraylib.h"

int get_int(int *number, int min, int max){
        int check = 0, number_check, flag = 0;
        while(flag == 0){
                check = scanf("%d" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                                flag = 1;
                                break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                    printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                    scanf("%*[^\n]");
                                    flag = 0;
                                    break;
                                }
                                *number = number_check;
                                scanf("%*[^\n]");
                                flag = 1;
                                break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                                scanf("%*[^\n]");
                                flag = 0;
                                break;
                        
                }
        }
        return check;
}

void arr_inicialization (int **arr, int *arr_size)
{
    int arr_size_local = 0;
    printf("Введите размер массива: \n");
    get_int(&arr_size_local, 1, INT_MAX);
    *arr = realloc(*arr, *arr_size * sizeof(int));
    *arr_size = arr_size_local;
}



void arr_make (int **arr, int *arr_size)
{
    int arr_element;
    *arr = realloc(*arr, *arr_size * sizeof(int));
    for (int i = 0; i < *arr_size; i++)
    {
        printf("arr[%d] = ", i);
        get_int(&arr_element, INT_MIN, INT_MAX);
        (*arr)[i] = arr_element;
        
    }
}

void arr_print (int *arr, int arr_size)
{
    int arr_element = 0;
    for (int i = 0; i < arr_size; i++)
    {
        arr_element = arr[i];
        printf("arr[%d] = %d\n", i , arr_element);
    }
}

void arr_max (int *arr, int arr_size)
{
    int max = arr[0];
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = arr[i];
    }
    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Маскимальное значение: %d\n", max);
}

void arr_sort (int *arr, int arr_size)
{
    int *arr_local = malloc(arr_size * sizeof(int));
    for (int i = 0; i < arr_size; i++)
    {
        arr_local[i] = arr[i];
    }
    
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = 0; j < arr_size - i - 1; j++)
        {
            if (arr_local[j] > arr_local[j + 1])
            {
                int temp = arr_local[j];
                arr_local[j] = arr_local[j + 1];
                arr_local[j + 1] = temp;
            }
        }
    }
    arr_print(arr_local, arr_size);
    free(arr_local);
}

void arr_sum (int *arr, int arr_size)
{
    int sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum += arr[i];
    }
    printf("Сумма элементов: %d\n", sum);
}



