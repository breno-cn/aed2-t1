struct voila{
  char key[30];
  char value[30];
  struct voila *prox;
};
typedef struct voila Voila;

struct hashTable {
	int size;
	Voila **tab;
};
typedef struct hashTable HashTable;

HashTable *hashtable_new (int size);
char* hashtable_search(HashTable *table, char *key);
void hashtable_print(HashTable *table);
void hashtable_insert(HashTable *table, char *key, char *value);

