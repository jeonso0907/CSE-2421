/* Sooyoung Jeon */

int fuse_over(void *data);
void last_pos(struct Firework *f);
double effective_dt(struct Firework *f);
void update_data(void *data);
double get_least_dt(void *data);
double get_least_fuse(void *data);
int is_not_null(void *data);
int first_time(void *data1, void *data2);
int sort_y(void *data1, void *data2);
void print_data(void *data);
