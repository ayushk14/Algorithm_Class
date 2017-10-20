#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *i=(int *)malloc(sizeof(int));
	*i=8;
	printf("%d\n",*i);
	i=NULL;
	printf("%d\n",*i);		// Line 1
	return 0;
}
