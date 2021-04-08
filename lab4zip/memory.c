/*
 * Sooyoung Jeon
 * Lab3: mamory.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "linkedlist.h"
#include "debug.h"
#include "memory_func.h"
#include "output.h"
#include "memory.h"

/*
 * Dynamically assign the firework pointer to the memory
 * Print the error message if the malloc fails
 */
void to_dynamic_memory(Firework **fc_ptr1) {
		*fc_ptr1 = malloc(sizeof(Firework));
		if (*fc_ptr1 == NULL) {
				dynamic_error_output();
				free(*fc_ptr1);
		}
}

/*
 * Set up the firework struct and assign it to the simulation struct list pointer
 */
void firework_setup(Firework **fc_ptr1, Firework **fc_ptr2, Sim **sim_ptr) {
		to_dynamic_memory(fc_ptr1);
		if (fc_ptr1 != NULL) {
			**fc_ptr1 = **fc_ptr2;
			(*fc_ptr1)->sim = *sim_ptr;
		}
}

/*
 * Iterate the firework with given function pointer
 */
void iterate_struct(Sim *s, void (*func_ptr)(void *data)) {
		iterate(s->list, func_ptr);
}

/*
 * Sort the firework based on the height of the current position
 */
void sort_struct(Sim *s) {
		sort(s->list, sort_y);
}

/*
 * Insert the firework in the linked list
 */
void insert_struct(Firework *f) {
		static int num_allocated = 1;
		allocate_output(f, num_allocated);
		insert(&f->sim->list, f, first_time, TEXT);
		num_allocated++;
}

/*
 * Delete the firework while computing the given function pointer
 */
void deleteSome_struct(Sim *s, void (*func_ptr)(void *data)) {
		deleteSome(&s->list, firework_valid, func_ptr, TEXT); 
}

/*
 * Find the least firework with the given condition of the function pointer
 */
double least_struct(Sim *s, double (*func_ptr)(void *data)) {
		return least(s->list, func_ptr);
}

/*
 * Check rather there is a valid firework with the given condition of the function pointer
 */
int some_struct(Sim *s, int (*func_ptr)(void *data)) {
		return some(s->list, func_ptr);
}
