#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int number;
	struct Node *left,*right,*parent;
	int position;
	int isred;
};

struct Node *start=NULL;

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

void doubleRed(struct Node * t)
{
	struct Node *g,*u,*p;
	p=t->parent;
	g=p->parent;
	if (p->position==0)
		u=g->right;
	else
		u=g->left;
	
	
	//CASE 1...............
	if (u!=NULL && u->isred==1)
	{
		g->isred=1;
		p->isred=0;
		u->isred=0;
		if (g!=start && g->isred==1)
		{
			doubleRed(g);
		}
		else if (g==start)
		{
			g->isred=0;
			return;
		}
	}
	else //CASE 2.............
	{
		char *c=findRotationType(g,t->number);
		if(strcmp("000",c)==0 || strcmp("100",c)==0)
		{
			if(g->parent!=NULL)
			{
				if (g->position==0)
					g->parent->left=p;
				else
					g->parent->right=p;
			}
			p->parent=g->parent;
			p->position=g->position;
			if (g==start)
			{
				start=p;
			}
			g->left=p->right;
			p->right=g;
			g->position=1;
			g->parent=p;
			p->isred=0;
			g->isred=1;
		}
		else if(strcmp("111",c)==0 || strcmp("011",c)==0) 
		{
			if(g->parent!=NULL)
			{
				if (g->position==1)
					g->parent->right=p;
				else
					g->parent->left=p;
			}
			if(g==start)
			{
				start=p;
			}
			g->right=p->left;
			p->position=g->position;
			p->parent=g->parent;
			p->left=g;
			g->position=0;
			g->parent=p;
			p->isred=0;
			g->isred=1;
		}
		else if(strcmp("001",c)==0 || strcmp("101",c)==0)
		{
			if (g->parent!=NULL)
			{
				if (g->position==0)
					g->parent->left=t;
				else
					g->parent->right=t;
			}
			if (g==start)
			{
				start=t;
			}
			t->position=g->position;
			t->parent=g->parent;
			g->left=t->right;
			p->right=t->left;
			t->left=p;
			p->parent=t;
			p->position=0;
			t->right=g;
			g->parent=t;
			g->position=1;
			g->isred=1;
			t->isred=0;
		}
		else if(strcmp("010",c)==0 || strcmp("110",c)==0)
		{
			if (g->parent!=NULL)
			{
				if (g->position==0)
					g->parent->left=t;
				else
					g->parent->right=t;
				
			}
			if (g==start)
			{
				start=t;
			}
			t->position=g->position;
			t->parent=g->parent;
			g->right=t->left;
			p->left=t->right;
			t->left=g;
			g->parent=t;
			g->position=0;
			t->right=p;
			p->parent=t;
			p->position=1;
			t->isred=0;
			g->isred=1;
		}
	}
}

/*void doubleBlack(struct Node * x, struct Node * p)
{
	
}


void deleteNode(int num)
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
	
	struct Node *p,*x,*f;
	if (t->left==NULL && t->right==NULL)
	{
		if (t==start)
		{
			start=NULL;
			free(t);
			return;
		}
		if (t->isred==1)
		{
			free(t);
			return;
		}
		else
		{
			p=t->parent;
			free(t);
			doubleBlack(NULL,p);
			return;
		}
	}
	else if(t->right==NULL)
	{
		p=t->parent;
		x=t->left;
		if (t==start)
		{
			start=x;
			x->isred=0;
			x->parent=NULL;
			x->position=-1;
			free(t);
			return;
		}
		if (t->position==0)
			p->left=x;
		else
			p->right=x;
		x->parent=p;
		x->position=t->position;
		if (t->isred==1)
		{
			free(t);
			return;
		}
		else
		{
			if (x->isred==1)
			{	
				x->isred=0;
				free(t);
				return;
			}
			else
			{
				free(t);
				doubleBlack(x,p);
				return;
			}
		}
	}
	else if (t->left==NULL)
	{
		p=t->parent;
		x=t->right;
		if (t==start)
		{
			start=x;
			x->isred=0;
			x->parent=NULL;
			x->position=-1;
			free(t);
			return;
		}
		if (t->position==0)
			p->left=x;
		else
			p->right=x;
		x->parent=p;
		x->position=t->position;
		if (t->isred==1)
		{
			free(t);
			return;
		}
		else
		{
			if (x->isred==1)
			{
				x->isred=0;
				free(t);
				return;
			}
			else
			{
				free(t);
				doubleBlack(x,p);
				return;
			}
		}
	}
	else
	{
		f=t->left;
		while (f->right!=NULL)
		{
			f=f->right;
		}
		int temp=t->number;
		t->number->f->number;
		f->number=temp;
		
		deleteNode(f->number)
		return;
	}
}*/

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
		t->isred=0;
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
				t->isred=1;
				if (t->parent->isred==1)
				{
					doubleRed(t);
				}
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
				t->isred=1;
				if (t->parent->isred==1)
				{
					doubleRed(t);
				}
				return;
			}
			else
			{
				j=j->right;
			}
		}
	}
}


void inOrder(struct Node *t)
{
	if(t==NULL) 
		return;
	inOrder(t->left);
	printf("%d  %d\n",t->number,t->isred);	
	inOrder(t->right);
}


void preOrder(struct Node *t)
{
	if(t==NULL) 
		return;
	printf("%d  %d\n",t->number,t->isred);
	preOrder(t->left);
	preOrder(t->right);
}


void postOrder(struct Node *t)
{
	if(t==NULL) 
		return;
	postOrder(t->left);
	postOrder(t->right);
	printf("%d  %d\n",t->number,t->isred);
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
			//removeNode(num);
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
			//printf("Height %d\n",findHeight(start));
		}
		if(ch==7)
		{
			break;
		}
	}
	return 0;
}