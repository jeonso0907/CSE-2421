/*
 * Sooyoung Jeon
 * Lab3: func_ptr_proto.c (Prototype to test the function pointer to execute the value with the given function)
 */

#include <stdio.h>
#include "struct.h"

void run_func(struct Firework *rocket, void (*func_ptr)(struct Firework *f)) {
		func_ptr(rocket);
}

void struct_pointer(struct Firework *f) {
		printf("\nInitialize the struct firework variables (Function Pointer Prototype)\n\n");
		printf("Launch Time: %3lf\nHex code:    %3X\nFuse time:   %3lf\nX Position:  %3lf\nY Position:  %3lf\nX Velocity:  %3lf\nY Velocity:  %3lf\n\n", f->time, f->hex, f->fuse, f->x, f->y, f->vx, f->vy);

}

int main() {
		struct Firework f = {0}, *rocket = &f;
		rocket->time = 10;
		rocket->hex = 0xA1239A;
		rocket->fuse = 20; 
		rocket->x = 30; 
		rocket->y = 40;
		rocket->vx = 50;
		rocket->vy = 60;

		run_func(rocket, &struct_pointer);
		return 0;
}
