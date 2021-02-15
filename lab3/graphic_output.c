/* Sooyoung Jeon */

#include "libfire.h"
#include "struct.h"
#include "bits.h"
#include "memory.h"
#include "memory_func.h"
#include "calculate.h"

void draw_dot(void *data) {
		struct Firework *f;
		f = data;
		fw_dot(get_color(f->hex), f->x, f->y);
}

void draw_star(struct Firework *f) {
		fw_star(get_color(f->hex), f->x, f->y);
}

void draw_effect(void *data) {
		struct Firework *f = data;
		draw_star(f);
		if (get_flash(f->hex)) fw_flash();
		if (get_bang(f->hex)) fw_bang();
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
