#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>


char *args[99];
char comando[90];
int pid;

void rdpipe(){
	
	
	int p[2];
	char * ln = 
	char * args[99] = strtok(comando," ") ;
	char * args1[99] = strtok(NULL," ") ;

	pipe(p);
	pid_t id = fork();

	if (id==0){
		dup2(p[1], STDOUT_FILENO);
    		close(p[0]);
    		leercomando();
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

void leerComando(){
     char *var = strtok(comando," ") ;
     for (int i =0; var!=NULL; i++){
         args[i]=var;
         var= strtok(NULL, " ");
     }
     execvp(args[0], args);
}

void comandoSimple(){
     leerComando();
}

void redireccion(){
    char *archivo = strtok(comando, ">");
    archivo = strtok(NULL, ">");
    close(STDOUT_FILENO);
    open(archivo, O_EXCL|O_CREAT|O_WRONLY, S_IRWXU);
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
	    //leerComando();
	    comandoSimple();
	    //redireccion();
	}else{
	    wait(NULL);
	}
    }
   return 0;
}

