/*
 * Sooyoung Jeon
 * Lab3: memory.h (Functions to control the linked list to access and update the data)
 */

void firework_setup(Firework **fc_ptr1, struct Firework **fc_ptr2, struct Sim **sim_ptr);
void insert_struct(Firework *f);
void iterate_struct(Sim *s, void (*func_ptr)(void *data));
void sort_struct(Sim *s);
int some_struct(Sim *s, int (*func_ptr)(void *data));
double least_struct(Sim *s, double (*func_ptr)(void *data));
void deleteSome_struct(Sim *s, void (*func_ptr)(void *data));
