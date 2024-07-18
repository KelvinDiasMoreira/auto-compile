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

int main(int argc, char *argv[])
{
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

    printf("%s\n", ptr_bytes);

    free(ptr_bytes);
    ptr_bytes = NULL;
    return 0;
}

// gcc -o test .\main.c
