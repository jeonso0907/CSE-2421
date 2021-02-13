/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "linkedlist.h"
#include "libfire.h"

void to_dynamic_memory(struct Firework **fc_ptr) {
		*fc_ptr = malloc(sizeof(struct Firework));
		if (*fc_ptr == NULL) {
				printf("ERROR:memory.c:to_dynamic_memory:malloc failed\n");
		}
}

void update_et(void *data) {
		struct Firework *f;
		f = data;
		f->sim->et = now();
}


int first_time(void *data1, void *data2) {
		struct Firework *f1 = data1, *f2 = data2;
		return (f1->time < f2->time);
}

int all_true(void *data) {
	return (1 == 1);
}

void print_data(void *data) {
	struct Firework *f;
	f = data;
	printf("Time is : %lf\n", f->sim->et);
}

void delete_struct(struct Sim *s) {
		deleteSome(s, all_true, print_data, 1);
}

void iterate_struct(struct Sim *s) {
		printf("iterate start\n");
		iterate(s->list, update_et);
		printf("iterate end\n");
}

void iterate_print(struct Sim *s) {
		iterate(s->list, print_data);
}

int insert_struct(struct Firework *f) {
		static int num_allocated = 1;
		insert(&f->sim->list, f, first_time, 1);
		num_allocated++;
		return num_allocated;
} 
