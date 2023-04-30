#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Hello world (pid:%d)\n", getpid());
    int rc = fork();
    printf("Fork rc = %d\n", rc);
    if (rc < 0)
    {
        fprintf(stderr, "s\n");
        exit(1);
    }
    if (rc == 0)
    {
        printf("Hello , I am child (pid:%d)\n", getpid());
    }
    else
    {
        printf("hello, I am parent of {%d} (my pid:%d)\n", rc, (int)getpid());
    }

    return 0;
}