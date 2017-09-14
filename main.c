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
  
time_t rawtime; 
struct tm *info;
char buffer[80];
  
typedef void (*sighandler_t)(int);
void handle_signal(int signo){
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer,80,"%d/%m %R", info);
	printf("\n[%s] # ", buffer);
	fflush(stdout);
}

int main(int argc, char **argv){	
char  *argline[64];
char *line = NULL;
ssize_t bufsize = 0; 
   
time(&rawtime);
  
signal(SIGINT, handle_signal);
while(1){
	info = localtime(&rawtime );
	strftime(buffer,80,"%d/%m %R", info);
	printf("[%s] # ", buffer);/* print the time in the format given by strftime */
		if(getline(&line, &bufsize, stdin)==-1){/* read in the line entered by the user */
		printf("\n");
		break; 
		}
	printf("\n");
	parse(line, argline);/* send it off to be parsed */  
	if (strcmp(argline[0], "cd") == 0) {/* if command is cd, then execute builtin, otherwise pass arguments to execute */
		my_cd(argline);
		}
	else{ 
		execute(argline);
		}
	}
  
return EXIT_SUCCESS;
}
