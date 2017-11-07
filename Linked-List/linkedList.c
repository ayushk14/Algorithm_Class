/*linked list code to: 1. Insert, 2. Display, 3. Delete, 4. Reverse, 5. Search, 6. Exit */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	} *head;

/****************************************** Reverse **********************************************************************************/

void reverse()
{
	struct node *p, *c, *n;
	p = NULL;
	c = head;
	while(c!=NULL)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;	
	}
	head = p;
}

/****************************************** Reverse Ends *****************************************************************************/

/****************************************** Search ***********************************************************************************/

void search(int num)
{
	struct node *temp;
	temp = head;
	int flag = 0;
	if (temp == NULL)
	{
		printf("List is empty\n");
		flag = 1;
	}
	while(temp!=NULL)
	{
		if(temp->data == num)
		{
			printf("Number is present\n");
			flag = 2;
			break;
		}
		else
			temp = temp->next;
	}
	if (flag == 0)
		printf("Number is not present\n");
}

/****************************************** Search Ends ******************************************************************************/

/****************************************** Delete ***********************************************************************************/

void delete (int num)
{
	struct node *temp, *prev;
	temp = head;
	int flag = 0;
	if(temp == NULL)
	{
		printf("No list to delete\n");
		flag = 1;
	}
	while(temp!=NULL)
	{
		if (temp->data == num)
		{
			if (temp == head)
			{
				head = temp->next;
				free(temp);
				printf("Node Deleted\n");
				flag = 2;
				break;
			}
			else
			{
				prev->next = temp->next;
				free(temp);
				printf("Node Deleted\n");
				flag = 2;
				break;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
	if (flag == 0)
		printf("Number does not exists\n"); 
}

/****************************************** Delete Ends ******************************************************************************/

/****************************************** Display **********************************************************************************/

void display()
{
	struct  node *temp;
	temp = head;
	if (temp == NULL)
		printf("List is Empty\n");
	while (temp!=NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

/****************************************** Display Ends *****************************************************************************/


/****************************************** Insert ***********************************************************************************/

void addhead(int num)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	if (head == NULL)
	{
		head=temp;
		head->next = NULL;
	}
	else
	{
		temp->next = head;
		head=temp;
	}
}

void addafter(int num, int loc)
{
	int i;
	struct node *temp, *right, *left;
	right = head;
	for (i=0; i<loc; i++) 
	{
		left = right;
		right = right->next;
	}	
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	left->next = temp;
	left = temp;
	left->next = right;
}

void append(int num)
{
	struct node *temp, *right;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	right = (struct node *)head;
	while((right->next)!=NULL)
		right = right->next;
	right->next = temp;
	right = temp;
	right->next = NULL;
}

int count()
{
	int c = 0;
	struct node *temp;
	temp = head;
	while(temp!=NULL)
	{
		c++;
		temp = temp->next;
	}
	return c;
}

void insert (int num)
{
	int c=0;
	struct node *temp;
	temp = head;
	if (temp == NULL)
	{
		addhead(num);
	}
	else
	{
		while(temp!=NULL)
		{
			if((temp->data) < num)
				c++;
			temp = temp->next;
		}
		if (c==0)
			addhead(num);
		else if(c < count())
			addafter(num, c++);
		else
			append(num);
	}
}
/********************************************************* Insert Ends ******************************************************************/


int main()
{
	int opt, num;
	head = NULL;
	
	while(1)
	{
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("3. Delete\n");
		printf("4. Reverse\n");
		printf("5. Search\n");
		printf("6. Exit\n");
		printf("Enter your choice:");
		scanf("%d", &opt);
		if (opt == 1)
		{
			printf("Enter the number to be inserted:");
			scanf("%d", &num);
			insert(num);
			printf("New node/ nodes inserted\n");
		}
		else if (opt == 2)
		{
			printf("Diplaying all nodes\n");
			display();
		}
		else if(opt == 3)
		{
			printf("Enter the number to be deleted:");
			scanf("%d", &num);
			delete(num);
		}
		else if(opt == 4)
		{
			reverse();
			printf("Linked List Reversed\n");
		}
		else if(opt == 5)
		{
			printf("Enter the number to be searched:");
			scanf("%d", &num);
			search(num);
		}
		else if(opt == 6)
		{
			exit(0);
		}
		else
			printf("Invlaid option\n");
			
	}

	return 0;
}
