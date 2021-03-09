void deleteSome(void **p2headptr, int (*CriterianFunc)(void *data), void (*ActionFunc)(void *data), int verbose) ;
int insert(void **p2headptr, void *data, int (*ComparisonFunc)(void *data1, void *data2), int verbose) ;
void iterate(void *p2headptr, void (*func_ptr)(void *data)) ;
double least(void *p2headptr, double (*func_ptr)(void *data)) ;
void sort(void *p2headptr, int (*ComparisonFunc)(void *data1, void *data2)) ;
