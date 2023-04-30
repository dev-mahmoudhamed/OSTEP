#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main()
{
    FILE *fptr;
    char ch;
    struct timeval start, end;

    gettimeofday(&start, 0);
    fptr = fopen("test.txt", "r");
    while (!feof(fptr))
    {
        ch = fgetc(fptr);
    }
    fclose(fptr);
    gettimeofday(&end, 0);

    printf("Time taken to proccess file : %ld micro seconds\n",
           ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
    return 0;
}
