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

void parse(char *line, char **argline){
while (*line != '\0') { /* while not the end of the line */
	while(*line == ' ' || *line == '\t' || *line == '\n')
		*line++ = '\0'; /* if a space, make it \0 and save the position to argline */
		*argline++ = line;

	while(*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
		line++; /* if any other character, move on */
	}
*(argline-1) = '\0'; /* set the last character to \0 */
}


