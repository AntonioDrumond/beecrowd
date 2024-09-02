#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** separate(char* line){
	char** result = calloc(50, sizeof(char**));
	int i=0;
	result[i] = strtok(line, " ");
	while(result[i] != NULL){
		i++;
		result[i] = strtok(NULL, " ");
	}
	return result;
}

void swap(char** a, char** b){
	char* tmp = *a;
	*a = *b;
	*b = tmp;
}

char** sort(char** line, int n){
	if(n<1)
		return line;
	for(int i=0; i<n; i++){
		if(strlen(line[i]) < strlen(line[i+1]))
			swap(&line[i], &line[i+1]);
	}
	return sort(line, n-1);
}

/*
int main(){
	char* or = calloc(50, sizeof(char));
	strcpy(or, "top coder comp wedn at midnight");
	char** sep = separate(or);
	int n = 0;
	for(n=0; sep[n]!=NULL; n++);
	sort(sep, n-1);
	int i=0;
	while(sep[i]!=NULL){
		printf("%s\n", sep[i]);
		i++;
	}
	getchar();
	return 0;
}*/

int main(){
	int amnt = 0;
	scanf(" %d", &amnt);
	for(int e=0; e<amnt; e++){
		char* line = calloc(500, sizeof(char));
		scanf(" %1000[^\n]", line);
		char** sep = separate(line);
		int n=0;
		for(n=0; sep[n]!=NULL; n++);
		sort(sep, n-1);
		int i=0;
		while(sep[i]!=NULL){
			printf("%s ", sep[i]);
			i++;
		}
		free(sep);
		free(line);
		printf("\n");
	}
	return 0;
}
