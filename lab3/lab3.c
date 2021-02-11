/* Sooyoung Jeon */

#include <stdio.h>
#include "func.h"
#include "struct.h"

void run_func(struct Firework *rocket, void (*func_ptr)(struct Firework *f)) {
		func_ptr(rocket);
}

void print_struct(struct Firework *f) {
		printf("\nInitialize the struct firework variables\n\n");
		printf("Launch Time: %lf\nHex code: %X\nFuse time: %lf\nX Position: %lf\nX Velocity: %lf\nY Velocity: %lf\n\n", f->time, f->hex, f->fuse, f->x, f->vx, f->vy); 
}

void read_struct(struct Firework *f) {
		while (scanf("%lf %X %lf %lf %lf %lf\n", &f->time, &f->hex, &f->fuse, &f->x, &f->vx, &f->vy) == 6) {
				run_func(f, &print_struct);
		}
}

int main() {

		struct Firework f = {0}, *rocket = &f;
		run_func(rocket, &read_struct);

	return 0;
}
