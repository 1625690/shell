#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>


char *args[99];
char comando[90];
int pid;

void leerComando(){
     char *var = strtok(comando," ") ;
     for (int i =0; var!=NULL; i++){
         args[i]=var;
         var= strtok(NULL, " ");
     }
     execvp(args[0], args);
}

void comandoSimple(){
     char *var;
     const char op[] = " ";
     var = strtok(comando, op);
     leerComando();
}

void redireccion(){
    char *archivo = strtok(comando, ">");
    archivo = strtok(NULL, ">");
    close(STDOUT_FILENO);
    open(archivo, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    leerComando();
}

int main(int argc, char const *argv[]){
   while (1){
	scanf(" %99[^\n]",comando);
	if (!strcmp("exit",comando)){
	   break;
	}

	pid = fork();

	if (!pid){
	    redireccion();
	}else{
	    wait(NULL);
	}
    }
   return 0;
}

