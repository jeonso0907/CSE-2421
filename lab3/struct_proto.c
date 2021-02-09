/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"

int main() {
	struct Firework f = {0};
	printf("\nInitialize the struct firework variables\n\n");
	printf("Launch Time: %lf\nHex code:  %X\nFuze time:  %lf\nX Position:  %lf\nX Velocity:  %lf\nY Velocity:  %lf\n\n", f.time, f.hex, f.fuze, f.x, f.vx, f.vy);
	return 0;
}
