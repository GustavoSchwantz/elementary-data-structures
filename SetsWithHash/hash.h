#include "linked-list.h"

#define FACTOR 2

struct table {
	int t_size;
	int elements;
	LIST *table;
};

typedef struct table TABLE;

int h (int k, int n);
void table_factory (TABLE *t, int n);
void chained_hash_insert (TABLE *t, cel *x);
cel *chained_hash_search (TABLE *t, int k);
void chained_hash_delete (TABLE *t, cel *x);
void rehash (TABLE *t);
void destroy_table (LIST *table, int n);
int load_factor (int e, int s);