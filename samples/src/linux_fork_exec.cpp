#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

const char *ch_proc_name = "./lge_exe";

int main(int argc, char *argv[])
{
    printf("lfe: process start\n");
    pid_t ch_pid = fork();
    if(ch_pid > 0) // parent process
    {
        printf("lfe: in parent process\n");
        printf("lfe: process return\n");
        return EXIT_SUCCESS;
    }
    else if (ch_pid < 0) // error
    {
        perror("lfe: error when fork()!\n");
        return EXIT_FAILURE;
    }
    else /* if (ch_pid == 0) */ // child process
    {
        printf("lfe: in child process\n");
        argv[0] = (char *)ch_proc_name;
        execv(argv[0], argv);
        // The exec() functions return only if an error has occurred.
        perror("lfe: error when execv()\n");
        return (EXIT_FAILURE + 1);
    }

    // we may wait for all child processes
    /* int status;
    pid_t wait_result;
    while ((wait_result = wait(&status)) != -1)
    {
        printf("Process %lu returned result: %d\n", (unsigned long) wait_result, status);
    }
    printf("All children have finished.\n"); */
    return EXIT_SUCCESS;
}
