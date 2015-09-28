// CS3413 - Operating Systems I
// Assignment 1 - Question 1
// Joel Stanley
// Due October 1, 2015

#include <stdio.h>
#include <stdlib.h>

struct Node {
	char *user;
	char process;
	int arrival;
	int duration;
	struct Node *next;
};

//Pointers for Queue
struct Node* front = NULL;
struct Node* end = NULL;

void enqueue(char *userIn, char processIn, int arrivalIn, int durationIn) {
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->user = userIn;
	new->process = processIn;
	new->arrival = arrivalIn;
	new->duration = durationIn;
	new->next = NULL;

	if(front == NULL && end == NULL) {
		front = end = new;
	}
	else {
		end->next = new;
		end = new;
	}
} 

int main() {
	
	int numJobs, i;
	printf("How many jobs will there be?\n");
	scanf("%d", &numJobs);

	for(i = 0; i < numJobs; i++) {
		char tUser[10];
		char tProcess;
		int tArrival;
		int tDuration;

		printf("Input the data below seperated by a tab.\n");
		scanf("%s	%c	%d	%d", tUser, &tProcess, &tArrival, &tDuration);

		enqueue(tUser, tProcess, tArrival, tDuration);
	}
	return 0;
}

