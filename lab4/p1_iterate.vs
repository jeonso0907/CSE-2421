void dynamic_allocate(struct FW **fptr, struct FW **fptrCopy, struct Sim **site) ;
void iterate(void *p2headptr, void (*func_ptr)(void *data)) ;
int launch_order(void *data1, void *data2);
int main() ;
void print(void *data) ;
