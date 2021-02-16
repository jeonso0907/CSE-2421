/*
 * Sooyoung Jeon
 * Lab3: memory_func.h (Functions to advocate the memory.c)
 */

int firework_valid(void *data);
int is_free(void *data);
void last_pos(Firework *f);
double effective_dt(Firework *f);
void update_data(void *data);
double get_least_dt(void *data);
double get_least_fuse(void *data);
int is_not_null(void *data);
int first_time(void *data1, void *data2);
int sort_y(void *data1, void *data2);
void print_data(void *data);
void iterate_range_safety(void *data);
