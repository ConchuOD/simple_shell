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

void my_cd(char **args){
if (args[1] == NULL) { /* if no location is given then throw error */
	fprintf(stderr, "# - expected argument to \"cd\"\n");
	} 
else {
	if (chdir(args[1]) != 0) { /* if chdir has an error, then use perror to print it  */
		perror("# - cd:");
		}
	}
}

