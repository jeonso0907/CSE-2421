/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "debug.h"
#include "linkedlist.h"
#include "libfire.h"

void run_func(struct Firework *rocket, void (*func_ptr)(struct Firework *f)) {
		func_ptr(rocket);
}

void read_struct(struct Firework *f) {
		struct Sim s, *sim_ptr = &s;
		struct Firework *fptr;
		sim_ptr->list = NULL;
		while (scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy) == 6) {
				firework_setup(&fptr, &f, &sim_ptr);
				insert_struct(fptr);
		}
		run_simulate(fptr);
}

int main() {
		if (TEXT || (GRAPHICS &&fw_initialize())) {
				struct Firework f = {0}, *rocket = &f;
				run_func(rocket, &read_struct);
				if (GRAPHICS) fw_teardown();
		}

		return 0;
}
