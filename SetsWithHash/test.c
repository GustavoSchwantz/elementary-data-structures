#include <stdio.h>
#include "hashset.h"
#include "simpletest.h"

void test_create ()
{
    isEqual (create (), 0);
    isEqual (create (), 1);
    isEqual (create (), 2);
    isEqual (create (), 3);
    isEqual (create (), 4);
    isEqual (create (), -1);
    isEqual (create (), -1);
}

void test_insert ()
{
	create ();
	isEqual (insert (1, 0), 1);
	isEqual (insert (2, 0), 1);
	isEqual (insert (1, 0), 1);
	isEqual (insert (1, 1), -1);
}

void test_verify ()
{
	create ();
	insert (10, 0);
	insert (2, 0);
	isEqual (verify (10, 0), 1);
	isEqual (verify (1, 0), -1);
	isEqual (verify (2, 1), -1);
}

void test_delete ()
{
	create ();
	insert (10, 0);
	insert (2, 0);
	isEqual (delete (10, 1), 1);
	isEqual (verify (10, 0), 1);
	isEqual (verify (3, 0), -1);
}

void test_join ()
{
	create ();
	create ();
	insert (10, 0);
	insert (2, 0);
	insert (11, 1);
	isEqual (join (0, 1), 2);
}

void test_list ()
{
	create ();
	create ();
	insert (10, 0);
	insert (2, 0);
	insert (11, 0);
	insert (3, 0);
	insert (22, 1);
	insert (13, 1);
	insert (30, 1);
	join (0, 1);
	list (2);
}

int main(int argc, char const *argv[])
{
	test_list ();
	end ();

	return 0;
}