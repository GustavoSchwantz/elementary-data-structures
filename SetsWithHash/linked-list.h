struct reg {
    int content;
    struct reg *next;
    struct reg *last;
};

struct list {
	struct reg *start;
};

typedef struct reg cel;
typedef struct list LIST;

void list_init (LIST *l);
cel *cell_factory (int c);
cel *list_search (LIST *l, int c);
void list_insert (LIST *l, cel *x);
void list_delete (LIST *l, cel *x);
void print_list (LIST *l);
void destroy_list (LIST *l);