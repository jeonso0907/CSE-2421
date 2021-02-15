/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "linkedlist.h"
#include "memory_func.h"
#include "calculate.h"
#include "output.h"

void last_pos(struct Firework *f) {
		f->x = get_x(f->x, f->vx, f->fuse);
		f->y = get_y(f->y, f->vy, f->fuse);
}

double effective_dt(struct Firework *f) {
		double edt = 0;
		if (f->sim->et < f->time) edt = 0;
		else if (f->sim->et > f->time + f->sim->dt) edt = f->sim->dt;
		else edt = get_edt(f->sim->et, f->time);
		if ((edt > 0) && (f->fuse < edt) && (f->fuse + f->time > f->sim->et)) edt = f->fuse;
		return edt;
}

void update_data_continue(struct Firework *f) {
		double edt = 0;
		edt = effective_dt(f);
		f->fuse -= edt;
		f->x = get_x(f->x, f->vx, edt);
		f->y = get_y(f->y, f->vy, edt);
		f->vy = get_vy(f->vy, edt);
}

int fuse_over(void *data) {
		struct Firework *f; 
		double edt = 0;
		int is_free = 0;
		f = data;
		edt = effective_dt(f);
		if (get_y(f->y, f->vy, edt) < 0) {
				is_free = 1;
				update_data_continue(f);
		}
		return (is_free  || ((f->time < f->sim->et) && (f->fuse <= edt)));
}

int is_free(void *data) {
		struct Firework *f = data;
		double edt = effective_dt(f);
		return (get_y(f->y, f->vy, edt) < 0 || ((f->time < f->sim->et) && (f->fuse <= edt)));
}


void update_data(void *data) {
		double edt = 0, curr_vy = 0, curr_y = 0;
		struct Firework *f;
		f = data;
		update_data_continue(f);		
}

double get_least_dt(void *data) {
		struct Firework *f; 
		f = data;
		return get_dt(f->vy);
}

double get_least_fuse(void *data) {
		struct Firework *f;
		f = data;
		return f->fuse;
}

int is_not_null(void *data) {
		struct Firework *f;
		f = data;
		return (f !=  NULL);
}

int first_time(void *data1, void *data2) {
		struct Firework *f1 = data1, *f2 = data2;
		return (f1->time < f2->time);
}

int sort_y(void *data1, void *data2) {
		struct Firework *f1 = data1, *f2 = data2;
		return (f1->y > f2->y);
}

void iterate_range_safety(void *data) {
		struct Firework *f = data;
		range_safety_output(f);
}
