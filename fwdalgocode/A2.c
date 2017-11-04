/*
	Name:a0,a1,a2.............an-1 Find maximum sum of sub-array of given length l 
	Copyright: 
	Author: Hemant PAndey
	Date: 04/09/16 13:38
	Description: most efficien approach in O(n)
	Problem:Maximum Sum of Sub-Array of length exactly 'l'
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arrsize 10
int main()
{
	int a[arrsize]={2,-3,1,-4,-6,-1,7,8,-11,9},i,j,l,max=0;
	l=3;
	int sum=0;
	for(j=0;j<l;j++){
		sum+=a[j];
	}
	max=sum;
	for(j=l;j<arrsize;j++){
		sum=sum-a[j-l]+a[j];
		if(sum>max)
			max=sum;
	}
	printf("%d",max);
	return 0;
}
