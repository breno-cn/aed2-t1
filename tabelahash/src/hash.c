#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "hash.h"

HashTable*
hashtable_new(int size)
{
    HashTable *hash_table = NULL;

    if(size < 1)
        return NULL;

    if((hash_table = malloc(sizeof(HashTable))) == NULL )
        return NULL;

    if((hash_table->tab = malloc(sizeof(Voila *) * size)) == NULL)
        return NULL;

    for(int i = 0; i < size; i++ ) {
        hash_table->tab[i] = NULL;
    }

    hash_table->size = size;
    return hash_table;
}

int
ht_hash(HashTable *tabTermos, char *key)
{
    unsigned long int hashval = 0;

    int i = 0;
    while(hashval < ULONG_MAX && i < strlen(key) ) {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }

    return hashval % tabTermos->size;
}

Voila*
create_keyvalue(char *key, char *value)
{
    Voila *pair;

    if((pair = malloc(sizeof(Voila))) == NULL )
        return NULL;

    strcpy(pair->key, key);
    strcpy(pair->value, value);
    pair->prox = NULL;

    return pair;
}

void
hashtable_insert(HashTable *table, char *key, char *value)
{
    int bin = 0;
    Voila *new_pair = NULL;
    Voila *pos = NULL;
    Voila *ult = NULL;

    bin = ht_hash(table, key);
    pos = table->tab[bin];

    while(pos != NULL && strcmp(key, pos->key ) > 0) {
        ult = pos;
        pos = pos->prox;
    }

    if(pos != NULL && strcmp(key, pos->key) == 0) {
        strcpy(pos->value,value);
    }
    else {
        new_pair = create_keyvalue(key, value);

        if(pos == table->tab[bin]) {
            new_pair->prox = pos;
            table->tab[bin] = new_pair;
        } else if (pos == NULL) {
            ult->prox = new_pair;
        } else  {
            new_pair->prox = pos;
            ult->prox = new_pair;
        }
    }
}

char*
hashtable_search(HashTable *tabTermos, char *key)
{
    int bin = 0;
    Voila *pair;

    bin = ht_hash(tabTermos, key);

    pair = tabTermos->tab[bin];
    while(pair != NULL && strcmp(key, pair->key) > 0) {
        pair = pair->prox;
    }

    if(pair == NULL || strcmp(key, pair->key) != 0) {
        return NULL;
    } else {
        return pair->value;
    }
}


void
hashtable_print(HashTable *tabTermos)
{
    int size;
    Voila *t;

    size = tabTermos->size;
    for (int i = 0; i < size; i++){
        t = tabTermos->tab[i];

        printf("%d:",i);
        while (t != NULL){
            printf("(%s, %s) ",t->key,t->value);
            t = t->prox;
        }
        printf("\n");
    }
}
