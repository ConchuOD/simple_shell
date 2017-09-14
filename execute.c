/**
Conor Dooley
14321611
conor.dooley@ucdconnect.ie
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "myheader.h"

void  execute(char **argline){
pid_t pid;
int status;

if ((pid = fork()) < 0){     /* create a child process */
	printf("ERROR: forking child process failed\n");
	exit(EXIT_FAILURE);
	}
else if (pid == 0){          
	if (execvp(*argline, argline) < 0) {     /* execute the command */
		printf("ERROR: exec failed\n");
		exit(EXIT_FAILURE);
		}
	}
else{
	while (wait(&status) != pid); /* parent waits for child to complete */
	}
}
