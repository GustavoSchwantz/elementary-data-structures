#include <stdlib.h>
#include "hash.h"

int h (int k, int n)
{
	return k % n;
}

void table_factory (TABLE *t, int n)
{
	t->t_size = n;
	t->elements = 0;
	t->table = (LIST*) malloc (sizeof (LIST)*n);

    int i;

    for (i = 0; i < n; i++)
    	list_init (&t->table[i]);
}

void chained_hash_insert (TABLE *t, cel *x)
{
	if (load_factor (t->elements, t->t_size))
		rehash (t);

	t->elements++;
    list_insert (&t->table[h (x->content, t->t_size)], x);
}

cel *chained_hash_search (TABLE *t, int k)
{
	return list_search (&t->table[h (k, t->t_size)], k);
}

void chained_hash_delete (TABLE *t, cel *x)
{
	t->elements--;
    list_delete (&t->table[h (x->content, t->t_size)], x);
}

void rehash (TABLE *t)
{
	LIST *old_Table;

	old_Table = t->table;

	table_factory (t, t->t_size*2);

	int i;
	cel *x;

	for (i = 0; i < (t->t_size/2); i++) {
        for (x = old_Table[i].start; x != NULL; x = x->next) {
        	chained_hash_insert (t, cell_factory (x->content));
        }
	}

	destroy_table (old_Table, t->t_size/2);
}

void destroy_table (LIST *table, int n)
{
	int i;

	for (i = 0; i < n; i++) {
        destroy_list (&table[i]);
	}

	free (table);
}

int load_factor (int e, int s)
{
	return (e/s == FACTOR) ? 1 : 0;
}