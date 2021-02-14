/* Sooyoung Jeon */

#define GRAVITY -32.17405

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

struct Firework {
	double time;
	unsigned int hex;
	double fuse;
	double x;
	double y;
	double vx;
	double vy;
	struct Sim *sim;
};

struct Sim {
	double et;
	double dt;
	void *list;
};

void firework_setup(struct Firework **fc_ptr1, struct Firework **fc_ptr2, struct Sim **sim_ptr);
void iterate_struct(struct Sim *s);
void iterate_print(struct Firework *f);
void insert_struct(struct Firework *f);
void delete_struct(struct Sim *s);
double least_struct(struct Firework *f);
void deleteSome_struct(struct Firework *f);
int some_struct(struct Firework *f);
void iterate_update(struct Firework *f);

void run_simulate(struct Firework *f);

void allocate_output(struct Firework *f, int num_allocated);
void main_output(struct Firework *f);
void free_output(void *data);
void range_safety_output(struct Firework *f);

double get_edt(double et, double time);
double get_dt(double vy);
double get_x(double x, double vx, double dt);
double get_y(double y, double vy, double dt);
double get_vy(double vy, double dt);

int get_color(unsigned int hex);
int get_flash(unsigned int hex);
int get_bang(unsigned int hex);
