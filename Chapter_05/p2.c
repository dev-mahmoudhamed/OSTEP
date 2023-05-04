#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("hello world (pid:%d)\n", getpid());
    int rc = fork();
    printf("Fork rc = %d\n", rc);

    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if (rc == 0)
    {
        printf("hello, I am child (pid:%d)\n", getpid());
    }
    else
    {
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (my pid:%d)\n", rc, rc_wait, getpid());
    }

    return 0;
}