#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int number;
	struct Node *left,*right,*parent;
	int position;
};

struct Node *start=NULL;


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
			return;
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
	return;
}


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
  int ch,num;
  while(1)
	{
		printf("1.Add node\n");
		printf("2.Remove node\n");
		printf("3.Pre-Order traverse\n");
		printf("4.In-Order traverse\n");
		printf("5.Post-Order traverse\n");
		printf("6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter a number:");
			scanf("%d",&num);
			addNode(num);
		}
		else if(ch==2)
		{
			printf("Enter a number you want to remove from tree:");
			scanf("%d",&num);
			removeNode(num);
		}
		else if(ch==3)
		{
			preOrder(start);
		}
		else if(ch==4)
		{
			inOrder(start);
		}
		else if(ch==5)
		{
			postOrder(start);
		}
		else if(ch==6)
		{
			break;
		}
	}
  return 0;
}
