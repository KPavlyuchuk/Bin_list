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

void list_add(list* bl, void* data)
{
    node* new = node_init(data, err);
	
    if (bl->first == NULL) {
        bl->first = new; 
        bl->last = new;
    } 
	else {
        bl->last->next = new;
        new->prev = bl->last;
        bl->last = new;
    }
}