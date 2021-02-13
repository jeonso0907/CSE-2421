/* Sooyoung Jeon */

#define GRAVITY -32.17405

struct Firework {
	double time;
	unsigned int hex;
	double fuse;
	double x;
	double vx;
	double vy;
	struct Sim *sim;
};

struct Sim {
	double et;
	double dt;
	void *list;
};

void to_dynamic_memory(struct Firework **fc_ptr);
void iterate_struct(struct Sim *s);
void iterate_print(struct Sim *s);
int insert_struct(struct Firework *f);
void delete_struct(struct Sim *s);

void run_simulate(struct Sim *s);
void main_output(struct Firework *f, int num_allocated);

double get_dt(double vy);

