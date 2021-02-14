/* Sooyoung Jeon */

#define FADE 2

void allocate_output(struct Firework *f, int num_allocated);
void dynamic_error_output();
void call_text_output(struct Sim *s);
void call_graphic_output(struct Sim *s);
void range_safety_output(struct Firework *f);
void free_output(void *data);
void data_output(void *data);
