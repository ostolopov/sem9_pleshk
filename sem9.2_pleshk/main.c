#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "arraylib.h"


int main(void) {
    int *arr = NULL;
    int arr_size = 0;
    int case_number = 0;
    bool arr_inicialized = false;
    bool arr_filled = false;
    printf("(1) Создать массив.\n(2) Ввести массив.\n(3) Найти максимум.\n(4) Найти сумму.\n(5) Отсортировать.\n(6) Вывести массив.\n(7) Удалить массив.\n(8) Выход из программы\n(9) Очистить консоль.\n\n");
    while (get_int(&case_number, 1 ,9) != -1  && case_number != 0)
        {
            switch (case_number)
            {
                case 1:
                    if (arr_inicialized == true)
                    {
                        printf("Массив уже инициализирован.\n");
                        break;
                    }
                    arr_inicialization (&arr, &arr_size);
                    arr_inicialized = true;
                    arr_filled = false;
                    break;
                case 2:
                    if (arr_inicialized == false)
                    {
                        printf("Массив не инициализирован.\n");
                        break;
                    }
                    arr_make (&arr, &arr_size);
                    arr_filled = true;
                    break;;
                case 3:
                    if (arr_filled == false)
                    {
                        printf("Массив не заполнен.\n");
                        break;
                    }
                    arr_max (arr, arr_size);
                    break;
                case 4:
                    if (arr_filled == false)
                    {
                        printf("Массив не заполнен.\n");
                        break;
                    }
                    arr_sum (arr, arr_size);
                    break;
                case 5:
                    if (arr_filled == false)
                    {
                        printf("Массив не заполнен.\n");
                        break;
                    }
                    arr_sort (arr, arr_size);
                    break;
                case 6:
                    if (arr_filled == false)
                    {
                        printf("Массив не заполнен.\n");
                        break;
                    }
                    arr_print (arr, arr_size);
                    break;
                case 7:
                    if (arr_inicialized == true)
                    {
                        printf("Массив удален.\n");
                        arr_inicialized = false;
                        arr_filled = false;
                        free(arr);
                        arr = NULL;
                    } else
                    {
                        printf("Массив не инициализирован\n");
                    }
                    break;
                case 8:
                    printf("Завершение программы\n");
                    return 0;
                    break;
                case 9:
                    system("clear");
                    break;
                default:
                    printf("Жмакнули не ту кнопку\n");
                    break;
            }
            printf("(1) Создать массив.\n(2) Ввести массив.\n(3) Найти максимум.\n(4) Найти сумму.\n(5) Отсортировать.\n(6) Вывести массив.\n(7) Удалить массив.\n(8) Выход из программы\n(9) Очистить консоль.\n\n");
        }
        free(arr);
    return 0;
}
