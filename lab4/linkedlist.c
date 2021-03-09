/* 
 * Sooyoung Jeon
 * Lab4 (Linked list Functions)
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 #include "altmem.h"
 #include "node.h"
 #include "structs.h"
 #include "debug.h"
 
 /* Free Node */
static void recycle_node(struct Node **nextPtr, struct Node **prevPtr) {
		alternative_free(*nextPtr);
		alternative_free(*prevPtr);
}

/* Check rather value of each data in the comparison function are same or not */
static int is_same(void *data1, void *data2, int (*ComparisonFunc)(void *data1, void *data2)) {
	int is_same = 0;
	if (data1 != NULL && data2 != NULL && ComparisonFunc(data1, data2) == ComparisonFunc(data2, data1)) is_same = 1;
	return is_same;
}
 
/* ===== INSERT ===== */
 
 /* Node memory allocation for insert function */
static int dynamic_allocation_insert(struct Node **newNode) {
		int allocation = 0;

		*newNode = alternative_malloc(sizeof(struct Node));

		if (*newNode) {
				allocation = 1;
		}
		return allocation;
}

/* Print the allocated node number */
static void print_node_allocated(int is_allocated) {
		static int allocated_nodes = 0;
		allocated_nodes += is_allocated;
		if (is_allocated) printf("DIAGNOSTIC: %d nodes allocated.\n", allocated_nodes);
		else printf("ERROR: linkedlist.c: Failed to malloc a Node\n");
}

/* Linked list insert function implementation */
int insert(void **p2headptr, void *data, int (*ComparisonFunc)(void *data1, void *data2), int verbose) {
		
	struct Node *prev, *newNode;
	int is_allocated = 0;
	is_allocated = dynamic_allocation_insert(&newNode);

	if (is_allocated) {	
		newNode->next = *p2headptr;
		newNode->data = data;

		if (newNode->next == NULL || (!ComparisonFunc(newNode->next->data, newNode->data) && !is_same(newNode->next->data, newNode->data, ComparisonFunc))) {
			*((struct Node**) p2headptr) = newNode;
		} else {
			while (newNode->next != NULL && (ComparisonFunc(newNode->next->data, newNode->data) || is_same(newNode->next->data, newNode->data, ComparisonFunc))) {
				prev = newNode->next;
				newNode->next = newNode->next->next;
			}
			prev->next = newNode;
		}
	}
	if (verbose) print_node_allocated(is_allocated);

	return is_allocated;
		
}

/* ===== DELETE SOME ===== */

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

/* Print the freed node message */
static void print_freed_node() {
		static int freed_node = 1;
		printf("DIAGNOSTIC: %d nodes freed.\n", freed_node);
		freed_node++;
}

/* Delete the node which matches the condition to be end */
void deleteSome(void **p2headptr, int (*CriterianFunc)(void *data), void (*ActionFunc)(void *data), int verbose) {
	struct Node *temp, *prev;
	temp = alternative_malloc(sizeof(struct Node));

	if (temp) {
		temp->next = *p2headptr;

		while (temp->next != NULL && CriterianFunc(temp->next->data)) {
			*((struct Node**) p2headptr) = temp->next->next;
			ActionFunc(temp->next->data);
			if (verbose) print_freed_node();
			/*alternative_free(temp->next->data);*/
			alternative_free(temp->next);
			temp->next = *p2headptr;
		}

		while (temp->next != NULL) {
			while (temp->next != NULL && !CriterianFunc(temp->next->data)) {
				prev = temp->next;
				temp->next = temp->next->next;
			}
			if (temp->next == NULL) return;
			ActionFunc(temp->next->data);
			if (verbose) print_freed_node();
			prev->next = temp->next->next;
			/*alternative_free(temp->next->data);*/
			alternative_free(temp->next);
			temp->next = prev->next;
		}
		alternative_free(temp);
	}	
}

/* ===== ITERATE ===== */

void iterate(void *p2headptr, void (*func_ptr)(void *data)) {
		struct Node *currNode = p2headptr;
		while (currNode != NULL) {
				if (currNode->data != NULL) func_ptr(currNode->data);
				currNode = currNode->next;
		}
}

/* ===== LEAST ===== */

double least(void *p2headptr, double (*func_ptr)(void *data)) {
		struct Node *currNode = p2headptr;
		double curr_least, new_least;
		curr_least = func_ptr(currNode->data);
		currNode = currNode->next;
		while (currNode != NULL) {
				new_least = func_ptr(currNode->data);
				if (new_least < curr_least) curr_least = new_least;
				currNode = currNode->next;
		}
		return curr_least;
}

/* ===== SORT ===== */

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
			while (currNode != NULL && currNode->next != NULL) {
				if (!ComparisonFunc(currNode->data, currNode->next->data)
					&& !is_same(currNode->data, currNode->next->data, ComparisonFunc)) {
					swap(&currNode->data, &currNode->next->data);
				}
				currNode = currNode->next;
			}
			currNode = p2headptr;
			indNode = indNode->next;
		}
}


