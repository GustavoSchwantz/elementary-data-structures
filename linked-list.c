/* 
 * Simple Doubly-Linked List 
 * @author: Gustavo Schwantz Oliveira
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void list_init (LIST *l)
{
	l->start = NULL;
}

cel *cell_factory (int c)
{
	cel *x;
	x = malloc (sizeof (cel));
	x->content = c;

	return x;
}

cel *list_search (LIST *l, int c) 
{
	cel *x = l->start;

	while (x != NULL && x->content != c) 
        x = x->next;

	return x;
}

void list_insert (LIST *l, cel *x)
{
	x->next = l->start;

	if (l->start != NULL)
		l->start->last = x;

	l->start = x;
	x->last = NULL;
}

void list_delete (LIST *l, cel *x)
{
	if (x->last != NULL)
		x->last->next = x->next;
    else 
        l->start = x->next;

    if (x->next != NULL)
        x->next->last = x->last;

    free (x);
}

void print_list (LIST *l)
{
	cel *x;

	for (x = l->start; x != NULL; x = x->next)
		printf("%d\n", x->content);
}

void destroy_list (LIST *l)
{
	cel *x;

	for (x = l->start; x != NULL; x = x->next)
		free (x);

	l->start = NULL;
}
