/* Sooyoung Jeon */

void firework_setup(struct Firework **fc_ptr1, struct Firework **fc_ptr2, struct Sim **sim_ptr);
void insert_struct(struct Firework *f);
void iterate_struct(struct Sim *s, void (*func_ptr)(void *data));
void sort_struct(struct Sim *s);
int some_struct(struct Sim *s);
double least_struct(struct Sim *s, double (*func_ptr)(void *data));
void deleteSome_struct(struct Sim *s, void (*func_ptr)(void *data));
