#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(int argc, char* argv[]) 
{
    int status;
    switch(fork()) 
    {
        case -1:
            perror("fork");
            return 1;
        case 0:
            if ( execvp(argv[1], &argv[1]) == -1 ) 
            {
                perror("execl");
                return 1;
            }
            break;
        default:
            if (wait(&status) >= 0)
            {
                if (WIFEXITED(status))
                {
                    printf("%d \n", WEXITSTATUS(status));
                }
            }
            break;
    }
    return 0;
}
