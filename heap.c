#include<stdio.h>
#include<stdlib.h>

int count=0;
int heap[1000];



void bottomHeapify()
{
	int i=count-1;
	int p=(i-1)/2;
	while (i>=0 && heap[i]<heap[p])
	{
		int temp=heap[i];
		heap[i]=heap[p];
		heap[p]=temp;
		i=p;
		p=(i-1)/2;
	}
}

void topDownHeapify(int i)
{
	int l,r,minIndex;
	l=2*i+1;
	r=2*i+2;
	while(r<count)
	{
		if(heap[l]<heap[r])
		{
			minIndex=l;
		}
		else minIndex=r;
		if(heap[i]>heap[minIndex])
		{
			int t=heap[i];
			heap[i]=heap[minIndex];
			heap[minIndex]=t;
			i=minIndex;
			l=2*i+1;
			r=2*i+2;
		}
		else break;
	}
	if(l==count-1 && heap[l]<heap[i])
	{
		int t=heap[l];
		heap[l]=heap[i];
		heap[i]=t;
	}
}

void insert(int num)
{
	heap[count++]=num;
	bottomHeapify();
}

int deleteMin()
{
	int num=heap[0];
	heap[0]=heap[--count];
	topDownHeapify(0);
	return num;
}

int main()
{
	int ch,num,height;
	while(1)
	{
		printf("1. Add node\n");
		printf("2. Remove node\n");
		printf("3. Print heap\n");
		printf("15. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter a number:");
			scanf("%d",&num);
			insert(num);
		}
		else if(ch==2)
		{
			printf("Deleted :%d\n",deleteMin());
		}
		else if (ch==3)
		{
			for (int i=0;i<count;i++)
			{
				printf("%d\n",heap[i]);
			}
		}
		else if (ch==15)
		{
			break;
		}
	}
	return 0;
}