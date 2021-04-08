/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"

int main() {
	struct firework f = {0};
	printf("%lf %X %lf %lf %lf %lf\n", f.time, f.hex, f.fuze, f.x, f.vx, f.vy);
	return 0;
}
