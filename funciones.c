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
	
	
	int p[2],k,n;

    char *primeraParte = strtok(comando, "|");
    char *segundaParte = strtok(NULL, "|");
    
    
    char *args1[80];
    char *args2[80];

    char *var;
    var = strtok(primeraParte," ") ;
    for (int i =0; var!=NULL; i++){
        args1[i]=var;
        k=i;
        var= strtok(NULL, " ");
    }

    args1[k+1] = NULL;
    printf("Flags1: %s\n",args1[0]);


    var = strtok(segundaParte," ") ;
    for (int i =0; var!=NULL; i++){
        args2[i]=var;
        n=i;
        var= strtok(NULL, " ");
    }

    args2[n+1] = NULL;
    printf("Flags2: %s\n", args2[0]);
	pipe(p);
	pid_t id = fork();

	if (id==0){
		printf("%s\n",primeraParte);
		dup2(p[1], STDOUT_FILENO);
    	close(p[0]);
  		execvp(args1[0], args1);
	}else{
		wait(NULL);
		printf("%s\n", segundaParte);
		dup2(p[0], STDIN_FILENO);
    	close(p[1]);
    	execvp(args2[0], args2);
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
		rdpipe();
	    //leerComando();
	    //comandoSimple();
	    //redireccion();
	}else{
	    wait(NULL);
	}
    }
   return 0;
}

