/* Sooyoung Jeon */

#include "libfire.h"
#include <stdio.h>
#include "func.h"
#include "debug.h"

/*
 * Draws the moving fire work dots
 * Waits delta time for each dot
 */
void draw(double x, double y, int color, double dt, unsigned int hex) {
		fw_clear();
		fw_dot(color, x, y);
		fw_refresh();
		millisleep(dt * 1000);
}

/*
 * Prints the header of the lab with its hex code and delta time
 */
void print_header(unsigned int hex, double dt) {
		printf("\n");
		printf("Lab 2 starting %X with dt=%.3lf ms.\n", hex, dt * 1000);
		printf("\n");
		printf("  E.T. sec  (      X,       Y)'  (     VX,      VY) fps  Fuse sec\n");
}

/*
 * Prints the data within the table format row
 */
void print_data(double time, double x, double y,double vx, double vy, double fuse) {
		printf("%6.3lf sec  (%7.2lf, %7.2lf)'  (%7.2lf, %7.2lf) fps %4.3lf sec\n", time, x, y, vx, vy, fuse);
}

/*
 * Prints the star effect message with its color and location
 */
void print_star(int color, double x, double y) {
		printf("Color #%d starburst at (%6.2lf, %6.2lf)'\n", color, x, y);
}

/*
 * Prints the flash effect message with its location
 */
void print_flash(double x, double y) {
		printf("Flash at (%6.2lf, %6.2lf)'\n", x, y);
}

/*
 * Prints the bang effect message with its location
 */
void print_bang(double x, double y) {
		printf("Boom at (%6.2lf, %6.2lf)'\n", x, y);
}

/*
 * Prints the free fall warning message with its hex code, location, and remaning fuse time
 */
int print_freefall(unsigned int hex, double x, double y, double fuse) {
		printf("RANGE SAFETY WRANING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.\n", hex, y, x, fuse);
		return 0;
}

/*
 * Prints the impcat warning message with its hex code, time, made date, location, and remaing fuse time
 */
int print_impact(double time, unsigned int hex, double x, double y, double fuse) {
		int month = get_month(hex), day = get_day(hex), year = get_year(hex);
		printf("RANGE SAFETY WARNING: At %.3lf sec %X (made on %d-%d-%d) impacts at (%.2lf, %.2lf)' with %.3lf seconds remaining\n", time, hex, month, day, year, x, y, fuse);
		return 1;
}

/*
 * Based on the mode, either draw or print the star effect
 */
void draw_star(double x, double y, int color) {
		if (GRAPHICS) fw_star(color, x, y); 
		if (TEXT) print_star(color, x, y); 
}

/*
 * Based on the mode, either draw or print the flash effect
 * Only operates when the flash effect is available
 */
void draw_flash(unsigned int hex, double x, double y) {
		int flash = get_flash(hex);
		if (flash && GRAPHICS) fw_flash();
		if (flash && TEXT) print_flash(x, y); 
}

/*
 * Based on the mode, either draw or print the bang effect
 * Only operates when the bang effect is available
 */
void draw_bang(unsigned int hex, double x, double y) {
		int bang = get_bang(hex);
		if (bang && GRAPHICS) fw_bang();
		if (bang && TEXT) print_bang(x, y); 
}				

/*
 * Draws the effects of the fire work
 */
void draw_effect(double hex, double x, double y, int color) {
		draw_star(x, y, color);
		draw_flash(hex, x, y);
		draw_bang(hex, x, y);
}

/*
 *  * Draws the fade effect for 2 seconds and clear the graphics
 *   */
void fade(double dt) {
		double i = 0;
		for (i; i < FADE; i += dt) {
				fw_clear();
				fw_refresh();
				millisleep(dt * 1000);
		}   
}

/*
 * Runs the simulation with the input data
 * Based on the mode, either draw or print the data
 * If the firework starts to free fall or impacts on the ground, print proper range safety message
 * Runs the simulation until the fuse goes off
 */
void run(int color, double time, double fuse, unsigned int hex,  double x, double y, double vx, double vy, double dt){
		int end = 0, freefall = 1;
		while (fuse > 0) {
				if (GRAPHICS) draw(x, y, color, dt, hex);
				if (TEXT && (vy < 0) && freefall) freefall = print_freefall(hex, x, y, fuse);
				if (TEXT && (y < 0)) end = print_impact(time, hex, x, y, fuse);
				if (end) break;
				if (TEXT) print_data(time, x, y, vx, vy, fuse);
				x = get_x(x, vx, dt);
				y = get_y(y, vy, dt);
				vy = get_vy(vy, dt);
				time += dt;
			    fuse -= dt;
		}
		if (y > 0) draw_effect(hex, x, y, color);
}

/*
 * Initializes the simulation of the fireworks
 * Gets the base information to run the simulation
 */
void simulate(double time, unsigned int hex, double fuse, double x, double vx, double vy) {
		double dt = 0, y = 0;
		int color = 0;

		dt = get_dt(vy);
		color = get_color(hex);
		if (TEXT) print_header(hex, dt);
		run(color, time, fuse, hex, x, y, vx, vy, dt);
		if (GRAPHICS) fade(dt);
}
