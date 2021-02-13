/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"
#include "debug.h"
#include <stdlib.h>

void allocate_output(struct Firework *f, int num_allocated) {
		if (TEXT) {
				printf("DIAGNOSTIC: Allocating space for code %X. %d allocated.\n", f->hex, num_allocated);
		}

}

void et_output(struct Firework *f) {
		if (TEXT) {
			double ET = f->sim->et;
			printf("At ET = %.3lf (%lf) second:\n", ET, ET);
		}
}

void main_output(struct Firework *f, int num_allocated) {
		allocate_output(f, num_allocated);
}
