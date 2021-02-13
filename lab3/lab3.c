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

void print_struct(struct Firework *f) {
		printf("\nInitialize the struct firework variables\n\n");
		printf("Launch Time: %lf\nHex code: %X\nFuse time: %lf\nX Position: %lf\nX Velocity: %lf\nY Velocity: %lf\n\n", f->time, f->hex, f->fuse, f->x, f->vx, f->vy); 
}

void read_struct(struct Firework *f) {
		int num_allocated = 1;
		struct Sim s, *sim_struct = &s;
		struct Firework *fptr;
		sim_struct->list = NULL;
		while (scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy) == 6) {
				/*fptr = malloc(sizeof(struct Firework));*/
				to_dynamic_memory(&fptr);
				*fptr = *f;
				fptr->sim = sim_struct;
				if (TEXT) main_output(fptr, num_allocated);
				num_allocated = insert_struct(fptr);
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
