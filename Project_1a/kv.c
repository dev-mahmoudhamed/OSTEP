#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE

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
            break;
        case 'a':
            break;
        default:
            break;
        }

        break;
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
    char *key = atoi(id_str);

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
    char *key = atoi(id_str);

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fptr) != -1)
    {
        char *str = strdup(line);
        char *id = strsep(&str, ",");
        if (atoi(id) == key)
        {
            strcat(line, "World!");
            printf(line);
        }
    }
}

void clear()
{
}

void all()
{
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