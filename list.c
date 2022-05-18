#include "list.h"

list* list_init()
{
    list* bl = (list*)malloc(sizeof(list));	
    bl->last = NULL;
    bl->first = NULL;
	
    return bl;
};

node* node_init(void* data)
{
    node* n = (node*)malloc(sizeof(node)*1);
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
	return n;
};