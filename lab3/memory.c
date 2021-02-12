/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"
#include "linkedlist.h"

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
	printf("Time is : %lf\n", f->time);
}

void delete_struct(struct Sim *s) {
		deleteSome(s, all_true, print_data, 1);
}

void insert_struct(struct Firework *f) {
		insert(f->sim, f, first_time, 1);
		iterate(f->sim->list, print_data);
} 
