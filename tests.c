#include "list.h"
#define N 10

int main()
{
	list *list = NULL;
	LIST_ERR err;
	int *a = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        a[i] = i;
	}
	int b = 5;
	
	list = list_init(&err);
	if (list == NULL)
		fprintf(stdout, "Test_1\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_1\t->\tPASSED\n");
	
	for (int i = 0; i < 2; i++) {
        list_add(NULL, &a[i], &err);
		if (err != EINVARG)
			fprintf(stdout, "Test_2\t->\tFAILED\n");
		else
			fprintf(stdout, "Test_2\t->\tPASSED\n");
	}
	
	list_insert(NULL, NULL, &a[N-2], &err);
	if (err != EINVARG)
		fprintf(stdout, "Test_3\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_3\t->\tPASSED\n");
		
	list_free(NULL, &err);
	if (err != EINVARG)
		fprintf(stdout, "Test_4\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_4\t->\tPASSED\n");
	
	list_remove(list, list->first, &err);
	if (err != EEMPTY)
		fprintf(stdout, "Test_5\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_5\t->\tPASSED\n");
	
	node* n = node_init(&b, &err);
	list_insert(list, n, &b, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_6\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_6\t->\tPASSED\n");
	
	list_remove(list, list->last, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_7\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_7\t->\tPASSED\n");
	
	list_add(list, &b, &err);
	list_remove(list, list->first, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_8\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_8\t->\tPASSED\n");
	
	for (int i = 0; i < N; i++) {
        list_add(list, &a[i], &err);
		if (err != ESUCCESS)
			fprintf(stdout, "Test_9\t->\tFAILED\n");
		else
			fprintf(stdout, "Test_9\t->\tPASSED\n");
	}
	
	list_insert(list, list->first, &a[N-1], &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_10\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_10\t->\tPASSED\n");
	
	list_insert(list, list->first->next, &a[N-2], &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_11\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_11\t->\tPASSED\n");
	
	list_remove(list, list->first, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_12\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_12\t->\tPASSED\n");

	list_remove(list, list->last, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_13\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_13\t->\tPASSED\n");
	
	list_remove(list, list->first->next, &err);
	if (err != ESUCCESS)
		fprintf(stdout, "Test_14\t->\tFAILED\n");
	else
		fprintf(stdout, "Test_14\t->\tPASSED\n");
	return 0;
}