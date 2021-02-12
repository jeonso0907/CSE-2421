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

void insert_struct(struct Firework *f);
void delete_struct(struct Sim *s);
void run_simulate(struct Sim *s);

double get_dt(double vy);
