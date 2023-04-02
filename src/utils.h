#ifndef _UTILSH_
#define _UTILSH_

#include "sort.h"
typedef int(*cmp_func)(Product*, Product*);

#endif

long random_id_from_time(unsigned long u_id);
void randomize_transactions(struct Product *products, int len);
void print_transactions(struct Product *products, int len);
char ***benchmark_all(Product *products, const unsigned int *slices, cmp_func cmp, int* ids);
void generate_table(char ***matriz, int is_by_id);
