
int pipes()
{
        int     fd[2],
        pid_t   pid;


        pipe(fd);

        if((pid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(pid == 0)
        {     
                close(fd[0]); /*salida del primer argumento antes del pipe*/
		leerComando();
               
        }
        else
        {           
                close(fd[1]);
		/*entrada del segundo argumento*/
		leerComando();   
        }

        return(0);
}



