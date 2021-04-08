/*
 * Sooyoung Jeon
 * Lab3: struct_proto.c (Prototype to test the basic struct)
 */
#include <stdio.h>
#include "struct.h"

int main() {
		struct Firework rocket = {0}, *f = &rocket;
		f->time = 10;
		f->hex = 0xA1239A;
		f->fuse = 20; 
		f->x = 30; 
		f->y = 40;
		f->vx = 50;
		f->vy = 60;
		printf("\nInitialize the struct firework variables (Struct Prototype)\n\n");
		printf("Launch Time: %3lf\nHex code:    %3X\nFuse time:   %3lf\nX Position:  %3lf\nY Position:  %3lf\nX Velocity:  %3lf\nY Velocity:  %3lf\n\n", f->time, f->hex, f->fuse, f->x, f->y, f->vx, f->vy);
		return 0;
}
