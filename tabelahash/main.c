#include <stdio.h>
#include <stdlib.h>
#include "src/hash.h"

int main(void) {
    HashTable *ht;
    int hashtable_size = 10;
    int user_option;
    char key[30], value[30], *value_returned;

    ht = hashtable_new(hashtable_size);

    hashtable_insert(ht, "bkzm", "gcg.sh/bkzm");

    printf("Search for a URL: ");
    scanf("%s", key);

    value_returned = hashtable_search(ht,key);
    if (value_returned != NULL) {
        printf("\nFull URL: %s -> %s", key, value_returned);
    } else {
        printf("\nURL doesn't exist");
    }

    printf("\nSee all URLS? (0/1) ");
    scanf("%d", &user_option);
    if (user_option == 1)
        hashtable_print(ht);

    return 0;
}

