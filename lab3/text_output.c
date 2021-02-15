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
				printf("DIAGNOSTIC: Allocating space for code %X.  %d allocated.\n", f->hex, num_allocated);
		}
}

void dynamic_error_output() {
		printf("ERROR:memory.c:to_dynamic_memory:malloc failed\n");
}

void effect_output(struct Firework *f) {
		printf("\nColor #%d starburst at (%6.2lf, %6.2lf)'\n", get_color(f->hex), f->x, f->y);
		if (get_flash(f->hex)) printf("Flash at (%6.2lf, %6.02lf)'\n", f->x, f->y);
		if (get_bang(f->hex)) printf("Boom at (%6.2lf, %6.2lf)'\n", f->x, f->y);
}

void free_output(void *data) {
		static int num_freed = 1;
		struct Firework *f; 
		f = data;
		last_pos(f);
		if ((f->y > 0 || f->time < f->sim->et) && f->fuse < f->sim->dt) effect_output(f);
		else printf("\n");
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
		if (f->vy < 0 && f->y > 0) printf("\nRANGE SAFETY WARNING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.", f->hex, f->y, f->x, f->fuse);
		if (f->y < 0) printf("\nRANGE SAFETY WARNING: At %.3lf sec %X (made on 8-10-1978) impacts at (%6.2lf,%6.2lf)' with %.3lf seconds remaining", f->sim->et, f->hex, f->x, f->y, f->fuse);
}

void space_output(struct Sim *s, int is_free) { 
		if (s->et > 0) {
				if (is_free) printf("\n");	
				else printf("\n\n");
		}
}

void call_text_output(struct Sim *s) {
		int is_free = 0;
		et_output(s);
		iterate_struct(s, &data_output);
		get_et(s);
		is_free = some_struct(s, &fuse_over);
		deleteSome_struct(s, &free_output);
		iterate_struct(s, &update_data);
		space_output(s, is_free);
		sort_struct(s);
}
