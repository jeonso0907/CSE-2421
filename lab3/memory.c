/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "linkedlist.h"
#include "libfire.h"

void to_dynamic_memory(struct Firework **fc_ptr1) {
		*fc_ptr1 = malloc(sizeof(struct Firework));
		if (*fc_ptr1 == NULL) {
				printf("ERROR:memory.c:to_dynamic_memory:malloc failed\n");
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

void update_et(void *data) {
		struct Firework *f;
		f = data;
		f->sim->et = now();
}

double identify_dt(struct Firework *f) {
		double edt = 0;
		if (f->sim->et < f->time) edt = 0;
		else if (f->sim->et > f->time + f->sim->dt) edt = f->sim->dt;
		else edt = (get_edt(f->sim->et, f->time));	
		if ((edt > 0) && (f->fuse < edt)) edt = f->fuse;
		return edt;
}

void update_data(void *data) {
		double edt = 0, curr_vy = 0;
		struct Firework *f;
		f = data;
		curr_vy = f->vy;

		edt = identify_dt(f);
		f->fuse -= edt;
		f->x = get_x(f->x, f->vx, edt);
		f->y = get_y(f->y, f->vy, edt);
		f->vy = get_vy(f->vy, edt);
		if (curr_vy > 0 && f->vy < 0) range_safety_output(f);
}

double get_least_dt(void *data) {
		struct Firework *f;
		f = data;
		return get_dt(f->vy);
}

int is_not_null(void *data) {
		struct Firework *f;
		f = data;
		return (f !=  NULL);
}

int fuse_over(void *data) {
		struct Firework *f;
		f = data;
		return (f->fuse <= 0);
}

int first_time(void *data1, void *data2) {
		struct Firework *f1 = data1, *f2 = data2;
		return (f1->time < f2->time);
}

int sort_y(void *data1, void *data2) {
		struct Firework *f1 = data1, *f2 = data2;
		return (f1->y > f2->y);
}

int all_true(void *data) {
	return (1 == 1);
}

void print_data(void *data) {
	struct Firework *f;
	f = data;
	if (f->sim->et >= f->time) {
		printf("\n%X at  (%7.2lf, %7.2lf)'  (%7.2lf, %7.2lf) fps with %4.3lf sec", f->hex, f->x, f->y, f->vx, f->vy, f->fuse);
	} else {
		printf("\n%X at  (%7.2lf, %7.2lf)'  Holding until %.3lf", f->hex, f->x, f->y, f->time);
	}
}

void delete_struct(struct Sim *s) {
		deleteSome(s, all_true, print_data, 1);
}

void iterate_struct(struct Sim *s) {
		iterate(s->list, update_et);
}

void iterate_print(struct Firework *f) {
		iterate(f->sim->list, print_data);
}

void iterate_update(struct Firework *f) {
		f->sim->et += f->sim->dt;
		iterate(f->sim->list, update_data);
		sort(f->sim->list, sort_y);
		/*f->sim->et += f->sim->dt;*/
}

void insert_struct(struct Firework *f) {
		static int num_allocated = 1;
		allocate_output(f, num_allocated);
		insert(&f->sim->list, f, first_time, 1);
		num_allocated++;
}

double least_struct(struct Firework *f) {
		return least(f->sim->list, get_least_dt);
}

int some_struct(struct Firework *f) {
		return some(f->sim->list, is_not_null);
}

void deleteSome_struct(struct Firework *f) {
		deleteSome(&f->sim->list, fuse_over, free_output, 1);
}
