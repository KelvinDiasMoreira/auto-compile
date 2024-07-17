#include <stdio.h>
#include <stdlib.h>

void set_path(const char *str, int *ptr)
{
    // printf("pointer: %d\n", ptr);
    printf("%s\n", str);
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
