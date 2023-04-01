#include <stdio.h>
#include <stdlib.h>
#include "src/sort.h"
#include "src/utils.h"

const unsigned int slices[5] = { 10000, 25000, 50000, 75000, 100000 };

int main (int argc, char *argv[])
{
    struct Product *products;
    char ***id_table = benchmark_all(products, slices, cmp_cod, 1);
    printf("\n                         Time sorted by id (seconds)\n");
    generate_table(id_table, 1);

    char ***cpf_table = benchmark_all(products, slices, cmp_price, 0);
    printf("\n                         Times sorted by cpf (seconds)\n");
    generate_table(cpf_table, 0);

    char ***value_table = benchmark_all(products, slices, cmp_description, 0);
    printf("\n                         Times sorted by value (seconds)\n");
    generate_table(value_table, 0);

    // free(id_table);
    // free(cpf_table);
    // free(value_table);
    return 0;
}
