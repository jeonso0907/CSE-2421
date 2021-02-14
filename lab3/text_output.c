/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"
#include "debug.h"
#include <stdlib.h>
#include "memory_func.h"
#include "output.h"
#include "memory.h"
#include "bits.h"
#include "calculate.h"

void allocate_output(struct Firework *f, int num_allocated) {
		if (TEXT) {
				printf("DIAGNOSTIC: Allocating space for code %X. %d allocated.\n", f->hex, num_allocated);
		}
}

void dynamic_error_output() {
		printf("ERROR:memory.c:to_dynamic_memory:malloc failed\n");
}

void effect_output(struct Firework *f) {
		if (get_flash(f->hex)) printf("Flash at Flash at (%6.2lf, %6.02lf)'\n", f->x, f->y);
		if (get_bang(f->hex)) printf("Boom at (%6.2lf, %6.2lf)'\n", f->x, f->y);
}

void free_output(void *data) {
		static int num_freed = 1;
		struct Firework *f; 
		f = data;
		last_pos(f);
		printf("\nColor #%d starburst at (%6.2lf, %6.2lf)'\n", get_color(f->hex), f->x, f->y);
		effect_output(f);
		printf("DIAGNOSTIC: Freeing firework with code %X.  %d freed.\n", f->hex, num_freed);
		num_freed++;
}


void et_output(struct Sim *s) {
		if (TEXT) {
				double ET = s->et;
				printf("\n At ET =  %.3lf (%.15lf) second:", ET, ET);
				printf("\n    Code     (      X,       Y)'  (     VX,      VY) fps       Fuse sec");
		}
}

void data_output(void *data) {
		struct Firework *f;
		f = data;
		if (f->sim->et >= f->time) {
				printf("\n%X at  (%7.2lf, %7.2lf)'  (%7.2lf, %7.2lf) fps with %4.3lf sec", f->hex, f->x, f->y, f->vx, f->vy, f->fuse);
		} else {
				printf("\n%X at  (%7.2lf, %7.2lf)'  Holding until %.3lf", f->hex, f->x, f->y, f->time);
		}
}

void range_safety_output(struct Firework *f) {
		if (f->vy < 0) printf("\nRANGE SAFETY WARNING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.", f->hex, f->y, f->x, f->fuse);
}

void space_output(struct Sim *s, double least_fuse) {
		if (s->et > 0) {
				if (least_fuse < s->dt) printf("\n");	
				else printf("\n\n");
		}
}

void call_text_output(struct Sim *s) {
		double least_fuse = 0;
		et_output(s);
		iterate_struct(s, &data_output);
		get_et(s);
		least_fuse = least_struct(s, get_least_fuse);
		deleteSome_struct(s, &free_output);
		space_output(s, least_fuse);
		iterate_struct(s, &update_data);
		sort_struct(s);
}
