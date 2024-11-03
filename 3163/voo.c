#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

typedef struct Cell Cell;
typedef struct Cell{
	char* name;
	Cell* next;
} Cell;

typedef struct {
	Cell* fim;
	Cell* ini;
	int n;
} Stack;

Cell* newCell(char* plane){
	Cell* ret = calloc(1, sizeof(Cell));
	if(plane==NULL)
		ret->name = NULL;
	else{
		ret->name = malloc(10*sizeof(char));
		strcpy(ret->name, plane);
	}
	ret->next = NULL;
	return ret;
}

void delCell(Cell* d){
	if(d->next != NULL) delCell(d->next);
	if(d->name != NULL) free(d->name);
	free(d);
}

Stack* newStack(){
	Stack* ret = calloc(1, sizeof(Stack));
	ret->ini = newCell(NULL);
	ret->fim = ret->ini;
	ret->n = 0;
	return ret;
}

void delStack(Stack* d){
	if(d!=NULL && d->ini!=NULL) delCell(d->ini);
	d->fim = NULL;
	d->ini= NULL;
	free(d);
}

void push(Stack* s, char* plane){
	Cell* tmp = newCell(plane);
	s->fim->next = tmp;
	s->fim = tmp;
	s->n++;
}

void pushCell(Stack* s, Cell* c){
	s->fim->next = c;
	s->fim = c;
	s->n++;
}

void pop(Stack* s, Stack* general){
	if(s->n > 0){
		Cell* tmp = s->ini->next;
		s->ini->next = s->ini->next->next;
		s->n--;
		tmp->next = NULL;
		pushCell(general, tmp);
	}
}

void printStackCall(Cell* current){
	if(current->name != NULL) printf("%s ", current->name);
	if(current->next!=NULL && current->next->name!=NULL) printStackCall(current->next);
}

void printStack(Stack* s){
	if(s!=NULL && s->ini!=NULL) printStackCall(s->ini);
}

bool equals(const char* a, const char* b){
	return (0==strcmp(a, b));
}

void reread(char* input){
	if(input != NULL) free(input);
	input = malloc(10*sizeof(char));
	scanf(" %10[^\n]", input);
}


int main(){
	Stack* east = newStack();
	Stack* west = newStack();
	Stack* north = newStack();
	Stack* south = newStack();

	Stack* general = newStack();

	char* input = malloc(10* sizeof(char));
	scanf(" %10[^\n]", input);
	while(!equals(input, "0")){
		if(equals(input, "-4")){
			reread(input);
			while(!equals(input, "-1") && !equals(input, "-2") && !equals(input, "-3") && !equals(input, "-4") && !equals(input, "0")){
				push(east, input);
				reread(input);
			}
		}
		if(equals(input, "-3")){
			reread(input);
			while(!equals(input, "-1") && !equals(input, "-2") && !equals(input, "-3") && !equals(input, "-4") && !equals(input, "0")){
				push(north, input);
				reread(input);
			}
		}
		if(equals(input, "-2")){
			reread(input);
			while(!equals(input, "-1") && !equals(input, "-2") && !equals(input, "-3") && !equals(input, "-4") && !equals(input, "0")){
				push(south, input);
				reread(input);
			}
		}
		if(equals(input, "-1")){
			reread(input);
			while(!equals(input, "-1") && !equals(input, "-2") && !equals(input, "-3") && !equals(input, "-4") && !equals(input, "0")){
				push(west, input);
				reread(input);
			}
		}
	}

	while(north->n>0 || south->n>0 || east->n>0 || west->n>0){
		if(west->n>0) pop(west, general);
		if(north->n>0) pop(north, general);
		if(south->n>0) pop(south, general);
		if(east->n>0) pop(east, general);
	}

	printStack(general);

	/*
	printStack(west);
	printStack(north);
	printStack(south);
	printStack(east);
	*/

	delStack(general);
	delStack(south);
	delStack(north);
	delStack(west);
	delStack(east);
	
	return 0;
}
