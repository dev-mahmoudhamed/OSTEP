#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int *ptr = NULL;
    int value = &ptr;

    printf("%d\n", value);
    printf("%p\n", &ptr);
    return 0;
}
