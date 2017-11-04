/*
	Name:a0,a1,a2.............an-1 Find maximum sum of sub-array of length atleast  l 
	Copyright: 
	Author: Hemant PAndey
	Date: 04/09/16 13:46
	Description: most efficien approach in O(n)
	Problem:Maximum Sum of Sub-Array of length atleast 'l'
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arrsize 10
int main()
{
	int a[arrsize]={2,-3,2,-4,-6,-1,7,8,-11,9},i,j,l,max=0;
	l=3;
	int sum=0,sum_l=0;
	for(j=0;j<arrsize;j++){
		if(j<l){
			sum+=a[j];
			sum_l=sum_l+a[j];
			max=sum;
		}
		else{
			sum+=a[j];
			sum_l+=a[j]-a[j-l];						 
			if(sum<sum_l)
				sum=sum_l;
			if(sum>max)
				max=sum;
			//printf("%d %d\n",sum,sum_l);
		}		
		
	}
	printf("%d",max);
	return 0;
}
