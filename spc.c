#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
   char str2[] = "Estees|  uncomando|  con pipelines |ok";
   const char s[2] = " ";
   char *token;
   
   /* obtiene el primer comando quitando los espacios vacios*/
   token = strtok(str2, s);
   
   /* error si el primer char es | */
   if(!strcmp("|", token)){
      printf("No se puede empezar un comando con | ");
   }else{
      /* Recorre la linea de comando */
      while( token != NULL ) {           
         /* Guarda el comando */
         char *cmd = token;
         /* puntero que se usara para recorrer el comando */
         char *p;
         char *ins;
         char **linea;
         /* Recorre el comando letra por letra */
         for(p = cmd; *p != '\0'; p++){
             if(*p != '|'){

             }
        }
        /* incremento del puntero que recorre la linea */
        token = strtok(NULL, s);
      }
   }
    return 0;
}
