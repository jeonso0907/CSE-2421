double decel_and_warn(struct FW *fptr, double dt);
double effective_dt(struct FW *fptr);
int more_to_come(struct Sim *site);
double newX( struct FW *fptr, double dt);
double newY(struct FW *fptr, double dt);
void set_dt(struct FW *fptr, struct Sim *site) /* in seconds */;
void update_all_fireworks(struct Sim *site) /* X, Y, VY, fuse */;
void update_clock(struct Sim *site) /* sim clock and fuses */;
void update_one_firework(void *data) /* in time and space */;
