#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>

#define PROMPT "> "

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
    int number;
    char *str = readline(PROMPT);
    printf("Выберите регистр:\n(0) Нижний регистр.\n(1) Верхний регистр.\n");
    scanf("%d", &number);
    for (int i = 0; i < strlen(str); i++) {
        if (number == 0) {
            str[i] = tolower(str[i]);
        } else if (number == 1) {
            str[i] = toupper(str[i]);
        }
    }
    printf("%s\n", str);
    free(str);
}

void reverse_str (void)
{
    char *str = readline(PROMPT);
    int str_size = (int) strlen(str);
    for (int i = 0; i < str_size / 2; i++)
    {
        char temp = str[i];
        str[i] = str[str_size - 1 - i];
        str[str_size - 1 - i] = temp;
    }
    printf("%s\n", str);
    free(str);
}

void reverse_word(void)
{
    int count = 0;
    char *str = readline(PROMPT);
    int str_size = (int) strlen(str);
    char *result = malloc(str_size + 1);
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        int token_size = (int) strlen(token);
        for (int i = 0; i < token_size / 2; i++)
        {
            char temp = token[i];
            token[i] = token[token_size - 1 - i];
            token[token_size - 1 - i] = temp;
        }
        memcpy(result + count, token, token_size);
        count += token_size;
        result[count++] = ' ';
        token = strtok(NULL, " ");
    }
    result[count] = '\0';
    printf("%s\n", result);
    free(str);
    free(result);
}

int main(void) {
    int case_number = 0;
    printf("(1) Программа для выбора регистра.\n(2) Переворот строки.\n(3) Переворот слов в строке.\n(4) Очистить консоль.\n\n");
    while (get_int(&case_number, 0 ,4) != -1  && case_number != 0)
       {
           switch (case_number)
           {
               case 1:
                   register_func ();
                   break;
               case 2:
                   reverse_str();
                   break;
               case 3:
                   reverse_word();
                   break;
               case 4:
                   system("clear");
                   break;
               default:
                   printf("Жмакнули не ту кнопку\n");
                   break;
           }
           printf("(1) Программа для выбора регистра.\n(2) Переворот строки.\n(3) Переворот слов в строке.\n(4) Очистить консоль.\n\n");
       }
    
    return 0;
}
