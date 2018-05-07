#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *args[];
char cmd[90];

void rdpipe(char *cmd[]){
	
	
	int p[2];
	char * point = cmd;
	for()
	char * args[] = {"ls", "-la", NULL};
	char * args1[] = {"wc", "-l", NULL};

	pipe(p);
	pid_t id = fork();

	if (id==0){
		dup2(p[1], STDOUT_FILENO);
    	close(p[0]);
    	execvp(args[0], args);
	}
	pid_t id1 = fork();
	if(id1 == 0){
		dup2(p[0], STDIN_FILENO);
    	close(p[1]);
    	execvp(args1[0], args1);
	}else{
		wait(NULL);
	}
	close(p[0]);
	close(p[1]);
}

int main(){
	

	while(1){
		printf("$ ");
		scanf(" %99[^\n]",cmd);
		if(!strcmp("exit", cmd)){
			break;
		}
		pid_t id = fork();
		if(!id){
            rdpipe();
		}else{
			wait(NULL);
		}	
	}
	return 0;
}