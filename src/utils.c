#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "fort.h"

void randomize_transactions(Product *transaction, int len) {
    char *description;
    for (int i = 1; i <= len; i++) {
        description = malloc(12 * sizeof(int));
        sprintf(description, "%.11u", (unsigned) rand());
        strcpy(transaction[i - 1].description, description);

        transaction[i-1].code = (rand() - i) % 100000;
        transaction[i-1].price = (unsigned) rand();
    }
    free(description);
}

void print_transactions(Product *transaction, int len) {
    for (int i = 0; i < len; i++) {
        printf("description: %s value: %.5g id: %d\n", transaction[i].description, transaction[i].price, transaction[i].code);
    }
}

float benchmark_sort(Product *transaction, int len, sort_fn sort, cmp_func cmp) {
    clock_t acc = 0;

    for (int i = 0; i < 10; i++) {
        clock_t start = clock();
        sort(transaction, len, cmp);
        clock_t end = clock();
        clock_t time_elapsed = end - start;

        acc += time_elapsed;
    }

    clock_t avg = acc / 10;
    return ((float) avg / CLOCKS_PER_SEC);
}

float benchmark_bucketsort(Product *transaction, int len) {
    clock_t acc = 0;

    int ids[len];
    for (int i = 0; i < len; i++)
        ids[i] = transaction[i].code;

    for (int i = 0; i < 10; i++)
    {
        clock_t start = clock();
        bucketsort(ids, len);
        clock_t end = clock();
        clock_t time_elapsed = end - start;

        acc += time_elapsed;
    }

    clock_t avg = acc / 10;

    return ((float) avg / CLOCKS_PER_SEC);
}

char ***benchmark_all(Product *transaction, const unsigned int *slices, cmp_func cmp, int is_by_id) {
    char ***sort_times = malloc(8 * sizeof(char **));
    for (int i = 0; i < 7; i++) {
        sort_times[i] = malloc(8 * sizeof(float *));
        for (int j = 0; j < 7; j++) {
            sort_times[i][j] = malloc(10 * sizeof(float *));
        }
    }

    /* Pra slices[0] elementos */
    transaction = malloc(slices[0] * sizeof(Product));
    randomize_transactions(transaction, slices[0]);
    sprintf(sort_times[0][0], "%f", benchmark_sort(transaction, slices[0], insertionsort, cmp));
    randomize_transactions(transaction, slices[0]);
    sprintf(sort_times[1][0], "%f", benchmark_sort(transaction, slices[0], shellsort, cmp));
    randomize_transactions(transaction, slices[0]);
    sprintf(sort_times[2][0], "%f", benchmark_sort(transaction, slices[0], cocktailsort, cmp));
    randomize_transactions(transaction, slices[0]);
    sprintf(sort_times[3][0], "%f", benchmark_sort(transaction, slices[0], pancakesort, cmp));
    randomize_transactions(transaction, slices[0]);
    sprintf(sort_times[4][0], "%f", benchmark_sort(transaction, slices[0], heapsort_, cmp));
    randomize_transactions(transaction, slices[0]);
    sprintf(sort_times[5][0], "%f", benchmark_sort(transaction, slices[0], quicksort, cmp));
    if (is_by_id == 1) {
        randomize_transactions(transaction, slices[0]);
        sprintf(sort_times[6][0], "%f", benchmark_bucketsort(transaction, slices[0]));
    }
    free(transaction);

    /* Pra slices[1] elementos */
    transaction = malloc(slices[1] * sizeof(Product));
    randomize_transactions(transaction, slices[1]);
    sprintf(sort_times[0][1], "%f", benchmark_sort(transaction, slices[1], insertionsort, cmp));
    randomize_transactions(transaction, slices[1]);
    sprintf(sort_times[1][1], "%f", benchmark_sort(transaction, slices[1], shellsort, cmp));
    randomize_transactions(transaction, slices[1]);
    sprintf(sort_times[2][1], "%f", benchmark_sort(transaction, slices[1], cocktailsort, cmp));
    randomize_transactions(transaction, slices[1]);
    sprintf(sort_times[3][1], "%f", benchmark_sort(transaction, slices[1], pancakesort, cmp));
    randomize_transactions(transaction, slices[1]);
    sprintf(sort_times[4][1], "%f", benchmark_sort(transaction, slices[1], heapsort_, cmp));
    randomize_transactions(transaction, slices[1]);
    sprintf(sort_times[5][1], "%f", benchmark_sort(transaction, slices[1], quicksort, cmp));
    if (is_by_id == 1) {
        randomize_transactions(transaction, slices[1]);
        sprintf(sort_times[6][1], "%f", benchmark_bucketsort(transaction, slices[1]));
    }
    free(transaction);

    /* Pra slices[2] elementos */
    transaction = malloc(slices[2] * sizeof(Product));
    randomize_transactions(transaction, slices[2]);
    sprintf(sort_times[0][2], "%f", benchmark_sort(transaction, slices[2], insertionsort, cmp));
    randomize_transactions(transaction, slices[2]);
    sprintf(sort_times[1][2], "%f", benchmark_sort(transaction, slices[2], shellsort, cmp));
    randomize_transactions(transaction, slices[2]);
    sprintf(sort_times[2][2], "%f", benchmark_sort(transaction, slices[2], cocktailsort, cmp));
    randomize_transactions(transaction, slices[2]);
    sprintf(sort_times[3][2], "%f", benchmark_sort(transaction, slices[2], cocktailsort, cmp));
    randomize_transactions(transaction, slices[2]);
    sprintf(sort_times[4][2], "%f", benchmark_sort(transaction, slices[2], heapsort_, cmp));
    randomize_transactions(transaction, slices[2]);
    sprintf(sort_times[5][2], "%f", benchmark_sort(transaction, slices[2], quicksort, cmp));
    if (is_by_id == 1) {
        randomize_transactions(transaction, slices[2]);
        sprintf(sort_times[6][2], "%f", benchmark_bucketsort(transaction, slices[2]));
    }
    free(transaction);

    /* Pra slices[3] elementos */
    transaction = malloc(slices[3] * sizeof(Product));
    randomize_transactions(transaction, slices[3]);
    sprintf(sort_times[0][3], "%f", benchmark_sort(transaction, slices[3], insertionsort, cmp));
    randomize_transactions(transaction, slices[3]);
    sprintf(sort_times[1][3], "%f", benchmark_sort(transaction, slices[3], shellsort, cmp));
    randomize_transactions(transaction, slices[3]);
    sprintf(sort_times[2][3], "%f", benchmark_sort(transaction, slices[3], cocktailsort, cmp));
    randomize_transactions(transaction, slices[3]);
    sprintf(sort_times[3][3], "%f", benchmark_sort(transaction, slices[3], cocktailsort, cmp));
    randomize_transactions(transaction, slices[3]);
    sprintf(sort_times[4][3], "%f", benchmark_sort(transaction, slices[3], heapsort_, cmp));
    randomize_transactions(transaction, slices[3]);
    sprintf(sort_times[5][3], "%f", benchmark_sort(transaction, slices[3], quicksort, cmp));
    if (is_by_id == 1) {
        randomize_transactions(transaction, slices[3]);
        sprintf(sort_times[6][3], "%f", benchmark_bucketsort(transaction, slices[3]));
    }
    free(transaction);

    /* Pra slices[4] elementos */
    transaction = malloc(slices[4] * sizeof(Product));
    randomize_transactions(transaction, slices[4]);
    sprintf(sort_times[0][4], "%f", benchmark_sort(transaction, slices[4], insertionsort, cmp));
    randomize_transactions(transaction, slices[4]);
    sprintf(sort_times[1][4], "%f", benchmark_sort(transaction, slices[4], shellsort, cmp));
    randomize_transactions(transaction, slices[4]);
    sprintf(sort_times[2][4], "%f", benchmark_sort(transaction, slices[4], cocktailsort, cmp));
    randomize_transactions(transaction, slices[4]);
    sprintf(sort_times[3][4], "%f", benchmark_sort(transaction, slices[4], pancakesort, cmp));
    randomize_transactions(transaction, slices[4]);
    sprintf(sort_times[4][4], "%f", benchmark_sort(transaction, slices[4], heapsort_, cmp));
    randomize_transactions(transaction, slices[4]);
    sprintf(sort_times[5][4], "%f", benchmark_sort(transaction, slices[4], quicksort, cmp));
    if (is_by_id == 1) {
        randomize_transactions(transaction, slices[4]);
        sprintf(sort_times[6][4], "%f", benchmark_bucketsort(transaction, slices[4]));
    }
    free(transaction);

    return sort_times;
}

void generate_table(char ***matriz, int is_by_id) {
    ft_table_t *table = ft_create_table();
    const char *slices[6] = { "", "10000", "25000", "50000", "75000", "100000" };

    ft_set_border_style(table, FT_DOUBLE2_STYLE);
    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    /* Center header row */
    for (int i = 0; i < 6; i++) {
        ft_set_cell_prop(table, 0, i, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);
    }

    /* Center non-header rows */
    ft_set_cell_prop(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);

    /* Set header row foreground to cyan and bold */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_CONT_FG_COLOR, 5);
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_TSTYLE_BOLD, (1U << 1));

    ft_write_ln(table,                         slices[0],    slices[1],    slices[2],    slices[3],    slices[4], slices[5]);

    ft_write_ln(table, "Insertion Sort",       matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3], matriz[0][4]);
    ft_write_ln(table, "Shell Sort",           matriz[1][0], matriz[1][1], matriz[1][2], matriz[1][3], matriz[1][4]);
    ft_write_ln(table, "Cocktail Sort",        matriz[2][0], matriz[2][1], matriz[2][2], matriz[2][3], matriz[2][4]);
    ft_write_ln(table, "Pancake Sort",         matriz[3][0], matriz[3][1], matriz[3][2], matriz[3][3], matriz[3][4]);
    ft_write_ln(table, "Heap Sort",            matriz[4][0], matriz[4][1], matriz[4][2], matriz[4][3], matriz[4][4]);
    ft_write_ln(table, "Quick Sort (mediana)", matriz[5][0], matriz[5][1], matriz[5][2], matriz[5][3], matriz[5][4]);
    if (is_by_id == 1) {
        ft_write_ln(table, "Bucket Sort", matriz[6][0], matriz[6][1], matriz[6][2], matriz[6][3], matriz[6][4]);
    }
    
    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
}
