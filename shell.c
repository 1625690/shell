#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	char cmd[80];
	while(1){
		printf("$ ");
		scanf("%s",cmd);
		if(!strcmp("exit", cmd)){
			break;
		}
		pid_t id = fork();
		if(!id){
			char * args[2];
			args[0] = strdup(cmd);
			args[1] = NULL;
			execvp(args[0], args);
		}else{
			wait(NULL);
		}	
	}
	return 0;
}