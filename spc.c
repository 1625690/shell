#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
   char str[80] = "Hola   Separar   Palabras   ajá";
   const char s[2] = " ";
   char *token;
   
   /* obtiene el primer token*/
   token = strtok(str, s);
   
   /* Recorre el puntero de tokens*/
   while( token != NULL ) {
      printf( " %s\n", token );    
      token = strtok(NULL, s);
   }
    return 0;
}
