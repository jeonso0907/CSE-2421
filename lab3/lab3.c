/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"
#include "debug.h"
#include "linkedlist.h"
#include "libfire.h"

void run_func(struct Firework *rocket, void (*func_ptr)(struct Firework *f)) {
		func_ptr(rocket);
}

void print_struct(struct Firework *f) {
		printf("\nInitialize the struct firework variables\n\n");
		printf("Launch Time: %lf\nHex code: %X\nFuse time: %lf\nX Position: %lf\nX Velocity: %lf\nY Velocity: %lf\n\n", f->time, f->hex, f->fuse, f->x, f->vx, f->vy); 
}

void read_struct(struct Firework *f) {
		struct Sim s, *sim_struct = &s;
		sim_struct->list = NULL;
		while (scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy) == 6) {
				struct Firework fc, *fc_ptr = &fc;
				*fc_ptr = *f;
				fc_ptr->sim = sim_struct;
				insert_struct(fc_ptr);
		}
		run_simulate(sim_struct);
}

int main() {
		if (TEXT || (GRAPHICS &&fw_initialize())) {
				struct Firework f = {0}, *rocket = &f;
				run_func(rocket, &read_struct);
				if (GRAPHICS) fw_teardown();
		}

		return 0;
}
