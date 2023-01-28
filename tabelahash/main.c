#include <stdio.h>
#include <stdlib.h>
#include "src/hash.h"

int menu();


int main(void) {
    HashTable *ht;
    int hashtable_size = 10;
    int user_option;
    char key[30], value[30], *value_returned;

    ht = hashtable_new(hashtable_size);


    printf("Voila!\n");
    do {
        user_option = menu();
        switch (user_option) {
            case 1:
                printf("Type the new URL: ");
                scanf("%s", key);
                char fullurl[30];
                sprintf(fullurl, "voila.xyz/%s", key);
                hashtable_insert(ht, key, fullurl);
                printf("URL created!\n\n");

                break;
            case 2:
                printf("Search for a URL: ");
                scanf("%s", key);

                value_returned = hashtable_search(ht, key);
                if (value_returned != NULL) {
                    printf("\nFull URL: %s -> %s\n\n", key, value_returned);
                } else {
                    printf("\nURL doesn't exist\n\n");
                }

                break;
            case 3:
                hashtable_print(ht);
                printf("\n");
                break;
        }
    } while (user_option != 0);

    return 0;
}

int
menu()
{
    int option;

    printf("[1]. Insert new URLs\n");
    printf("[2]. Get the full URL\n");
    printf("[3]. Print all URLs\n");
    printf("[0]. Quit\n");
    printf("Option: ");
    scanf("%d",&option);
    getchar();

    return option;
}
