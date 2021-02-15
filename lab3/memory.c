/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "linkedlist.h"
#include "libfire.h"
#include "memory.h"
#include "memory_func.h"
#include "output.h"
#include "debug.h"

void to_dynamic_memory(struct Firework **fc_ptr1) {
		*fc_ptr1 = malloc(sizeof(struct Firework));
		if (*fc_ptr1 == NULL) {
				dynamic_error_output();
				free(*fc_ptr1);
		}
}

void firework_setup(struct Firework **fc_ptr1, struct Firework **fc_ptr2, struct Sim **sim_ptr) {
		to_dynamic_memory(fc_ptr1);
		if (fc_ptr1 != NULL) {
			**fc_ptr1 = **fc_ptr2;
			(*fc_ptr1)->sim = *sim_ptr;
		}
}

void iterate_struct(struct Sim *s, void (*func_ptr)(void *data)) {
		iterate(s->list, func_ptr);
}

void sort_struct(struct Sim *s) {
		sort(s->list, sort_y);
}

void insert_struct(struct Firework *f) {
		static int num_allocated = 1;
		allocate_output(f, num_allocated);
		insert(&f->sim->list, f, first_time, TEXT);
		num_allocated++;
}

void deleteSome_struct(struct Sim *s, void (*func_ptr)(void *data)) {
		deleteSome(&s->list, fuse_over, func_ptr, TEXT); 
}

double least_struct(struct Sim *s, double (*func_ptr)(void *data)) {
		return least(s->list, func_ptr);
}

int some_struct(struct Sim *s, int (*func_ptr)(void *data)) {
		return some(s->list, func_ptr);
}
