/* Sooyoung Jeon */

#include "func.h"
#include "libfire.h"
#include "debug.h"
#include <stdio.h>

/*
 * Loop and read until the end of the line in the file
 * Initialize the simulation functions to either draw graph or output the data
 */
void read() {
		double time = 0, fuse = 0, x = 0, vx = 0, vy = 0;
		unsigned int hex;
		while (scanf("%lf %X %lf %lf %lf %lf\n", &time, &hex, &fuse, &x, &vx, &vy) == 6) {
				simulate(time, hex, fuse, x, vx, vy);
		}
}

/*
 * Print out the end message with the total running time
 */
void end(double run_time) {
		printf("Ending: scanf returned -1\n");
		printf("Total run time is %.9lf seconds.\n", run_time);
}

/*
 * Initialize the either graphics or text mode to start
 */
int main() {
		double start_time = 0, end_time = 0, run_time = 0;
		
		start_time = now();
		if (TEXT || (GRAPHICS && fw_initialize())) {
				read();
				if (GRAPHICS) fw_teardown();
		}
		end_time = now();
		run_time = end_time - start_time;
		end (run_time);
		return 0;
}
