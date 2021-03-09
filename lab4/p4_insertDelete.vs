int insert(void **p2headptr, void *data, int (*ComparisonFunc)(void *data1, void *data2), int verbose) ;
int is_done(void *data) ;
int launch_order(void *data1, void *data2);
int main() ;
void print(void *p2headptr) ;
void print_deleted_message(void *data) ;
void print_list_size(void *p2headptr) ;
