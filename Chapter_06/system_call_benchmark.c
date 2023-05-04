#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main()
{
    FILE *fptr;
    char ch;
    struct timeval t0, t1;

    gettimeofday(&t0, 0);
    fptr = fopen("test.txt", "r");
    while (!feof(fptr))
    {
        ch = fgetc(fptr);
    }
    fclose(fptr);
    gettimeofday(&t1, NULL);

    long elapsed = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    printf("One system call takes %ld microseconds\n", elapsed);
    return 0;
}
