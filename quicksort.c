#include<stdio.h>
int main()
{
	int a[4],i;
	for(i=0;i<4;i++)
	{
		scanf("%d",&a[i]);		
	}
	quicksort(a,0,3);
	return 0;
}