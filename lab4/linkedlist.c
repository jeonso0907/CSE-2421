/* 
 * Sooyoung Jeon
 * Lab4 (Linked list Functions)
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 #include "node.h"
 #include "debug.h"
 #include "altmem.h"

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
		
	struct Node *curr, *newNode;
	int is_allocated = 0;
	is_allocated = dynamic_allocation_insert(&newNode);

	if (is_allocated) {	
		curr = *p2headptr;
		newNode->data = data;

		/* If the new node is the first node, change the head pointer 
		 * else, loop until to find the appropriate position ofr the new node */
		if (curr == NULL || (!ComparisonFunc(curr->data, newNode->data) && !is_same(curr->data, newNode->data, ComparisonFunc))) {
			newNode->next = curr;
			*p2headptr = newNode;
		} else {
			while (curr->next != NULL && (ComparisonFunc(curr->data, newNode->data) || is_same(curr->data, newNode->data, ComparisonFunc))) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
		}
	}
	
	if (verbose) print_node_allocated(is_allocated);

	return is_allocated;
		
}

/* ===== DELETE SOME ===== */

/* Print the freed node message */
static void print_freed_node() {

		static int freed_node = 1;
		
		printf("DIAGNOSTIC: %d nodes freed.\n", freed_node);
		freed_node++;
}

/* Free the finished nodes */
static void recycle_node(struct Node *node) {

	if (node != NULL) {
		alternative_free(node);
	}
}

/* Delete the node which matches the condition to be end */
void deleteSome(void **p2headptr, int (*CriterianFunc)(void *data), void (*ActionFunc)(void *data), int verbose) {
	
	struct Node *curr, *prev;
	curr = *p2headptr;

	/* Loop for continuous nodes including the head node */
	while (curr != NULL && CriterianFunc(curr->data)) {
		*p2headptr = curr->next;
		ActionFunc(curr->data);
		recycle_node(curr);
		curr = *p2headptr;
		print_freed_node();
	}
	
	/* Loop for continous nodes excluding the head node */
	while (curr != NULL) {
		while (curr != NULL && !CriterianFunc(curr->data)) {
			prev = curr;
			curr = curr->next;
		}
		if (curr == NULL) return;
		ActionFunc(curr->data);
		prev->next = curr->next;
		recycle_node(curr);
		curr = prev->next;
		print_freed_node();
	}
	
}

/* ===== ITERATE ===== */

/* Loop the nodes while executing the given function pointer */
void iterate(void *p2headptr, void (*func_ptr)(void *data)) {

		struct Node *currNode = p2headptr;
		
		while (currNode != NULL) {
				if (currNode->data != NULL) func_ptr(currNode->data);
				currNode = currNode->next;
		}
}

/* ===== LEAST ===== */

/* Loop the nodes to find the least variable with the given condition function pointer */
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

/* Swap the two given pointer to pointer variable */
static void swap(void **data1, void **data2) {
		void *temp;
		temp = *data1;
		*data1 = *data2;
		*data2 = temp;
}

/* Loop the nodes and swap the datas if the given condition function pointer is true */
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


