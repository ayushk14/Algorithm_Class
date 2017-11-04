/*
	Name:a0,a1,a2.............an-1 Find maximum sum of sub-array of length atmost  l 
	Copyright: 
	Author: Hemant PAndey
	Date: 04/09/16 13:59
	Description: most efficien approach in O(n)
	Problem:Maximum Sum of Sub-Array of length atmost 'l'
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arrsize 10
int main()
{
	int a[arrsize]={2,-3,2,-4,-6,-1,7,8,-11,29},i,j,l,max=0;
	l=3;
	int sum=0,sum1=0;
	for(j=0;j<l;j++){
		sum+=a[j];
		if(sum>max)
			max=sum;
	}
	i=l;
	for(j=l;j<arrsize;j++){		
		if(a[j]>0)
			sum+=a[j]-a[j-l];
		else
			sum=0;
		if(sum>max)
			max=sum;	
	}
	printf("%d",max);
	return 0;
}
