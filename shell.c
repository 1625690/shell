#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char cmd[80];
	while(1){
		printf("$ ");
		scanf("%s",cmd);
		if(!strcmp("exit", cmd)){
			break;
		}	
	}
	return 0;
}