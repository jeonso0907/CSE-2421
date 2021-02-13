/* Sooyoung Jeon */

#include "struct.h"
#include "libfire.h"
#include "debug.h"
#include "linkedlist.h"

void run_simulate(struct Sim *s) {
			s->et = now();
			iterate_print(s);	
}
