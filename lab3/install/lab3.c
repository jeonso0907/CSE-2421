/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "debug.h"
#include "libfire.h"
#include "output.h"
#include "memory.h"

/*
 * Read ans set up the firework rocket linked list until scanf reads the last line of the input values
 */
void read_struct(Firework *f, int *scan) {
		Sim s, *sim_ptr = &s;
		Firework *fptr;
		sim_ptr->list = NULL;
		*scan = scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy);
		while (*scan == 6) {
				firework_setup(&fptr, &f, &sim_ptr);
				insert_struct(fptr);
				*scan = scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy);
		}
		run_simulate(sim_ptr);
}

/*
 * Print the end result message
 */
void print_end_message(int scan, double run_time) {
		printf("Done reading: scanf returned %d\n", scan);
		printf("Total run time is %.9lf seconds.\n", run_time);
}

/*
 * Initialize the lab3 if it is in either text or graphics mode
 * Print the total running time after simulation ends
 */
int main() {
		double start = 0, end = 0;
		int scan = 0;
		if (TEXT || (GRAPHICS &&fw_initialize())) {
				Firework f = {0}, *rocket = &f;
				start = now();
				read_struct(rocket, &scan);
				if (GRAPHICS) fw_teardown();
				end = now();
		}
		print_end_message(scan, end - start);
		return 0;
}
