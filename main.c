#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <errno.h>

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
        exit(EXIT_FAILURE);
    }

    char *ptr_bytes = NULL;

    for (int i = 0; i < argc; i++)
    {
        if (set_path(argv[i]) == 1)
        {
            int size_str = strlen_k(argv[i + 1]) + 1;
            ptr_bytes = (char *)malloc(size_str * sizeof(char));
            if (ptr_bytes == NULL)
            {
                exit(EXIT_FAILURE);
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
            char *comand_ptr = NULL;
            comand_ptr = (char *)malloc(200);
            if (comand_ptr == NULL)
            {
                exit(EXIT_FAILURE);
            }

            char comand[] = "gcc -o ";

            for (int i = 0; i < strlen_k(comand); i++)
            {
                comand_ptr[i] = comand[i];
            }

            char file_name[50];
            printf("Enter the name of the output: ");
            scanf("%s", file_name);

            concat_strings(comand_ptr, file_name);
            concat_strings(comand_ptr, " ");
            concat_strings(comand_ptr, ptr_bytes);

            int post_last_bar = get_pos_last_bar(argv[0]);
            argv[0][post_last_bar + 1] = '\0';

            concat_strings(argv[0], "output");
            int mkdir_response = _mkdir(argv[0]);
            if (mkdir_response == -1)
            {
                //  errno 17 - FILE EXISTS
                if (errno == 17)
                {
                    char second_comand[] = "move ";
                    int result;
                    int pos_last_bar = get_pos_last_bar(ptr_bytes);
                    ptr_bytes[pos_last_bar + 1] = '\0';
                    concat_strings(ptr_bytes, file_name);
                    concat_strings(ptr_bytes, ".exe");

                    result = system(comand_ptr);

                    if (result == 0)
                    {
                        concat_strings(second_comand, ptr_bytes);
                        concat_strings(second_comand, " ");
                        concat_strings(second_comand, argv[0]);
                        system(second_comand);
                    }
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                char second_comand[] = "move ";
                int result;
                int pos_last_bar = get_pos_last_bar(ptr_bytes);
                ptr_bytes[pos_last_bar + 1] = '\0';
                concat_strings(ptr_bytes, file_name);
                concat_strings(ptr_bytes, ".exe");

                result = system(comand_ptr);

                if (result == 0)
                {
                    concat_strings(second_comand, ptr_bytes);
                    concat_strings(second_comand, " ");
                    concat_strings(second_comand, argv[0]);
                    system(second_comand);
                }
            }
            free(comand_ptr);
            comand_ptr = NULL;
            break;
        }
        else if (i == 0 && ptr_bytes[i] == 'C' && ptr_bytes[i + 1] == ':' && ptr_bytes[i + 2] == '\\')
        {

            char *comand_ptr = NULL;
            char comand[] = "gcc -o ";
            comand_ptr = (char *)malloc(200);
            if (comand_ptr == NULL)
            {
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < strlen_k(comand); i++)
            {
                comand_ptr[i] = comand[i];
            }

            char file_name[50];
            printf("Enter the name of the output: ");
            scanf("%s", file_name);

            concat_strings(comand_ptr, file_name);
            concat_strings(comand_ptr, " ");
            concat_strings(comand_ptr, ptr_bytes);

            int pos_last_bar = get_pos_last_bar(argv[0]);

            argv[0][pos_last_bar + 1] = '\0';
            concat_strings(argv[0], "output");

            int mkdir_response = _mkdir(argv[0]);
            if (mkdir_response == -1)
            {
                //  errno 17 - FILE EXISTS
                if (errno == 17)
                {
                    char second_comand[] = "move ";
                    int result;
                    int pos_last_bar = get_pos_last_bar(ptr_bytes);
                    ptr_bytes[pos_last_bar + 1] = '\0';
                    concat_strings(ptr_bytes, file_name);
                    concat_strings(ptr_bytes, ".exe");

                    result = system(comand_ptr);

                    if (result == 0)
                    {
                        concat_strings(second_comand, ptr_bytes);
                        concat_strings(second_comand, " ");
                        concat_strings(second_comand, argv[0]);
                        system(second_comand);
                    }
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                char second_comand[] = "move ";
                int result;
                int pos_last_bar = get_pos_last_bar(ptr_bytes);
                ptr_bytes[pos_last_bar + 1] = '\0';
                concat_strings(ptr_bytes, file_name);
                concat_strings(ptr_bytes, ".exe");

                result = system(comand_ptr);

                if (result == 0)
                {
                    concat_strings(second_comand, ptr_bytes);
                    concat_strings(second_comand, " ");
                    concat_strings(second_comand, argv[0]);
                    system(second_comand);
                }
            }

            free(comand_ptr);
            comand_ptr = NULL;
            break;
        }
    }

    free(ptr_bytes);
    ptr_bytes = NULL;
    return 0;
}
