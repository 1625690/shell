#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ejecutar(char cmd[]){
	 char *args[99];
     char *var = strtok(cmd, " ");     
     for (int i =0; var!=NULL; i++){
     	puts(var);
         args[i]=var;
         var= strtok(NULL, " ");
     }
     execvp(args[0], args);
}

int main(){
	
	char cmd[90];
	while(1){
		printf("$ ");
		scanf(" %99[^\n]",cmd);
		if(!strcmp("exit", cmd)){
			break;
		}
		pid_t id = fork();
		if(!id){
            ejecutar(cmd);
		}else{
			wait(NULL);
		}	
	}
	return 0;
}

