/* Sooyoung Jeon */

#include "struct.h"
#include "libfire.h"
#include "debug.h"
#include "linkedlist.h"

void run_simulate(struct Firework *f) {
		int i = 0;
		f->sim->dt = least_struct(f);
		while (some_struct(f)) {
				if (TEXT) main_output(f);
		}
}
