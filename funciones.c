#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "spc.h"

char *args[99];
char comando[90];
int pid;

void ejecutar(){
     char *var;
     var = strtok(comando, " ");
     for (int i =0; var!=NULL; i++){
         args[i]=var;
         var= strtok(NULL, " ");
     }
     execvp(args[0], args);
}

int main(int argc, char const *argv[]){
   while (1){
	scanf(" %99[^\n]",comando);
	if (!strcmp("exit",comando)){
	   break;
	}

	pid = fork();

	if (!pid){
	    ejecutar();
	}else{
	    wait(NULL);
	}
    }
   return 0;
}

