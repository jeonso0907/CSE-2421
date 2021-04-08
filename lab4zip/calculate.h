/*
 * Sooyoung Jeon
 * Lab3: calculate.h (Functions to calculate the physical motion of the firework)
 */

#define GRAVITY -32.17405

double get_edt(double et, double time);
double get_dt(double vy);
void get_et(Sim *s);
double get_x(double x, double vx, double dt);
double get_y(double y, double vy, double dt);
double get_vy(double vy, double dt);
