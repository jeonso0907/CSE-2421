/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "debug.h"
#include "libfire.h"
#include "simulate.h"
#include "memory.h"

void run_func(struct Firework *rocket, void (*func_ptr)(struct Firework *f)) {
		func_ptr(rocket);
}

void read_struct(struct Firework *f) {
		struct Sim s, *sim_ptr = &s;
		struct Firework *fptr;
		int scan = 0;
		sim_ptr->list = NULL;
		scan = scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy);
		while (scan == 6) {
				firework_setup(&fptr, &f, &sim_ptr);
				insert_struct(fptr);
				scan = scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy);
		}
		run_simulate(sim_ptr);
		printf("Done reading: scnaf returned %d \n", scan);
}

int main() {
		double start = 0, end = 0;
		if (TEXT || (GRAPHICS &&fw_initialize())) {
				struct Firework f = {0}, *rocket = &f;
				start = now();
				run_func(rocket, &read_struct);
				if (GRAPHICS) fw_teardown();
				end = now();
		}
		printf("Total run time is %.9lf seconds.", (end - start));
		return 0;
}
