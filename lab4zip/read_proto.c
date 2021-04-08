/*
 * Sooyoung Jeon
 * Lab3: read_proto.c (Prototype to test the reading and updating the struct data)
 * TEST WITH PROVIDED FWX FILE!
 */

#include <stdio.h>
#include "struct.h"

void print_struct(struct Firework firework) {
		struct Firework *f = &firework;
		printf("\nInitialize the struct firework variables (Read and Update Struct Prototype)\n\n");
		printf("Launch Time: %lf\nHex code: %X\nFuze time: %lf\nX Position: %lf\nX Velocity: %lf    \nY Velocity: %lf\n\n", f->time, f->hex, f->fuse, f->x, f->vx, f->vy); 

}

void read_struct(struct Firework f) {
		while (scanf("%lf %X %lf %lf %lf %lf\n", &f.time, &f.hex, &f.fuse, &f.x, &f.vx, &f.vy) == 6) {
				print_struct(f);
		}
}

int main() {
		struct Firework f;
		read_struct(f);
		return 0;
}
