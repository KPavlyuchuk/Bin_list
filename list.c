#include "list.h"

list* list_init(LIST_ERR *err)
{
    list* bl = (list*)malloc(sizeof(list));	
	
	if (bl == NULL) {
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EALLOC;
		return NULL;
	}
	
    bl->last = NULL;
    bl->first = NULL;
	*err = ESUCCESS;

    return bl;
};

node* node_init(void* data, LIST_ERR *err)
{
    node* n = (node*)malloc(sizeof(node)*1);
	
	if (n == NULL) {
		free(n);
		fprintf(stderr, "Not enough memory\n");
		if (err != NULL)
			*err = EALLOC;
		return NULL;
	}
	
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
	
	*err = ESUCCESS;
	return n;
};

void list_add(list* bl, void* data, LIST_ERR *err)
{
    node* new = node_init(data, err);
	
	if (bl == NULL) {
		free(new);
		fprintf(stderr, "List_add error\n");
		if (err != NULL)
			*err = EINVARG;
		return;
	}
	
    if (bl->first == NULL) {
        bl->first = new; 
        bl->last = new;
    } 
	else {
        bl->last->next = new;
        new->prev = bl->last;
        bl->last = new;
    }
	
	*err = ESUCCESS;
};

void list_free(list** bl, LIST_ERR *err)
{
    if (bl == NULL) {
		fprintf(stderr, "Invalid argument: list\n");
		if (err != NULL)
			*err = EINVARG;
		return;
	}
	
    node* c = (*bl)->first;
    while (c != NULL) {
        node* t = c->next;
        free(c);
        c = t;
    };
    free(*bl);
    *bl = NULL;
	*err = ESUCCESS;
};

void list_insert(list* bl, node* n, void* data, LIST_ERR *err)
{
	node* new = node_init(data, err);
	
	if (bl == NULL) {
		free(new);
		fprintf(stderr, "List_insert error\n");
		if (err != NULL)
			*err = EINVARG;
		return;
	}
	
    if (n->next == NULL) {
		free(new);
        list_add(bl, data, err);
    } 
	else {
		node* t = n->next;
		t->prev = new;
		n->next = new;
        new->next = t;
        new->prev = n;
    };
	*err = ESUCCESS;
};

void list_remove(list* bl, node* n, LIST_ERR *err)
{	
    if (bl->first == NULL) {
		fprintf(stderr, "List_remove error\n");
		if (err != NULL)
			*err = EEMPTY;
		return;
	}
	
    if (n == bl->first && n == bl->last) {
        bl->first = NULL;
        bl->last = NULL;
    }
    else if(n == bl->first) {
        (n->next)->prev = NULL;
        bl->first = n->next;
    } 
    else if(n != bl->first && n != bl->last) {
        (n->prev)->next = n->next;
        (n->next)->prev = n->prev;
    }
	else if(n == bl->last) {
        (n->prev)->next = n->next;
        bl->last = n->prev;
    }
    free(n);
	*err = ESUCCESS;
};

node* list_find(list* bl, void* target, int (*cmp)(void *a,void *b), LIST_ERR *err) {
	
	if (bl == NULL) {
		fprintf(stderr, "List_find error\n");
		if (err != NULL)
			*err = EINVARG;
		return NULL;
	}
	
    node* n = bl->first;
    while (n != NULL) {
        if (cmp(n->data, target) == 0) {
			*err = ESUCCESS;
            return n;
        }
        n = n->next;
    }
	*err = ESUCCESS;
    return NULL;
}