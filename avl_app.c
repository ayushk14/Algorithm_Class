#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int number;
	struct Node *left,*right,*parent;
	int position;
	int count;
	int sum;
	int min;
	int max;
	int minGap;
};
void preOrder(struct Node *);
struct Node *start=NULL;

int countNumberOfNodes(struct Node *t)
{
	if(t==NULL) return 0;
	return 1+countNumberOfNodes(t->left)+countNumberOfNodes(t->right);
}

int findSum(struct Node *t)
{
	if(t==NULL) return 0;
	return t->number+findSum(t->left)+findSum(t->right);
}

int findHeight(struct Node *t)
{
	if(t==NULL) 
		return 0;
	if(t->left==NULL && t->right==NULL) 
		return 0;
	int lh=0,rh=0;
	lh=findHeight(t->left);
	rh=findHeight(t->right);
	if(lh>rh) 
		return lh+1;
	else 
		return rh+1;
}

char * findRotationType(struct Node * victim, int num)
{
	char *rotationString=(char *)malloc(sizeof(char)*3);
	struct Node *t=victim;
	int i=0;
	while(i<3)
	{
		if(t->number > num)
		{
			if(t->position==-1)
				rotationString[i]=0+48;
			else
				rotationString[i]=(char)t->position+48;
			t=t->left;
		}
		else
		{
			if(t->position==-1)
				rotationString[i]=0+48;
			else
				rotationString[i]=(char)t->position+48;
			t=t->right;
		}
		i++;
	}
	return rotationString;
}

struct Node * findVictim(struct Node *t)
{
	int lh,rh,difference;
	while(t!=NULL)
	{
		if(t->left==NULL) 
			lh=-1;
		else 
			lh=findHeight(t->left);
		if(t->right==NULL) 
			rh=-1;
		else 
			rh=findHeight(t->right);
		difference=abs(lh-rh);
		if(difference>=-1 && difference<=1)
		{
			t=t->parent;
		}
		else 
			break;
	}//while ends
	return t;
}

int findFeasibleNumber(struct Node *t)
{
	int lh,rh,lh1,rh1;
	lh=findHeight(t->left);
	rh=findHeight(t->right);
	struct Node *temp;
	if(lh>=rh)
	{
		temp=t->left;
		lh1=findHeight(temp->left);
		rh1=findHeight(temp->right);
		if(lh1>=rh1)
		{
			return temp->left->number;
		}
		else
		{
			return temp->right->number;
		}
	}
	else
	{
		temp=t->right;
		//printf("temp->number %d\n",temp->right->number);
		lh1=findHeight(temp->left);
		rh1=findHeight(temp->right);
		if(lh1>rh1)
		{
			return temp->left->number;
		}
		else
		{
			return temp->right->number;
		}
	}
}

void updateMinGap(struct Node *t,struct Node *parent)
{
	if(parent==NULL) return;
	int gap[4],min,i;
	for(i=0;i<4;i++) gap[i]=-1;
	i=0;
	if(t->position==0)
	{
		gap[i]=t->minGap;
	}
	i++;
	if(t->position==1)
	{
		gap[i]=t->minGap;
	}
	i++;
	if(parent->left!=NULL)
	{
		gap[i]=abs(parent->number-parent->left->max);
	}
	i++;
	if(parent->right!=NULL)
	{
		gap[i]=abs(parent->right->min-parent->number);
	}
	min=98765;
	for(i=0;i<4;i++)
	{
		if(gap[i]!=-1 && min>gap[i])
		{
			min=gap[i];
		}
	//	printf("Gap %d----> min %d\n",gap[i],min);
	}
	parent->minGap=min;
	updateMinGap(parent,parent->parent);
}

void balanceTree(struct Node *t,int num)
{
	struct Node *p,*o;
	o=t->parent;
	if(t!=NULL)
	{
		char *c=findRotationType(t,num);
		if(strcmp("000",c)==0 || strcmp("100",c)==0)
		{
			printf("000 || 100\n");
			int z=0;
			p=t->left;
			if(p->right==NULL)
			{
				t->minGap=-1;
			}
			else 	z=1;
			if(t->parent!=NULL)
			{
				if (t->position==0)
					t->parent->left=p;
				else
					t->parent->right=p;
			}
			if(t==start)
			{
				start=p;
			}
			p->max=t->max;
			if(p->right!=NULL)
			{
				t->min=p->right->min;
				t->max=t->number;
			}
			else
			{
				t->min=t->number;
				t->max=t->number;
			}
			t->left=p->right;
			p->position=t->position;
			p->right=t;
			t->position=1;
			p->parent=t->parent;
			t->parent=p;
			t->count=countNumberOfNodes(t);
			p->count=countNumberOfNodes(p);
			t->sum=findSum(t);
			p->sum=findSum(p);
			if(z==0) 
			{ 
				updateMinGap(t,p);
			}
			else 
			{
				updateMinGap(t->left,t);
			}
			if(o!=NULL)
			{
				struct Node *yy=findVictim(o);
				if(yy!=NULL )
				{
					int x=findFeasibleNumber(yy);
					balanceTree(yy,x);
				}
			}
			//balanceTree(j,num);
		}
		else if(strcmp("111",c)==0 || strcmp("011",c)==0) 
		{
			printf("111 || 011\n");
			int z=0;
			p=t->right;
			if(p->left==NULL)
			{
				t->minGap=-1;
			}
			else z=1;
			if(t->parent!=NULL)
			{
				if (t->position==1)
					t->parent->right=p;
				else
					t->parent->left=p;
			}
			if(t==start)
			{
				start=p;
			}
			p->min=t->min;
			if(p->left!=NULL)
			{
			t->min=t->number;
			t->max=p->left->max;
			}
			else
			{
				t->min=t->number;
				t->max=t->number;
			}
			t->right=p->left;
			p->position=t->position;
			p->left=t;
			t->position=0;
			p->parent=t->parent;
			t->parent=p;
			t->count=countNumberOfNodes(t);
			p->count=countNumberOfNodes(p);
			t->sum=findSum(t);
			p->sum=findSum(p);
			if(z==0) updateMinGap(t,p);
			else updateMinGap(t->right,t);
			if(o!=NULL)
			{
				struct Node *yy=findVictim(o);
				if(yy!=NULL )
				{
					int x=findFeasibleNumber(yy);
					balanceTree(yy,x);
				}
			}
			//balanceTree(j,num);
		}
		else if(strcmp("010",c)==0 || strcmp("110",c)==0)
		{
			printf("010 || 110\n");
			int x=0,y=0;
			struct Node *q;
			p=t->right;
			q=p->left;
			if(q->left!=NULL) x=1;
			if(q->right!=NULL) y=1;
			if(t->left==NULL) t->minGap=-1;
			if(p->right==NULL) p->minGap=-1;
			if(t->position==0)
			{
				if(t->parent!=NULL)
					t->parent->left=q;
			}
			else
			{
				if(t->parent!=NULL)
					t->parent->right=q;
			}
			if(t==start)
			{
				start=q;
			}
			
			q->min=t->min;
			q->max=p->max;
			if(q->left!=NULL)
			{
				//t->min=t->number;
				t->max=q->left->max;
			}
			else
			{
				//t->min=t->number;
				t->max=t->number;
			}
			if(q->right!=NULL)
			{
				p->min=q->right->min;
				//p->max=p->number;
			}
			else
			{
				p->min=p->number;
				//p->max=p->number;
			}
			
			
			q->position=t->position;
			q->parent=t->parent;
			t->right=q->left;
			p->left=q->right;
			q->left=t;
			t->parent=q;
			t->position=0;
			q->right=p;
			p->parent=q;
			p->position=1;
			t->count=countNumberOfNodes(t);
			p->count=countNumberOfNodes(p);
			q->count=countNumberOfNodes(q);
			t->sum=findSum(t);
			p->sum=findSum(p);
			q->sum=findSum(q);

			if(x==0) updateMinGap(t,q);
			else updateMinGap(t->right,t);
			if(y==0) updateMinGap(p,q);
			else updateMinGap(p->left,p);

			if(o!=NULL)
			{
				struct Node *yy=findVictim(o);
				if(yy!=NULL )
				{
					printf("Second time start\n");
					int x=findFeasibleNumber(yy);
					balanceTree(yy,x);
				}
			}
		}
		else if(strcmp("001",c)==0 || strcmp("101",c)==0)
		{
			printf("001 || 101\n");
			int x=0,y=0;
			struct Node *q;
			p=t->left;
			q=p->right;

			if(q->left!=NULL) x=1;
			if(q->right!=NULL) y=1;
			if(p->left==NULL) p->minGap=-1;
			if(t->right==NULL) t->minGap=-1;
			if(t->position==0)
			{
				if(t->parent!=NULL)
					t->parent->left=q;
			}
			else
			{
				if(t->parent!=NULL)
					t->parent->right=q;
			}
			if(t==start)
			{
				start=q;
			}
			q->min=p->min;
			q->max=t->max;
			if(q->left!=NULL)
			{
				//p->min=p->number;
				p->max=q->left->max;
			}
			else
			{
				//p->min=p->number;
				p->max=p->number;
			}
			if(q->right!=NULL)
			{
				t->min=q->right->min;
				//t->max=t->number;
			}
			else
			{
				t->min=t->number;
				//t->max=t->number;
			}
			
			q->position=t->position;
			q->parent=t->parent;
			t->left=q->right;
			p->right=q->left;
			q->left=p;
			p->parent=q;
			p->position=0;
			q->right=t;
			t->parent=q;
			t->position=1;
			t->count=countNumberOfNodes(t);
			p->count=countNumberOfNodes(p);
			q->count=countNumberOfNodes(q);
			t->sum=findSum(t);
			p->sum=findSum(p);
			q->sum=findSum(q);

			if(x==0) updateMinGap(p,q);
			else updateMinGap(p->right,p);
			if(y==0) updateMinGap(t,q);
			else updateMinGap(t->left,t);

			if(o!=NULL)
			{
				struct Node *yy=findVictim(o);
				if(yy!=NULL )
				{
					int x=findFeasibleNumber(yy);
					balanceTree(yy,x);
				}
			}
		}
	}
	else
	{
		return;
	}
}

int nodeRank(int x,struct Node *t)
{
	int rank=1;
	if(t==NULL) return -1;
	while(t)
	{
		if (t->number==x)
		{
			int temp;
			if (t->right!=NULL)
				temp=t->right->count;
			else
				temp=0;
			rank=rank+temp;
			return rank;
		}
		if(t->number<x)
			t=t->right;
		else
		{
			int temp;
			if (t->right!=NULL)
				temp=t->right->count;
			else
				temp=0;
			rank=rank+temp+1;
			t=t->left;
		}
	}	
	return rank;
}

int findRank(int x,struct Node *t)
{
	while(t)
	{
		int temp;
		if (t->right!=NULL)
			temp=t->right->count;
		else
			temp=0;
		int r=temp;
		if (r+1==x)
			return t->number;
		if (r+1<x)
		{
			x=x-(r+1);
			t=t->left;
		}
		else
			t=t->right;
	}
	return -1;
}

int numberOfElementsBetweenTwoNumbers(int x,int y,int hasIncludedX,int hasIncludedY)
{
	int xRank,yRank,difference;
	xRank=nodeRank(x,start);
	yRank=nodeRank(y,start);
	difference=abs(xRank-yRank-1);
	if(hasIncludedX)
	{
		struct Node *t=start;
		while(t)
		{
			if(t->number == x)
			{
				break;
			}
			else if(t->number>x)
			{
				t=t->left;
			}
			else
			{
				t=t->right;
			}
		}
		if(t!=NULL) difference+=1; 
	}
	if(hasIncludedY)
	{
		struct Node *t=start;
		while(t)
		{
			if(t->number == x)
			{
				break;
			}
			else if(t->number>x)
			{
				t=t->left;
			}
			else
			{
				t=t->right;
			}
		}
		if(t!=NULL) difference+=1; 
	}
	if(xRank==yRank) return 0;
	return difference;
}

int findPrefixSum(int x)
{
	int s=0;
	struct Node * t=start;
	while (t)
	{
		if (t->number==x)
		{
			int temp;
			if (t->left!=NULL)
				temp=t->left->sum;
			else
				temp=0;
			return s+temp+t->number;
		}
		else if (t->number < x)
		{
			int temp;
			if (t->left!=NULL)
				temp=t->left->sum;
			else
				temp=0;
			s=s+temp+t->number;
			t=t->right;
		}
		else
		{
			t=t->left;
		}
	}
	return s;
}

int computeSumBetweenTwoNumbers(int x,int y)
{
	int prefixSumOfX,prefixSumOfY;
	prefixSumOfX=findPrefixSum(x-1);
	prefixSumOfY=findPrefixSum(y);
	return abs(prefixSumOfY-prefixSumOfX);
}

float computeAverageBetweenTwoNumbers(x,y)
{
	int sum=computeSumBetweenTwoNumbers(x,y);
	int numberOfNodes=numberOfElementsBetweenTwoNumbers(x,y,1,1);
	return sum/numberOfNodes;
}

void addNode(int num)
{
	struct Node *t,*j;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->number=num;
	t->left=NULL;
	t->right=NULL;
	t->parent=NULL;
	t->count=1;
	t->sum=t->number;
	t->min=num;
	t->max=num;
	t->minGap=-1;
	if(start==NULL)
	{
		start=t;
		t->parent=NULL;
		t->position=-1;
		return;
	}
	j=start;
	while(1)
	{
		if(t->number<j->number)
		{
			if(j->left==NULL)
			{
				j->left=t;
				t->parent=j;
				t->position=0;
				j->count++;
				j->sum=j->sum+t->number;
				if(j->min>num)
				{
					j->min=num;
				}
				if(j->max<num)
				{
					j->max=num;
				}
				updateMinGap(t,j);
				struct Node *temp=findVictim(t);
				if(temp!=NULL)
				balanceTree(temp,num);
				return;
			}
			else
			{
				j->count++;
				j->sum+=t->number;
				if(j->min>num)
				{
					j->min=num;
				}
				if(j->max<num)
				{
					j->max=num;
				}
				j=j->left;
			}
		}
		else
		{
			if(j->right==NULL)
			{
				j->right=t;
				t->parent=j;
				t->position=1;
				j->count++;
				j->sum+=t->number;
				if(j->min>num)
				{
					j->min=num;
				}
				if(j->max<num)
				{
					j->max=num;
				}
				updateMinGap(t,j);
				struct Node *temp=findVictim(t);
				if(temp!=NULL)
				balanceTree(temp,num);
				return;
			}
			else
			{
				j->count++;
				j->sum+=t->number;
				if(j->min>num)
				{
					j->min=num;
				}
				if(j->max<num)
				{
					j->max=num;
				}
				j=j->right;
			}
		}
	}
}

void changeCount(struct Node *t)
{
	while(t)
	{
		t->count--;
		t=t->parent;
	}
}

void changeSum(struct Node *t,int num)
{
	while(t)
	{
		t->sum=t->sum-num;
		t=t->parent;
	}
}

void updateMinMax(struct Node *t,int position,int num)
{
	struct Node *j=t;
	if(position==0)
	{
		while(j)
		{
			j->min=num;
			j=j->parent;
		}
	}
	else
	{
		while(j)
		{
			j->max=num;
			j=j->parent;
		}
	}
}


void removeNode(int num)
{
	struct Node * t,*j;
	if(start==NULL)
	{
		printf("Node doesn't exits.");
		return;
	}
	t=start;
	while(t!=NULL)
	{
		if(t->number==num)
		{
			break;
		}
		else if(t->number>num)
		{
			t=t->left;
		}//else if ends
		else
		{
			t=t->right;
		}//else ends
	}//while ends
	if(t==NULL)
	{
		printf("Node doesn't exists.");
		return;
	}

	j=t->parent;
	if(t->left==NULL && t->right==NULL)
	{
		if(t==start)
		{
			start=NULL;
			free(t);
			return;
		}
		else
		{
			if(t->position==0)
			{
				j->left=NULL;
			}
			else
			{
				j->right=NULL;
			}
			changeCount(j);
			changeSum(j,t->number);
			if(t->position==0)
			{
				updateMinMax(j,0,j->number);
			}
			else
			{
				updateMinMax(j,1,j->number);
			}

			int temp1=j->minGap;
			if(t->position==0)
			{
				if(j->right!=NULL)
				{
					if(j->right->minGap!=-1 && temp1>j->right->minGap)	j->minGap=j->right->minGap;
					if(j->parent!=NULL) updateMinGap(j,j->parent);
				}
				else
				{
					j->minGap=-1;
					if(j->parent!=NULL) updateMinGap(j,j->parent);
				}
			}
			else
			{
				if(j->left!=NULL)
				{
					if(j->left->minGap && temp1>j->left->minGap)	j->minGap=j->left->minGap;
					if(j->parent!=NULL) updateMinGap(j,j->parent);
				}
				else
				{
					j->minGap=-1;
					if(j->parent!=NULL) updateMinGap(j,j->parent);
				}
			}

			free(t);
			struct Node *temp=findVictim(j);
	
			if(temp!=NULL)
			{
				int x=findFeasibleNumber(temp);
				balanceTree(temp,x);
				return;
			}
			else return;
		}
	}//both children are NULL

	if (t->right==NULL)
	{
		if (t==start)
		{
			start=t->left;
			start->parent=NULL;
			free(t);
			return;
		}
		else
		{
			if (t->position==0)
			{
				t->left->parent=t->parent;
				t->parent->left=t->left;
			}
			else
			{
				t->left->parent=t->parent;
				t->parent->right=t->left;
			}
			j=t->parent;
			changeCount(j);
			changeSum(j,t->number);
			if(t->position==0)
			{
				updateMinMax(j,0,t->min);
				updateMinGap(j->left,j);
			}
			else
			{
				updateMinMax(j,1,t->max);
				updateMinGap(j->right,j);
			}
			free(t);
			struct Node * temp=findVictim(j);
			if (temp!=NULL)
			{
				int x=findFeasibleNumber(temp);
				balanceTree(temp,x);
				return;
			}
			else
				return;
		}
	}

	if (t->left==NULL)
	{
		if (t==start)
		{
			start=t->right;
			start->parent=NULL;
			free(t);
			return;
		}
		else
		{
			if (t->position==0)
			{
				t->right->parent=t->parent;
				t->parent->left=t->right;
			}
			else
			{
				t->right->parent=t->parent;
				t->parent->right=t->right;
			}
			j=t->parent;
			changeCount(j);
			changeSum(j,t->number);
			if(t->position==0)
			{
				updateMinMax(j,0,t->min);
				updateMinGap(j->left,j);
			}
			else
			{
				updateMinMax(j,1,t->max);
				updateMinGap(j->right,j);
			}
			free(t);
			struct Node * temp=findVictim(j);
			if (temp!=NULL)
			{
				int x=findFeasibleNumber(temp);
				balanceTree(temp,x);
				return;
			}
			else
				return;
		}
	}

	struct Node * temp=t->left;
	//printf("temp before while =%d\n",temp->number);
	while (temp->right!=NULL)
	{
		temp=temp->right;
	}

	//printf("temp =%d\n",temp->number);
	//printf("after temp->left!=null\n");
	if (temp->parent!=t)
	{
		if(temp->left!=NULL)
		{
			temp->left->parent=temp->parent;
			temp->parent->max=temp->left->max;
		}
		else
		{
			temp->parent->max=temp->parent->number;
		}
		changeCount(temp->parent);
		changeSum(temp->parent,temp->number);
			//changeSum(temp->parent,temp->number);
		temp->parent->right=temp->left;
		j=temp->parent;
		temp->left=t->left;
//		printf("temp->left.........=%d\n",temp->left->number);
		temp->left->parent=temp;
//		printf("temp->left->parent.............=%d   sdfsdfsfdfjjjjj\n",temp->left->parent->number);
//		printf("Change sum chala....\n");
	}
	else
	{
		j=temp;
		changeCount(j->parent);
		changeSum(j->parent,t->number);
		//changeSum(j->parent,t->number);
	}
	//printf("upper wala printf\n");

//	printf("after temp->right!=t\n");
	temp->parent=t->parent;
	//printf("after temp->parent=........%d\n",temp->parent->number);
	if (t->position==0)
	{
		t->parent->left=temp;
	}
	else if(t->position ==1)
	{
		t->parent->right=temp;
//			printf("inside t->position else.....and t->parent->right=%d\n",t->parent->right->number);
	}
	temp->position=t->position;
	//printf("after temp->position...........=%d\n",temp->position);
	
	temp->right=t->right;
	//printf("temp->right.............=%d\n",temp->right->number);
	temp->right->parent=temp;
	//printf("temp->right->parent............=%d\n",temp->right->parent->number);
	if(t==start)
	{
		start=temp;
		temp->count=countNumberOfNodes(temp);
		temp->sum=findSum(temp);
	}
	
	j->count=countNumberOfNodes(j);
	j->sum=findSum(j);
	temp->count=t->count;
	if(j!=temp)
	{
		int l=t->number-temp->number;
		temp->sum=t->sum-l;
		struct Node * m=t->parent;
		while (m)
		{
			m->sum=m->sum-l;
			m=m->parent;
		}
	}
	//temp->sum=t->sum;
	//temp->sum=findSum(temp);
	temp->min=t->min;
	temp->max=t->max;

	if(temp->left!=NULL)
	{
		if(temp->left->minGap>temp->right->minGap) temp->minGap=temp->right->minGap;
		else temp->minGap=temp->left->minGap;		
	}
	else
		temp->minGap=temp->right->minGap;
	updateMinGap(j->right,j);
	free(t);
	//printf("after free t and j=%d\n",j->number);
	temp=findVictim(j);
	//printf("after find victim%d\n",temp->number);
	if (temp!=NULL)
	{
		//	printf("inside temp!=null if %d\n",temp->number);
		int x=findFeasibleNumber(temp);
		printf("Value of x %d\n",x);
		balanceTree(temp,x);
		//	printf("Something\n");
		return;
	}
	else
		return;
}//removeNode ends



void inOrder(struct Node *t)
{
	if(t==NULL) 
		return;
	inOrder(t->left);
	printf("%d\n",t->number);	
	inOrder(t->right);
}


void preOrder(struct Node *t)
{
	if(t==NULL) 
		return;
	printf("%d  %d\n",t->number,t->min);
	preOrder(t->left);
	preOrder(t->right);
}


void postOrder(struct Node *t)
{
	if(t==NULL) 
		return;
	postOrder(t->left);
	postOrder(t->right);
	printf("%d\n",t->number);
}

int findMaxGap(struct Node *t)
{
	return (t->max - t->min);
}

int findMinGap(struct Node *t)
{
	return (t->minGap);
}
int main()
{
	int ch,num,height,count;
	while(1)
	{
		/*printf("1. Add node\n");
		printf("2. Remove node\n");
		printf("3. Pre-Order traverse\n");
		printf("4. In-Order traverse\n");
		printf("5. Post-Order traverse\n");
		printf("6. Find height\n");
		printf("7. Node rank\n");
		printf("8. Find rank\n");
		printf("9. numberOfElementsBetweenTwoNumbers\n");
		printf("10. Find prefix sum\n");*/
		printf("11. Find sum of numbers between two numbers\n");
		printf("12. Find average of numbers between two numbers\n");
		printf("13. Find max gap\n");
		printf("14. Find min gap\n");
		printf("15. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter a number:");
			scanf("%d",&num);
			addNode(num);
		}
		if(ch==2)
		{
			printf("Enter a number you want to remove from tree:");
			scanf("%d",&num);
			removeNode(num);
		}
		if(ch==3)
		{
			preOrder(start);
		}
		if(ch==4)
		{
			inOrder(start);
		}
		if(ch==5)
		{
			postOrder(start);
		}
		if(ch==6)
		{
			printf("Height %d\n",findHeight(start));
		}
		if(ch==7)
		{
			printf("Enter a number you want to find the rank:");
			scanf("%d",&num);
			printf("%d\n",nodeRank(num,start));
		}
		if(ch==8)
		{
			printf("Enter a number you want to find the rank:");
			scanf("%d",&num);
			printf("%d\n",findRank(num,start));
		}
		if(ch==9)
		{
			int x,y,hasIncludedX,hasIncludedY;
			printf("Enter first number :");
			scanf("%d",&x);
			printf("Do you want to include this number (0/1):");
			scanf("%d",&hasIncludedX);
			printf("Enter second number :");
			scanf("%d",&y);
			printf("Do you want to include this number (0/1):");
			scanf("%d",&hasIncludedY);
			printf("%d\n",numberOfElementsBetweenTwoNumbers(x,y,hasIncludedX,hasIncludedY));
		}
		if(ch==10)
		{
			printf("Enter a number:");
			scanf("%d",&num);
			printf("%d\n",findPrefixSum(num));
		}
		if(ch==11)
		{
			int x,y;
			printf("Enter first number :");
			scanf("%d",&x);
			printf("Enter second number :");
			scanf("%d",&y);
			printf("%d\n",computeSumBetweenTwoNumbers(x,y));
		}
		if(ch==12)
		{
			int x,y;
			printf("Enter first number :");
			scanf("%d",&x);
			printf("Enter second number :");
			scanf("%d",&y);
			printf("%f\n",computeAverageBetweenTwoNumbers(x,y));			
		}
		if(ch==13)
		{
			printf("Max gap of the tree :%d\n",findMaxGap(start));
		}
		if(ch==14)
		{
			printf("Min gap of the tree :%d\n",findMinGap(start));
		}
		if(ch==15)
		{
			break;
		}
	}
	return 0;
}
