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

void set_path(char *str, int *ptr)
{

    if (strcmp_k(str, FLAG_PATH) == 1)
    {
        printf("%s\n", str);
    }
}

int main(int argc, char *argv[])
{

    int bytes = 200 * 8;
    int *ptr_bytes;

    ptr_bytes = (int *)malloc(bytes * sizeof(char));

    if (ptr_bytes == NULL)
    {
        exit(0);
    }
    printf("size allocated: %d bytes\n", bytes * sizeof(char));
    printf("max characters to allocate: %d characters\n", ((bytes * sizeof(char)) / 8));

    for (int i = 0; i < argc; i++)
    {
        set_path(argv[i], ptr_bytes);
    };

    free(ptr_bytes);
    ptr_bytes = NULL;
    return 0;
}

// gcc -o test .\main.c
