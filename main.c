#include <stdio.h>
#include <stdlib.h>

// int strcmp_s(char *first_string, char second_string)
// {
//     printf(first_string);
//     printf(second_string);
//     return 1;
// }

void set_path(const char *str, int *ptr)
{
    char path[6];
    path[0] = "-";
    path[1] = "-";
    path[2] = "p";
    path[3] = "a";
    path[4] = "t";
    path[5] = "h";

    printf("pointer: %s\n", path);
    // printf("%s\n", str);
    // if (strcmp_s(str, '--path') != 0)
    // {
    //     printf("equal");
    // }
}

int main(int argc, char const *argv[])
{

    int bytes = 200 * 8;
    int *ptr_bytes;

    ptr_bytes = (int *)malloc(bytes * sizeof(char));

    if (ptr_bytes == NULL)
    {
        exit(0);
    }
    // printf("pointer: %d\n", ptr_bytes);
    printf("size aloccated: %d bytes\n", bytes * sizeof(char));
    printf("max characters to allocate: %d characters\n", ((bytes * sizeof(char)) / 8));

    for (int i = 0; i < argc; i++)
    {
        set_path(argv[i], ptr_bytes);
        // printf("%s\n", argv[i]);
    };

    free(ptr_bytes);
    ptr_bytes = NULL;
    return 0;
}

// gcc -o test .\main.c
