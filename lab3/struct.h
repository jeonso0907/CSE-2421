/* Sooyoung Jeon */

struct Firework {
	double time;
	unsigned int hex;
	double fuse;
	double x;
	double y;
	double vx;
	double vy;
	int range_safety_printed;
	struct Sim *sim;
};

struct Sim {
	double et;
	double dt;
	void *list;
};
