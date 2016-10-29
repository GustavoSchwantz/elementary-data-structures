/* 
 * Abstract Data Structure whith Hash
 * @author: Gustavo Schwantz Oliveira
 * 
 * This is a data structure that consist of many sets,
 * where each set is a hash table. It does use of dou-
 * bly-linked list and hash.
 *
 */

#include "hashset.h"
#include <stdio.h>

#define NUM_SETS 50
#define HASH_SIZE 50

TABLE sets[NUM_SETS];
int id_set;

int create ()
{
	if (id_set < NUM_SETS) {
        table_factory (&sets[id_set], HASH_SIZE);
        return id_set++;
	}

	return -1;
}

int insert (int element, int set)
{
	if (set < id_set) {

		if (!chained_hash_search (&sets[set], element))
            chained_hash_insert (&sets[set], cell_factory (element));

        return 1;
	}

	return -1;
}

int verify (int element, int set)
{
	if (set < id_set && chained_hash_search (&sets[set], element)) 
        return 1;

	return -1;
}

int delete (int element, int set)
{
	if (set < id_set) {

		cel *x;

		if ((x = chained_hash_search (&sets[set], element))) {
            chained_hash_delete (&sets[set], x);
            return 1;
        }

        return -1;
	}

	return 1;
}

int join (int set_a, int set_b)
{
	int new_set;

	if (set_a < id_set && set_b < id_set && (new_set = create ()) != -1) {
        
        LIST *x; cel *y; int i;

        for (i = 0, x = sets[set_a].table; 
        	i < sets[set_a].t_size; ++i, ++x)
        	for (y = x->start; y != NULL; y = y->next)
        		insert (y->content, new_set);

        for (i = 0, x = sets[set_b].table; 
        	i < sets[set_b].t_size; ++i, ++x)
        	for (y = x->start; y != NULL; y = y->next)
        		insert (y->content, new_set);	

        return new_set; 	

	}

	return -1;
} 

void list (int set)
{
	if (set < id_set) {
		LIST *x; cel *y; int i;

        for (i = 0, x = sets[set].table; 
        	i < sets[set].t_size; ++i, ++x)
        	for (y = x->start; y != NULL; y = y->next)
        		printf("%d ", y->content);
	}
}

void end ()
{
	int i;

	for (i = 0; i < id_set; ++i)
		destroy_table (sets[i].table, sets[i].t_size);
}