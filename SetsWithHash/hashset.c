#include "hashset.h"

int id_set;

int create (TABLE *sets, int nsets, int size)
{
	if (id_set != nsets) {
        table_factory (&sets[id_set], size);
        return id_set++;
	}

	return -1;
}

int insert (int element, int set, TABLE *sets)
{
	if (set < id_set) {

		cel *x;

		if ((x = chained_hash_search (sets[set], element)) == NULL)
            chained_hash_insert (&set, cell_factory (element));

        return 1;
	}

	return -1;
}