#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <readline/readline.h>

#define PROMPT "> "
#define MAX_STR_SIZE 81

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

void register_func (void)
{
    char str[MAX_STR_SIZE];
    int number;
    printf(PROMPT);
    scanf("%s", str);
    printf("Выберите регистр:\n(0) Нижний регистр.\n(1) Верхний регистр.\n");
    scanf("%d", &number);
    for (int i = 0; i < strlen(str); i++) {
        if (number == 0) {
            str[i] = tolower(str[i]);
        } else if (number == 1) {
            str[i] = toupper(str[i]);
        }
    }
    printf("%s", str);
}

int main(void) {
    int case_number = 0;
    printf("(1) Программа для выбора регистра.\n(2) Переворот строки.\n(3) Переворот слов в строке.\n\n");
    while (get_int(&case_number, 0 ,4) != -1  && case_number != 0)
       {
           switch (case_number)
           {
               case 1:
                   register_func ();
                   break;
               case 2:
                   
                   break;
               case 3:
                   
                   break;
               case 4:
                   system("clear");
                   break;
               default:
                   printf("Жмакнули не ту кнопку\n");
                   break;
           }
           printf("(1) Программа для выбора регистра.\n(2) Переворот строки.\n(3) Переворот слов в строке.\n\n");
       }
    
    return 0;
}
