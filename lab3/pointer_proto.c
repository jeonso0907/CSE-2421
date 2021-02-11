/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"

void struct_pointer(struct Firework *f) {
		printf("\nInitialize the struct firework variables\n\n");
		printf("Launch Time: %lf\nHex code: %X\nFuse time: %lf\nX Position: %lf\nX Velocity: %lf\nY Velocity: %lf\n\n", f->time, f->hex, f->fuse, f->x, f->vx, f->vy);
}

int main() {
	struct Firework firework = {0}, *f = &firework;
	struct_pointer(f);
	return 0;
}
