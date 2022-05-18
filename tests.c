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
	return 0;
}