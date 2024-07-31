#include <stdio.h>
#include <stdlib.h>

#define FLAG_PATH "--path"

int strlen_k(char *str)
{
    if (*str == '\0')
        return 0;
    else
        return 1 + strlen_k(str + 1);
}

int strcmp_k(char *first_string, char *second_string)
{
    int flag = 1;
    while (*first_string != '\0' || *second_string != '\0')
    {
        if (*first_string == *second_string)
        {

            first_string++;
            second_string++;
        }
        else if ((*first_string == '\0' && *second_string != '\0') || (*first_string != '\0' && *second_string == '\0') || *first_string != *second_string)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int set_path(char *str)
{

    if (strcmp_k(str, FLAG_PATH) == 1)
    {
        return 1;
    }
    return 0;
}

int get_pos_last_bar(char *str)
{
    int total_bars = 0;
    int count_bars = 0;
    for (int i = 0; i < strlen_k(str); i++)
    {
        if (str[i] == '\\')
        {
            total_bars++;
        }
    }
    for (int i = 0; i < strlen_k(str); i++)
    {
        if (str[i] == '\\')
        {
            count_bars++;
            if (count_bars == total_bars)
            {
                return i;
            }
        }
    }
}

void concat_strings(char *str1, char *str2)
{

    while (*str1)
    {
        str1++;
    }
    while (*str2)
    {
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage --path <path>");
        exit(1);
    }

    char file_name[50];
    printf("Enter the name of the output: ");
    scanf("%s", file_name);

    concat_strings(file_name, " ");

    char *ptr_bytes = NULL;

    for (int i = 0; i < argc; i++)
    {
        if (set_path(argv[i]) == 1)
        {
            int size_str = strlen_k(argv[i + 1]) + 1;
            ptr_bytes = (char *)malloc(size_str * sizeof(char));
            if (ptr_bytes == NULL)
            {
                exit(1);
            }
            for (int j = 0; j < size_str; j++)
            {
                ptr_bytes[j] = argv[i + 1][j];
            }
            break;
        };
    };

    for (int i = 0; i < strlen_k(ptr_bytes); i++)
    {
        if (i == 0 && ptr_bytes[i] == '.' && ptr_bytes[i + 1] == '\\')
        {
            int post_last_bar = get_pos_last_bar(argv[0]);
            argv[0][post_last_bar + 1] = '\0';
            int i = post_last_bar + 1;
            int j = 0;
            int first_point = 0;
            int first_bar = 0;

            while (ptr_bytes[j] != '\0' && i < strlen_k(argv[0]) + strlen_k(ptr_bytes))
            {
                if (ptr_bytes[j] == '.' && !first_point)
                {
                    j++;
                    first_point = 1;
                    continue;
                }
                if (ptr_bytes[j] == '\\' && !first_bar)
                {
                    j++;
                    first_bar = 1;
                    continue;
                }
                argv[0][i] = ptr_bytes[j];
                i++;
                j++;
            }
            argv[0][i] = '\0';

            char comand[] = "gcc -o ";

            concat_strings(comand, file_name);
            concat_strings(comand, argv[0]);

            system(comand);
            break;
        }
        else
        {
            printf("not implemented");
            exit(1);
        }
    }

    free(ptr_bytes);
    ptr_bytes = NULL;
    return 0;
}

// gcc -o compilation-test .\main.c
//.\compilation-test.exe --path .\main.c
