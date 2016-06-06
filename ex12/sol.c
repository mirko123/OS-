#include <stdio.h> //printf
#include <unistd.h> //execl, execlp
#include <sys/types.h> // fork, getpid, getppid
#include <sys/wait.h> // wait
#include <stdlib.h> // exit
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]) {
    if (argc < 2) {
        exit(1);
    }

    char* command = argv[1];
    int status;
    if ( fork() > 0 ) {
        wait(&status);
    } else {
        if ( execlp(command, command, 0) == -1 ) {
            printf("Shit happened doing %s\n", command);
            exit(99);
        }
    }

    if (!status) {
        printf("Command name was %s", command);
    }

    return 0;
}
