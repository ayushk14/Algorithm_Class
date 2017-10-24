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

int isLeaf(struct Node *t)
{
	if(t->left==NULL && t->right==NULL) return 1;
	else return 0;
}

int *alphabetCode[26];
int g=0;
void copyCode(int code[],int size)
{
	alphabetCode[g]=(int *)malloc(sizeof(int)*(size+1));
	int i=1,t=0;
	alphabetCode[g][0]=size;
	size++;
	while(i<size)
	{
		alphabetCode[g][i]=code[t];
		t++;
		i++;
	}
	g++;
}

void findCode(struct Node *t,int code[],int size)
{
	if(t->left==NULL && t->right==NULL)
	{
		copyCode(code,size);
		return;
	}
	if(t->left)
	{
		code[size]=0;
		findCode(t->left,code,size+1);
	}
	if(t->right)
	{
		code[size]=1;
		findCode(t->right,code,size+1);
	}
}

int main()
{
	
	int ch,num;
	char c;
	struct Node **inputData=(struct Node **)malloc(sizeof(struct Node *)*26);
	int inputDataCount=0;
	while(1)
	{
		printf("1. Add node\n");
		printf("2. Build Huffman Tree\n");
		printf("3. Print heap\n");
		printf("4. Print codes\n");
		printf("5. Compute final length of file\n");
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
			inputDataCount=count;
			while(i<count)
			{
				inputData[i]=heap[i];
				i++;
			}
			i=0;
			while(i<t)
			{
				buildHuffmanTree();
				i++;
			}
			traverse(heap[0]);
			int *code=(int *)malloc(sizeof(int)*10000);
			int top=0;
			findCode(heap[0],code,top);
		}
		else if (ch==3)
		{
			int i;
			for (i=0;i<count;i++)
			{
				printf("%d	%c\n",heap[i]->freq,heap[i]->c);
			}
		}
		else if(ch==4)
		{
			int i=0;
			int j=0;
			while(i<g)
			{
				j=alphabetCode[i][0];
				j++;
				int temp=1;
				printf("%c ",inputData[i]->c);
				while(temp<j)
				{
					printf("%d",alphabetCode[i][temp]);
					temp++;
				}
				printf("\n");
				i++;
			}
		}
		else if(ch==5)
		{
			int i=0,j=0;
			int sum=0;
			while(i<inputDataCount)
			{
				sum=sum+inputData[i]->freq*alphabetCode[i][0];
				i++;
			}
			printf("Compressed data length : %d\n",sum);
		}
		else if (ch==15)
		{
			break;
		}
	}
	return 0;
}
