#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *args[];
char cmd[90];

void ejecutar(){
	 
     char *var = strtok(cmd, " ");     
     for (int i =0; var!=NULL; i++){
         args[i]=var;
         var= strtok(NULL, " ");
     }
     execvp(args[0], args);
}

void rdpipe(){
	
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
            ejecutar();
		}else{
			wait(NULL);
		}	
	}
	return 0;
}

