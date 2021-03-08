/* 
 * Sooyoung Jeon
 * Lab4 (Prototype of iterate Function)
 */

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "node.h"
#include "linkedlist.h"
#include "debug.h"

void print(void *data) {
		struct FW *fptr = data;
		printf("%lf %X %lf %lf %lf %lf\n", fptr->launch, fptr->code, fptr->fuse, fptr->X, fptr->VX, fptr->VY);
}

void iterate(void *p2headptr, void (*func_ptr)(void *data)) {
		struct Node *currNode = p2headptr;
		static int count = 1;
		while (currNode != NULL) {
				func_ptr(currNode->data);
				currNode = currNode->next;
		}
		printf("%d nodes are printed \n\n", count);
		count++;
}

int launch_order(void *data1, void *data2){
		struct FW *f1 = data1, *f2 = data2;
		return( f1->launch < f2->launch);
}

void dynamic_allocate(struct FW **fptr, struct FW **fptrCopy, struct Sim **site) {
		if (*fptrCopy = malloc(sizeof(struct FW))) {
			if (fptrCopy != NULL) {
				**fptrCopy = **fptr;
				(*fptrCopy)->world = *site;
			}
		}
}

int main() {

		struct FW FW, *fptr = &FW, *fptrCopy;
		struct Sim launch_site, *site = &launch_site;
		while (scanf("%lf %X %lf %lf %lf %lf", &fptr->launch, &fptr->code, &fptr->fuse, &fptr->X, &fptr->VX, &fptr->VY) == 6) {
				dynamic_allocate(&fptr, &fptrCopy, &site);
				insert(&site->p2headptr, fptrCopy, launch_order, TEXT);
				iterate(site->p2headptr, print);
		}
		return 0;
}
