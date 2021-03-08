/* 
 * Sooyoung Jeon
 * Lab4 (Prototype of least Function)
 */

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "node.h"
#include "linkedlist.h"
#include "debug.h"

double least_type(void *data) {
		struct FW *fptr = data;
		return fptr->fuse;
}

double least(void *p2headptr, double (*func_ptr)(void *data)) {
		struct Node *currNode = p2headptr;
		double curr_least, new_least;
		static int count = 1;
		curr_least = func_ptr(currNode->data);
		currNode = currNode->next;
		printf("Least value in loop %d is %lf\n", count, curr_least);
		count++;
		while (currNode != NULL) {
				new_least = func_ptr(currNode->data);
				if (new_least < curr_least) curr_least = new_least;
				printf("Least value in loop %d is %lf\n", count, curr_least);
				currNode = currNode->next;
				count++;
		}
		return curr_least;
}

void dynamic_allocate(struct FW **fptr, struct FW **fptrCopy, struct Sim **site) {
		if (*fptrCopy = malloc(sizeof(struct FW))) {
			if (fptrCopy != NULL) {
				**fptrCopy = **fptr;
				(*fptrCopy)->world = *site;
			}
		}
}

int launch_order(void *data1, void *data2){
		struct FW *f1 = data1, *f2 = data2;
		return( f1->launch < f2->launch);
}

int main() {
	struct FW FW, *fptr = &FW, *fptrCopy;
	struct Sim launch_site, *site = &launch_site;
	double least_value;
	while (scanf("%lf %X %lf %lf %lf %lf", &fptr->launch, &fptr->code, &fptr->fuse, &fptr->X, &fptr->VX, &fptr->VY) == 6) {
				dynamic_allocate(&fptr, &fptrCopy, &site);
				insert(&site->p2headptr, fptrCopy, launch_order, TEXT);
	}
	least_value = least(site->p2headptr, least_type);
	printf("The final least value is %lf\n", least_value);
	return 0;
}
