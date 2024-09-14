#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

void flag(){
	printf("\nFLAG\n\n");
}

struct messages{
	char** lang;
	char** msg;
};

struct messages* getInfo(){
	int nLangs = 0;
	scanf(" %d", &nLangs);
	// set space
	struct messages* result = calloc(1, sizeof(struct messages));
	result->lang = calloc(nLangs+1, sizeof(char*));
	result->msg = calloc(nLangs+1, sizeof(char*));
	for(int i=0; i<nLangs; i++){
		result->lang[i] = calloc(200, sizeof(char));
		result->msg[i] = calloc(200, sizeof(char));
	}
	//read data
	for(int i=0; i<nLangs; i++){
		scanf(" %200[^\n]", result->lang[i]);
		scanf(" %200[^\n]", result->msg[i]);
	}
	return result;
}

void sendMsg(struct messages* src){
	int reps = 0;
	scanf(" %d", &reps);
	for(int j=0; j<reps; j++){
		char* name = malloc(200* sizeof(char));
		scanf(" %200[^\n]", name);
		printf("%s\n", name);
		free(name);
		//get correct message
		char* lang = malloc(200* sizeof(char));
		scanf(" %200[^\n]", lang);
		bool found = false;
		int i=0;
		while(!found){
			found = 0 == strcmp(src->lang[i], lang);
			if(!found) i++;
		}
		printf("%s\n\n", src->msg[i]);
		free(lang);
	}
}

int main(){
	struct messages* info = getInfo();
	sendMsg(info);
	free(info);
	return 0;
}
