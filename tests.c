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

	return 0;
}