#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <memory in MB>\n", argv[0]);
        return 1;
    }

    int memory = atoi(argv[1]);
    int size = memory * 1024 * 1024 / sizeof(int);
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    int i = 0;
    while (1)
    {
        arr[i] = i;
        i = (i + 1) % size;
    }

    return 0;
}