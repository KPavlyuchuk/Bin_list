#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    void* data;
    struct _node* next;
    struct _node* prev;
} node;

typedef struct bin_list
{
    node* first;
    node* last; 
} list;

node* node_init(void*);
list* list_init();
void list_add(list*, void*);
void list_free(list**);
void list_insert(list*, node*, void*);
void list_remove(list*, node*);

