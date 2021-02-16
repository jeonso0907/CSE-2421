/*
 * Sooyoung Jeon
 * Lab3: memory_func.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "calculate.h"
#include "output.h"
#include "memory_func.h"

/*
 * Update the last position of the firework to print the free message with appropriate data
 */
void last_pos(Firework *f) {
		f->x = get_x(f->x, f->vx, f->fuse);
		f->y = get_y(f->y, f->vy, f->fuse);
}

/*
 * Get the effective delta time for specific circumstances
 */
double effective_dt(Firework *f) {
		double edt = 0;
		if (f->sim->et < f->time) edt = 0;
		else if (f->sim->et > f->time + f->sim->dt) edt = f->sim->dt;
		else edt = get_edt(f->sim->et, f->time);
		if ((edt > 0) && (f->fuse < edt) && (f->fuse + f->time > f->sim->et)) edt = f->fuse;
		return edt;
}

/*
 * Update the whole data with delta time
 */
void update_data_continue(Firework *f) {
		double edt = 0;
		edt = effective_dt(f);
		f->fuse -= edt;
		f->x = get_x(f->x, f->vx, edt);
		f->y = get_y(f->y, f->vy, edt);
		f->vy = get_vy(f->vy, edt);
}

/*
 * Check rather the firework is still valid to remain in the list
 * If it is going to be freed, lastly update the data for the end message
 */
int firework_valid(void *data) {
		struct Firework *f= data; 
		double edt = 0;
		int is_free = 0;
		edt = effective_dt(f);
		if (get_y(f->y, f->vy, edt) < 0) {
				is_free = 1;
				update_data_continue(f);
		}
		return (is_free  || ((f->time < f->sim->et) && (f->fuse <= edt)));
}

/*
 * Check rather the firework is freed or is still running
 */
int is_free(void *data) {
		Firework *f = data;
		double edt = effective_dt(f);
		return (get_y(f->y, f->vy, edt) < 0 || ((f->time < f->sim->et) && (f->fuse <= edt)));
}

/*
 * Update the data generally
 */
void update_data(void *data) {
		Firework *f = data;
		update_data_continue(f);		
}

/*
 * Get the least delta time in the firework list
 */
double get_least_dt(void *data) {
		Firework *f = data;
		return get_dt(f->vy);
}

/*
 * Get the least fuse time in the firework list
 */
double get_least_fuse(void *data) {
		Firework *f = data;
		return f->fuse;
}

/*
 * Check rather the firework is not null
 */
int is_not_null(void *data) {
		Firework *f = data;
		return (f !=  NULL);
}

/*
 * Get the smaller launch time firework in two data
 */
int first_time(void *data1, void *data2) {
		Firework *f1 = data1, *f2 = data2;
		return (f1->time < f2->time);
}

/*
 * Get the smaller height (y) firework in two data
 */
int sort_y(void *data1, void *data2) {
		Firework *f1 = data1, *f2 = data2;
		return (f1->y > f2->y);
}

/*
 * Print the range safety message with the given firework
 */
void iterate_range_safety(void *data) {
		Firework *f = data;
		range_safety_output(f);
}
