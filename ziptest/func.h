/* Sooyoung Jeon */

/* Define the fading time */
#define FADE 2

/* Define the color shift and bits to mask  */
#define COLOR_SHIFT 24
#define COLOR_BITS 0xF

/* Define the effect shift and bits to mask */
#define FLASH_SHIFT 30
#define BANG_SHIFT 29
#define EFFECT_BITS 0x1

/* Define the made date shift and bits to mask */
#define DAY_SHIFT 16
#define DAY_BITS 0xFF
#define MONTH_SHIFT 12
#define MONTH_BITS 0xF
#define YEAR_SHIFT 0
#define YEAR_BITS 0xFFF

void simulate(double time, unsigned int hex, double fuse, double x, double vx, double vy);

double get_dt(double vy);
double get_x(double x, double vx, double dt);
double get_y(double y, double vy, double dt);
double get_vy(double vy, double dt);

int get_color(unsigned int hex);
int get_flash(unsigned int hex);
int get_bang(unsigned int hex);
int get_day(unsigned int hex);
int get_month(unsigned int hex);
int get_year(unsigned int hex);
