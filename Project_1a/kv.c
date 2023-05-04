#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

FILE *fptr;

char *truncString(char *str, int pos);
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        exit(0);
    }

    int i = 1;
    fptr = fopen("database.txt", "a+");

    while (argv[i] != NULL)
    {
        printf(argv[i]);
        switch ((argv[i])[0])
        {
        case 'p':
            put(argv[i]);
            i++;
            break;
        case 'g':
            get(argv[i]);
            break;
        case 'd':
            delete (argv[i]);
            break;
        case 'c':
            clear();
            break;
        case 'a':
            all();
            break;
        default:
            break;
        }
    }
    fclose(fptr);
}

void put(char *data)
{
    char *str = strdup(data);
    char *put_str = truncString(strdup(str), 2);
    fprintf(fptr, "%s\n", put_str);
}

void get(char *argv)
{
    char *input_str = strdup(argv);
    char *id_str = truncString((input_str), 2);
    int key = atoi(id_str);

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fptr) != -1)
    {
        char *str = strdup(line);
        char *id = strsep(&str, ",");
        if (atoi(id) == key)
        {
            printf("%s", line);
        }
    }
}

void delete(char *argv)
{
    char *input_str = strdup(argv);
    char *id_str = truncString((input_str), 2);
    int key = atoi(id_str);

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fptr) != -1)
    {
        char *str = strdup(line);
        char *id = strsep(&str, ",");
        if (atoi(id) == key)
        {
            fseek(fptr, 0, SEEK_CUR);
            // int len = ftell(fptr);
            char str[] = " ";
            fwrite(str, 1, sizeof(str), fptr);
        }
    }
}

void clear()
{
    fptr = fopen("database.txt", "w");
}

void all()
{
    char buffer[BUFFER_SIZE];

    fptr = fopen("database.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, fptr) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fptr);

    return 0;
}

char *truncString(char *str, int pos)
{
    size_t len = strlen(str);

    if (len > abs(pos))
    {
        if (pos > 0)
            str = str + pos;
        else
            str[len + pos] = 0;
    }
    return str;
}