/* 
 * Sooyoung Jeon
 * Lab4 (Prototype of sort Function)
 */

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "node.h"
#include "linkedlist.h"
#include "debug.h"

int compare(void *data1, void *data2) {
		struct FW *f1 = data1;
		struct FW *f2 = data2;
		return f1->fuse > f2->fuse;
}

static void swap(void **data1, void **data2) {
		void *temp;
		temp = *data1;
		*data1 = *data2;
		*data2 = temp;
}

void sort(void *p2headptr, int (*ComparisonFunc)(void *data1, void *data2)) {
		struct Node *indNode = p2headptr;
		struct Node *currNode = p2headptr;
		while (indNode != NULL) {
			while (currNode->next != NULL) {
				if (ComparisonFunc(currNode->data, currNode->next->data)) {
					swap(&currNode->data, &currNode->next->data);
				}
				currNode = currNode->next;
			}
			currNode = p2headptr;
			indNode = indNode->next;
		}
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

void print(void *p2headptr) {
		struct Node *currNode = p2headptr;
		struct FW *fptr;
		while (currNode != NULL) {
			fptr = currNode->data;
			printf("%lf\n", fptr->fuse);
			currNode = currNode->next;
		}
}

int main() {
		struct FW FW, *fptr = &FW, *fptrCopy;
		struct Sim launch_site, *site = &launch_site;
	
		while (scanf("%lf %X %lf %lf %lf %lf", &fptr->launch, &fptr->code, &fptr->fuse, &fptr->X, &fptr->VX, &fptr->VY) == 6) {
				dynamic_allocate(&fptr, &fptrCopy, &site);
				insert(&site->p2headptr, fptrCopy, launch_order, TEXT);
		}
		printf("Sort by fuse time (Increasing order)\n");
		printf("Before sort\n");
		print(site->p2headptr);
		sort(site->p2headptr, compare);
		printf("After sort\n");
		print(site->p2headptr);
	
		return 0;
}
