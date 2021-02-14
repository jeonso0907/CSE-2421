/* Sooyoung Jeon */

#include "struct.h"
#include "libfire.h"
#include "debug.h"
#include "linkedlist.h"
#include "output.h"
#include "memory.h"
#include "memory_func.h"

void call_output(struct Sim *s) {
		if (TEXT) call_text_output(s);
		if (GRAPHICS) call_graphic_output(s);
}

void run_simulate(struct Sim *s) {
		int i = 0;
		s->dt = least_struct(s, &get_least_dt);
		while (some_struct(s)) {
				call_output(s);
		}
}
