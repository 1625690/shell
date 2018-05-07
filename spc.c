#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "spc.h";
int main()
{
    char str[] = "ls -al | sort";
    erspc(str);
    return 0;
}

char* erspc(char* ln){
	const char s[2] = " ";
	char* token = strtok(ln, s);
	return token;
}
