/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "output.h"
#include "memory.h"
#include "libfire.h"
#include "random_fire.h"

double xp() {
		static int side = 1;
		double x = 0;
		if (side) {
				x = rand() % 250 + 100;
				side = 0;
		} else {
				x = rand() % 150 - 250;
				side = 1;
		}
		return x;
}

void random_firework(Firework *f) {
		int total_firework, randN;
		double time, x;
		unsigned int mask;
		static double launch_time = 0;
		total_firework = 100;

		randN = rand() % 6 + 1;
		if (randN < 0) randN *= -1;
		mask = (randN & 0xF) << 24;
		f->hex = (0x800FA74E | mask);
		f->x = xp();
		f->fuse = ((rand() % 6)) + 1;
		f->time = launch_time;
		f->vx = 0;
		f->vy = rand() % 30 + 100;
		launch_time += 0.25;
}
