/* Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "libfire.h"
#include "memory.h"
#include "memory_func.h"
#include "debug.h"
#include "calculate.h"
#include "bits.h"
#include "output.h"

/* GRAPHIC OUTPUT */
void draw_dot(void *data) {
		struct Firework *f;
		f = data;
		if (f->y > 0) fw_dot(get_color(f->hex), f->x, f->y);
}

void draw_star(struct Firework *f) {
		fw_star(get_color(f->hex), f->x, f->y);
}

void draw_effect(void *data) {
		struct Firework *f = data;
		double y = f->y, vy = f->vy, edt = effective_dt(f), next_y = 0;
		next_y = get_y(y, vy, edt);
		if (next_y > 0)draw_star(f);
		if (get_flash(f->hex) && next_y > 0) fw_flash();
		if (get_bang(f->hex) && next_y > 0) fw_bang();
		if (f->fuse > 0 && next_y < 0) fw_status("RANGE SAFETY: Impact!");
}

void draw_fade(struct Sim *s) {
		double i = 0;
		for (i; i < FADE; i += (s->dt)) {
				fw_clear();
				fw_refresh();
				millisleep(s->dt * 1000);
		}
}

void call_graphic_output(struct Sim *s) {
		fw_clear();
		iterate_struct(s, &draw_dot);
		fw_refresh();
		millisleep(s->dt * 1000);
		get_et(s);
		deleteSome_struct(s, &draw_effect);
		iterate_struct(s, &update_data);
		sort_struct(s);
		if (!some_struct(s, &is_not_null)) draw_fade(s);
}

/* TEXT OUTPUT */
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
		double vy = f->vy, vx = f->vx, y = f->y, x = f->x, fuse = f->fuse, edt = effective_dt(f);
		if (get_vy(vy, edt) < 0 && f->y > 0 && !(f->range_safety_printed)) { 
				f->range_safety_printed = 1;
				printf("\nRANGE SAFETY WARNING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.", f->hex, get_y(y, vy, edt), get_x(x, vx, edt), fuse - edt);
		}
		if (get_y(y, vy, edt) < 0) printf("\nRANGE SAFETY WARNING: At %.3lf sec %X (made on %d-%d-%d) impacts at (%6.2lf,%6.2lf)' with %.3lf seconds remaining", f->sim->et, f->hex, get_month(f->hex), get_day(f->hex), get_year(f->hex), get_x(x, vx, edt), get_y(y, vy, edt), fuse - edt);
}

void space_output(struct Sim *s, int is_free_result) {
		if (s->et > 0) {
				if (is_free_result) printf("\n");
				else printf("\n\n");
		}
}

void debug_output(void *data) {
		struct Firework *f = data;
		double edt = effective_dt(f);
		if (f->y > 0) printf("\neffective_dt: %X IN AIR  ET=%.4lf, L=%.4lf, F=%.4lf dt=%.6lf. rval= %.4lf", f->hex, f->sim->et, f->time, f->fuse, f->sim->dt, edt);
		else if (f->sim->et >= f->time) printf("\neffective_dt: %X LAUNCH ET=%.4lf, L=%.4lf, F=%.4lf dt=%.6lf. rval= %.4lf", f->hex, f->sim->et, f->time, f->fuse, f->sim->dt, edt);
		else printf("\neffective_dt: %X HOLD ET=%.4lf, L=%.4lf, F=%.4lf, dt=%.6lf. rval= %.4lf", f->hex, f->sim->et, f->time, f->fuse, f->sim->dt, edt);
		if ((f->y > 0 || f->time < f->sim->et) && f->fuse < f->sim->dt) printf("\neffective_dt: %X  - clipping to fuse time.", f->hex);
		range_safety_output(f);
}

void call_text_output(struct Sim *s) {
		int is_free_result = 0;
		et_output(s);
		iterate_struct(s, &data_output);
		get_et(s);
		is_free_result = some_struct(s, &is_free);
		if (DEBUG) iterate_struct(s, &debug_output);
		else iterate_struct(s, &iterate_range_safety);
		deleteSome_struct(s, &free_output);
		iterate_struct(s, &update_data);
		space_output(s, is_free_result);
		sort_struct(s);
}
