/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"

void struct_pointer(struct Firework firework) {
		struct Firework *f = &firework;
		printf("\nInitialize the struct firework variables\n\n");
		printf("Launch Time: %lf\nHex code: %X\nFuze time: %lf\nX Position: %lf\nX Velocity: %lf\nY Velocity: %lf\n\n", f->time, f->hex, f->fuze, f->x, f->vx, f->vy);

}

int main() {
	struct Firework firework;
	struct_pointer(firework);
	return 0;
}
