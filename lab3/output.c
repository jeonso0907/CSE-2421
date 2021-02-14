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

void effect_output(struct Firework *f) {
		if (get_flash(f->hex)) printf("Flash at Flash at (%6.2lf, %6.02lf)'\n", f->x, f->y);
		if (get_bang(f->hex)) printf("Boom at (%6.2lf, %6.2lf)'\n", f->x, f->y);
}

void free_output(void *data) {
		static int num_freed = 1;
		struct Firework *f; 
		f = data;
		printf("\nColor #%d starburst at (%6.2lf, %6.2lf)'\n", get_color(f->hex), f->x, f->y);
		effect_output(f);
		printf("DIAGNOSTIC: Freeing firework with code %X.  %d freed.\n", f->hex, num_freed);
}


void et_output(struct Firework *f) {
		if (TEXT) {
			double ET = f->sim->et;
			printf("\n At ET =  %.3lf (%.15lf) second:", ET, ET);
		}
}

void title_output() {
		printf("\n    Code     (      X,       Y)'  (     VX,      VY) fps       Fuse sec");
}

void range_safety_output(struct Firework *f) {
		if (f->vy < 0) printf("\nRANGE SAFETY WARNING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.", f->hex, f->y, f->x, f->fuse);
}

void space_output(struct Firework *f) {
		if (f->sim->et > 0) printf("\n\n");

}

void text_output(struct Firework *f) {
		deleteSome_struct(f);
		if (some_struct(f)) {
				space_output(f);
				et_output(f);
				title_output();
				iterate_print(f);
				iterate_update(f);
		}
}

void graphic_output(struct Firework *f) {
}

void main_output(struct Firework *f) {
		if (TEXT) text_output(f);
		if (GRAPHICS) graphic_output(f);
}
