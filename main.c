#include <stdio.h>
#include <stdlib.h>
#include "src/sort.h"
#include "src/utils.h"

const unsigned int slices[5] = { 10000, 25000, 50000, 75000, 100000 };
// const unsigned int slices[5] = { 10, 100, 1000, 10000, 100000 };
// const unsigned int slices[5] = { 1000, 2000, 5000, 7500, 10000 };

int main (int argc, char *argv[])
{
    Product *products = malloc(slices[4] * sizeof(Product));
    int *ids = malloc(slices[4] * sizeof(int));

    char ***id_table = benchmark_all(products, slices, cmp_cod, ids);
    printf("\n                         Time sorted by id (seconds)\n");
    generate_table(id_table, 1);

    char ***price_table = benchmark_all(products, slices, cmp_price, NULL);
    printf("\n                         Times sorted by price (seconds)\n");
    generate_table(price_table, 0);

    char ***description_table = benchmark_all(products, slices, cmp_description, NULL);
    printf("\n                         Times sorted by description (seconds)\n");
    generate_table(description_table, 0);

    free(products);
    free(ids);
    // free(id_table);
    // free(cpf_table);
    // free(value_table);
    return 0;
}
