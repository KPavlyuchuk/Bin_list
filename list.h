#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

typedef enum {
	ESUCCESS = 0,
	EINVARG,
	EALLOC,
	EEMPTY
} LIST_ERR;

node* node_init(void*, LIST_ERR *err);
list* list_init(LIST_ERR *err);
void list_add(list*, void*, LIST_ERR *err);
void list_free(list**, LIST_ERR *err);
void list_insert(list*, node*, void*, LIST_ERR *err);
void list_remove(list*, node*, LIST_ERR *err);
node* list_find(list*, void*, int (*cmp)(void *a,void *b), LIST_ERR *err);
