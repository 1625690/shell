#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
   char str[] = "Hola   Separar   Palabras   ajá";
   char str2[] = "Este es   | un comando     |    con pipelines | as";
   const char s[2] = " ";
   char *token;
   
   /* obtiene el primer token*/
   token = strtok(str2, s);
   
   /* Recorre el puntero de tokens*/
   while( token != NULL ) {      
      
      if(strcmp("|", token)){
         printf( " %s\n", token );
      }
      token = strtok(NULL, s);
   }
    return 0;
}
