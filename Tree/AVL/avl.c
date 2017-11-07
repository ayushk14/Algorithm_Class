#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int number;
	struct Node *left,*right,*parent;
	int position;
};

struct Node *start=NULL;


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

void balanceTree(struct Node *t,int num)
{
	struct Node *p,*o;
	o=t->parent;
	if(t!=NULL)
	{
		char *c=findRotationType(t,num);
		if(strcmp("000",c)==0 || strcmp("100",c)==0)
		{
			p=t->left;
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
			t->left=p->right;
			p->position=t->position;
			p->right=t;
			t->position=1;
			p->parent=t->parent;
			t->parent=p;
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
			p=t->right;
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
			t->right=p->left;
			p->position=t->position;
			p->left=t;
			t->position=0;
			p->parent=t->parent;
			t->parent=p;
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
			struct Node *q;
			p=t->right;
			q=p->left;
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
		else if(strcmp("001",c)==0 || strcmp("101",c)==0)
		{
			struct Node *q;
			p=t->left;
			q=p->right;
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



void addNode(int num)
{
	struct Node *t,*j;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->number=num;
	t->left=NULL;
	t->right=NULL;
	t->parent=NULL;
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
				struct Node *temp=findVictim(t);
				if(temp!=NULL)
				balanceTree(temp,num);
				return;
			}
			else
			{
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
				struct Node *temp=findVictim(t);
				if(temp!=NULL)
				balanceTree(temp,num);
				return;
			}
			else
			{
				j=j->right;
			}
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
	if (temp->left!=NULL)
	{
		temp->left->parent=temp->parent;
	}
	//printf("after temp->left!=null\n");
	if (temp->parent!=t)
	{
		temp->parent->right=temp->left;
		j=temp->parent;
		temp->left=t->left;
		//	printf("temp->left.........=%d\n",temp->left->number);
		temp->left->parent=temp;
		//	printf("temp->left->parent.............=%d\n",temp->left->parent->number);	
	}
	else
	{
		j=temp;
		//	printf("value of j %d\n",j->number);
	}
	//printf("after temp->right!=t\n");
	temp->parent=t->parent;
	//printf("after temp->parent=........%d\n",temp->parent->number);
	if (t->position==0)
	{
		t->parent->left=temp;
	}
	else
	{
		t->parent->right=temp;
		//	printf("inside t->position else.....and t->parent->right=%d\n",t->parent->right->number);
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
	}
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
	printf("%d\n",t->number);
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


int main()
{
	int ch,num,height,count;
	while(1)
	{
		printf("1.Add node\n");
		printf("2.Remove node\n");
		printf("3.Pre-Order traverse\n");
		printf("4.In-Order traverse\n");
		printf("5.Post-Order traverse\n");
		printf("6. Find height\n");
		printf("7.Exit\n");
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
			break;
		}
	}
	return 0;
}