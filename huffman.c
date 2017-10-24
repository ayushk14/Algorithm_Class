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
	struct Node *temp;
	while (i>=0 && heap[i]->freq<heap[p]->freq)
	{
		temp=heap[i];
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
	struct Node *temp;
	while(r<count)
	{
		if(heap[l]->freq<heap[r]->freq)
		{
			minIndex=l;
		}
		else minIndex=r;
		if(heap[i]->freq>heap[minIndex]->freq)
		{
			temp=heap[i];
			heap[i]=heap[minIndex];
			heap[minIndex]=temp;
			i=minIndex;
			l=2*i+1;
			r=2*i+2;
		}
		else break;
	}
	if(l==count-1 && heap[l]->freq<heap[i]->freq)
	{
		temp=heap[l];
		heap[l]=heap[i];
		heap[i]=temp;
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

void traverse(struct Node *t)
{
	if(t==NULL) return;
	printf("%d %c\n",t->freq,t->c);
	traverse(t->left);
	traverse(t->right);
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
			int i=0;
			int t=count-1;
			while(i<t)
			{
				buildHuffmanTree();
				i++;
			}
			traverse(heap[0]);
		}
		else if (ch==3)
		{
			int i;
			for (i=0;i<count;i++)
			{
				printf("%d	%c\n",heap[i]->freq,heap[i]->c);
			}
		}
		else if (ch==15)
		{
			break;
		}
	}
	return 0;
}
