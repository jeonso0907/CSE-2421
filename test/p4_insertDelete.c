/* 
 * Sooyoung Jeon
 * Lab4 (Prototype of insert and deleteSome Functions)
 */

#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "node.h"
#include "debug.h"
#include "altmem.h"

/*--------------------------------- MEMORY CONTROL FUNCTIONS  ----------------------------------*/

/* Node memory allocation for insert function */
static int dynamic_allocation_insert(struct Node **newNode, struct Node **nextPtr, struct Node **prevPtr) {
		int allocation = 0;
		*newNode = alternative_malloc(sizeof(struct Node));
		*nextPtr = alternative_malloc(sizeof(struct Node));
		*prevPtr = alternative_malloc(sizeof(struct Node));
		if (*newNode != NULL && *nextPtr != NULL && *prevPtr != NULL) {
				allocation = 1;
		}
		return allocation;
}

/* Node memory allocation for deleteSome function*/
static int dynamic_allocation_deleteSome(struct Node **nextPtr, struct Node **prevPtr) {
		int allocation = 0;
		*nextPtr = alternative_malloc(sizeof(struct Node));
		*prevPtr = alternative_malloc(sizeof(struct Node));
		if (*nextPtr != NULL && *prevPtr != NULL) {
				allocation = 1;
		}
		return allocation;
}

/* Free Node */
static void recycle_node(struct Node **nextPtr, struct Node **prevPtr) {
		alternative_free(*nextPtr);
		alternative_free(*prevPtr);
}

/*--------------------------------------- INSERT  -------------------------------------*/

/* Print the allocated node number */
static void print_node_allocated(int is_allocated) {
		static int allocated_nodes = 0;
		allocated_nodes += is_allocated;
		if (is_allocated) printf("DIAGNOSTIC: %d nodes allocated.\n", allocated_nodes);
		else printf("ERROR: Unable to allocate a node\n");
}

/* Linked list insert function implementation */
int insert(void **p2headptr, void *data, int (*ComparisonFunc)(void *data1, void *data2), int verbose) {
		int is_allocated = 0;
		int is_first = 1;
		struct Node *newNode, *nextPtr, *prevPtr; 

		is_allocated = dynamic_allocation_insert(&newNode, &nextPtr, &prevPtr);
		if (verbose) print_node_allocated(is_allocated);

		if (is_allocated) {
				nextPtr->next = *p2headptr;
				newNode->data = data;
				newNode->next = NULL;
				while (nextPtr->next != NULL && ComparisonFunc(nextPtr->next->data, newNode->data)) {
						prevPtr->next = nextPtr->next;
						nextPtr->next = nextPtr->next->next;
						is_first = 0;
				}
				newNode->next = nextPtr->next;
				nextPtr->next = newNode;

				if (is_first) {
						*((struct Node**) p2headptr) = nextPtr->next;
				} else { 
						prevPtr->next->next = newNode;
				}
		}

		/* Free pointr nodes */
		if (is_allocated) recycle_node(&nextPtr, &prevPtr);

		return is_allocated;
}

/* Insert order function (ordered by decreasing launch time) */
int launch_order(void *data1, void *data2){
		struct FW *f1 = data1, *f2 = data2;
		return( f1->launch > f2->launch);
}


/* --------------------------------------- DELETE SOME -------------------------------------*/

/* Print the freed node message */
static void print_freed_node() {
		static int freed_node = 1;
		printf("DIAGNOSTIC: %d nodes freed.\n", freed_node);
		freed_node++;
}

/* Delete the node which matches the condition to be end */
static void deleteSome(void **p2headptr, int (*CriterianFunc)(void *data), void (*ActionFunc)(void *data), int verbose) {
		struct Node *nextPtr, *prevPtr, *holder;
		int is_allocated = 0;
		is_allocated = dynamic_allocation_deleteSome(&nextPtr, &prevPtr);
		holder = NULL;

		if (is_allocated) {
				nextPtr->next = *p2headptr;
				while (nextPtr->next != NULL) {
						if (CriterianFunc(nextPtr->next->data)) {
								if (holder != NULL) prevPtr->next = holder;
								holder = nextPtr->next;
								nextPtr->next = nextPtr->next->next;
								ActionFunc(holder->data);
								if (verbose) print_freed_node();
								alternative_free(holder->data);
								alternative_free(holder);
								if (prevPtr->next != NULL) prevPtr->next->next = nextPtr->next;
								else *((struct Node**) p2headptr) = nextPtr->next;
								holder = NULL;
						} else {
								holder = nextPtr->next;
								nextPtr->next = nextPtr->next->next;
						}
				}
				recycle_node(&nextPtr, &prevPtr);
		}
}

/* Check rather the launch time is larger than 1 sec */
int is_done(void *data) {
		struct FW *fptr = data;
		return fptr->launch > 1;
}

/* Action to do if the node is freed */
void print_deleted_message(void *data) {
		struct FW *fptr = data;
		printf("FW with launch value %lf is freed\n", fptr->launch);
}

/*---------------------------------- PRTOTYPE DEBUG FUNCTIONS ------------------------------*/

/* Print all nodes function (print decreasing ordered launch time) */
void print(void *p2headptr) {
		struct Node *currNode;
		struct FW *fptr;
		currNode = p2headptr;
		printf("Print list node data values by its launch time in decreasing order\n");
		while (currNode != NULL) {
				fptr = currNode->data;
				printf("%lf\n", fptr->launch);
				currNode = currNode->next;
		}
}

/* Print the size of the linked list (should matches with the allocation message) */
void print_list_size(void *p2headptr) {
		struct Node *currNode;
		int count = 0;
		currNode = p2headptr;

		while (currNode != NULL) {
				count++;
				currNode = currNode->next;
		}
		printf("LINKED LIST SIZE: %d\n", count);
}

/*------------------------------ MAIN & FW ALLOCATING FUNCTION ----------------------------------*/

/* Firework memory allocation */
static int dynamic_allocate(struct FW **fptr, struct FW **fptrCopy, struct Sim **site) {
		static int count = 1;
		static int total_count = 0;
		*fptrCopy = alternative_malloc(sizeof(struct FW));
		if (*fptrCopy) {
				**fptrCopy = **fptr;
				(*fptrCopy)->world = *site;
		} else {
			printf("ERROR: memory.c: to_dynamic_memory: malloc failed\n");
			printf("%d firework failed\n", count);
			total_count++;
		}
		count++;
		return total_count;
}

/* Main function to test both insert and deleteSome */
int main() {
		struct FW FW, *fptr = &FW, *fptrCopy;
		struct Sim launch_site, *site = &launch_site;
		static int count = 1;
		int total_node_count = 0;
		int total_fw_count = 0;
		int is_inserted = 0;
		site->p2headptr = NULL;
		printf("\n-----INSERT PROTOTYPE-----\n\n");
		while (scanf("%lf %X %lf %lf %lf %lf", &fptr->launch, &fptr->code, &fptr->fuse, &fptr->X, &fptr->VX, &fptr->VY) == 6) {
				total_fw_count = dynamic_allocate(&fptr, &fptrCopy, &site);
				if (fptrCopy) {
					is_inserted = insert(&site->p2headptr, fptrCopy, launch_order, TEXT);
					if (!is_inserted) {
						printf("Since node no allocated, free the fw\n");
						printf("%d nodes failed\n", count);
						alternative_free(fptrCopy);
						total_node_count++;
					}
				}
				count++;
				print_list_size(site->p2headptr);
				printf("\n");
		}
		printf("total %d fw failed\n", total_fw_count);
		printf("total %d nodes failed\n", total_node_count);
		print(site->p2headptr);
		printf("\n");
		printf("-----DELETE SOME PROTOTYPE-----\n\n");
		printf("Free firework launch time with higher than 1 second\n");
		deleteSome(&site->p2headptr, is_done, print_deleted_message, TEXT);
		printf("\n");
		print(site->p2headptr);

		return 0;
}
