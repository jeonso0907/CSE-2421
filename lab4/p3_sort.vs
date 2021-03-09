int compare(void *data1, void *data2) ;
void dynamic_allocate(struct FW **fptr, struct FW **fptrCopy, struct Sim **site) ;
int launch_order(void *data1, void *data2);
int main() ;
void print(void *p2headptr) ;
void sort(void *p2headptr, int (*ComparisonFunc)(void *data1, void *data2)) ;
