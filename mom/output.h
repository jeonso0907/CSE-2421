/*
 * Sooyoung Jeon
 * Lab3: output.h (Functions to print data in both text and graphics mode)
 */

#define FADE 2

void allocate_output(Firework *f, int num_allocated);
void dynamic_error_output();
void call_debug_output(Sim *s);
void range_safety_output(Firework *f);
void free_output(void *data);
void data_output(void *data);
void debug_output(void *data);
void call_text_output(Sim *s);
void call_graphic_output(Sim *s);
void call_output(Sim *s);
void run_simulate(Sim *s);
