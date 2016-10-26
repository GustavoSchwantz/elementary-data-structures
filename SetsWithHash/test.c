#include <stdio.h>
#include "hashset.h"
#include "simpletest.h"

#define NSETS 50
#define SSIZE 10

TABLE sets[NSETS];

void test_create ()
{
    isEqual (create (sets, NSETS, SSIZE), 0);
    isEqual (create (sets, NSETS, SSIZE), 1);
    isEqual (create (sets, NSETS, SSIZE), 2);
}

int main(int argc, char const *argv[])
{
	test_create ();

	return 0;
}