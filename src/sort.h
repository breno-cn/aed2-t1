#ifndef _SORTH_
#define _SORTH_

#define DESCRIPTION_SIZE 64

typedef struct Product {
    int code;
    char description[DESCRIPTION_SIZE];
    double price;
} Product;

typedef int (*cmp_func) (Product*, Product*);
typedef void (*sort_fn) (Product*, int, cmp_func);

int cmp_cod(Product *pr1, Product *pr2);
int cmp_description(Product *pr1, Product *pr2);
int cmp_price(Product *pr1, Product *pr2);

void insertionsort(Product *products, int len, cmp_func cmp);
void shellsort(struct Product *products, int len, cmp_func cmp);
void pancakesort(Product* arr, int n, cmp_func cmp);
void heapsort_(Product arr[], int n, cmp_func cmp);
void cocktailsort(Product *products, int len, cmp_func cmp);
void bucketsort(int array[], int len);
void quicksort(Product *array, int len, cmp_func cmp);

#endif