/*
	Name: 
	Copyright: a0,a1,a2.....................an-1 Find min.length of sub-array whose sum is S
	Author: Hemant PAndey
	Date: 04/09/16 15:08
	Description: 1-using a var sum and min find sum contineously if sum exceed to S then move var i
					from lhs such that sum is still greater than S but it will take O(n^2) in worstcase
				2-using an efficient approach within O(2n) 
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define arrsize 10
int main()
{
	int a[arrsize]={2,-3,1,-4,-6,-1,7,8,-11,19},i,j,l,max=0;
	int sum=0;
	int length=arrsize,S;
	S=10;
	i=0;
	for(j=0;j<arrsize;j++){
		sum+=a[j];
		if(sum<0){
			sum=0;
			i=j+1;
			continue;
		}
		if(sum>S){
			while(sum>S){
				sum-=a[i];
				i++;
			}
			if(j-(i-1)+1<length)
				length=j-(i-1)+1;
			sum=0;
			i=j;
		}		
	}
	printf("Minimum Length of Sub-array :%d",length);
	return 0;
}
