#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int freq;
	char c;
	struct Node * left;
	struct Node * right;
};


int count=0;
struct Node * heap[1000];



void bottomHeapify()
{
	int i=count-1;
	int p=(i-1)/2;
	while (i>=0 && heap[i]->freq<heap[p]->freq)
	{
		int temp=heap[i]->freq;
		heap[i]->freq=heap[p]->freq;
		heap[p]->freq=temp;
		
		char c_temp=heap[i]->c;
		heap[i]->c=heap[p]->c;
		heap[p]->c=temp;
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
		if(heap[l]->freq<heap[r]->freq)
		{
			minIndex=l;
		}
		else minIndex=r;
		if(heap[i]->freq>heap[minIndex]->freq)
		{
			int t=heap[i]->freq;
			heap[i]->freq=heap[minIndex]->freq;
			heap[minIndex]->freq=t;
			char c_temp=heap[i]->c;
			heap[i]->c=heap[minIndex]->c;
			heap[minIndex]->c=c_temp;
			i=minIndex;
			l=2*i+1;
			r=2*i+2;
		}
		else break;
	}
	if(l==count-1 && heap[l]->freq<heap[i]->freq)
	{
		int t=heap[l]->freq;
		heap[l]->freq=heap[i]->freq;
		heap[i]->freq=t;
		char c_temp=heap[l]->c;
		heap[l]->c=heap[i]->c;
		heap[i]->c=c_temp;
	}
}

void insert(struct Node * temp)
{
	heap[count++]=temp;
	bottomHeapify();
}

struct Node * deleteMin()
{
	struct Node * temp=heap[0];
	heap[0]=heap[--count];
	topDownHeapify(0);
	return temp;
}


void buildHuffmanTree()
{
	struct Node * min1=deleteMin();
	struct Node * min2=deleteMin();
	struct Node * t=(struct Node *)malloc(sizeof(struct Node));
	t->freq=min1->freq+min2->freq;
	t->c=126;
	if (min1->freq < min2->freq)
	{
		t->left=min1;
		t->right=min2;
	}
	else
	{
		t->left=min2;
		t->right=min1;
	}
	insert(t);	
}


int main()
{
	
	int ch,num;
	char c;
	while(1)
	{
		printf("1. Add node\n");
		printf("2. Build Huffman Tree\n");
		printf("3. Print heap\n");
		printf("15. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter a number:");
			scanf("%d",&num);
			printf("Enter alphabet:");
			scanf(" %c",&c);
			struct Node * temp=(struct Node *)malloc(sizeof(struct Node));
			temp->freq=num;
			temp->c=c;
			temp->left=NULL;
			temp->right=NULL;
			insert(temp);
		}
		else if(ch==2)
		{
			buildHuffmanTree();
		}
		else if (ch==3)
		{
			for (int i=0;i<count;i++)
			{
				printf("%d	%c\n",heap[i]->freq,heap[i]->c);
			}
		}
		else if (ch==15)
		{
			break;
		}
	}
	printf("%d\t%d\n",heap[0]->left->freq,heap[0]->right->freq);
	return 0;
}