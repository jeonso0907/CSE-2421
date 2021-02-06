/* Sooyoung Jeon */

#include "func.h"
#include "gravity.h"
#include "libfire.h"

/*
 * Calculate the delta time
 */ 
double get_dt(double vy) {
		return (0.25 * fw_get_delta_Y()) / vy;
}

/*
 * Calculate the x position
 */
double get_x(double x, double vx, double dt) {
		return x + vx * dt;
}

/*
 * Calculate the y position
 */
double get_y(double y, double vy, double dt) {
		return y + vy * dt + 0.5 * GRAVITY * dt *dt;
}

/*
 * Calculate the y velocity
 */
double get_vy(double vy, double dt) {
		return vy + GRAVITY * dt;
}
