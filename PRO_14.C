		/*	Write a program to implement
			a double ended queue using a linked list	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Node
{
	struct Node *pre;
	int d;
	struct Node *next;
}node;

void enqueue_f(node **f,node **r);
void enqueue_r(node **f,node **r);
void dequeue_f(node **f,node **r);
void dequeue_r(node **f,node **r);
void display(node **f,node **r);

int main(void)
{
	int ch;
	node *front=NULL,*rear=NULL;
	while(1)
	{
		printf("%s","\n 1) Enqueue At Front");
		printf("%s","\n 2) Enqueue At Rear");
		printf("%s","\n 3) Dequeue At Front");
		printf("%s","\n 4) Dequeue At Rear");
		printf("%s","\n 5) Display");
		printf("%s","\n 6) EXIT...");
		printf("%s","\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue_f(&front,&rear);
			break;
			case 2:
				enqueue_r(&front,&rear);
			break;
			case 3:
				dequeue_f(&front,&rear);
			break;
			case 4:
				dequeue_r(&front,&rear);
			break;
			case 5:
				display(&front,&rear);
			break;
			case 6:
				exit(0);
			default:
				printf("%s","\n Invalid Input");
				printf("%s","\n Press Any Key to Cont...");
				getch();
		}
	}
}

void enqueue_f(node **f,node **r)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp == NULL)
	{
		printf("%s","\n Memory Problem");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		printf("%s","\n Enter Data : ");
		scanf("%d",&temp->d);
		temp->pre = NULL;
		temp->next = *f;
		if(*f != NULL)
			(*f)->pre = temp;
		*f = temp;
		if(*r == NULL)
			*r = temp;
		printf("%s","\n Node Successfully Inserted At Front");
	}
	getch();
}

void enqueue_r(node **f,node **r)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp == NULL)
	{
		printf("%s","\n Memory Problem");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		printf("%s","\n Enter Data : ");
		scanf("%d",&temp->d);
		temp->next = NULL;
		temp->pre = *r;
		if(*r != NULL)
			(*r)->next = temp;
		*r = temp;
		if(*f == NULL)
			*f = temp;
		printf("%s","\n Node Successfully Inserted At Front");
	}
	getch();
}

void dequeue_f(node **f,node **r)
{
	node *q;
	if(*f == NULL)
	{
		printf("%s","\n Deque Is Underflow");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		q = *f;
		printf("\n Deleted Data Is : %d",(*f)->d);
		(*f) = (*f)->next;
		if(*f == NULL)
			*f = *r = NULL;
		else
			(*f)->pre = NULL;
		free(q);
	}
	getch();
}

void dequeue_r(node **f,node **r)
{
	node *q;
	if(*r == NULL)
	{
		printf("%s","\n Deque Is Underflow");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		q = *r;
		printf("\n Deleted Data Is : %d",(*r)->d);
		(*r) = (*r)->pre;
		if(*r == NULL)
			*r = *f = NULL;
		else
			(*r)->next = NULL;
		free(q);
	}
	getch();
}

void display(node **f,node **r)
{
	node *q;
	if(*f == NULL)
	{
		printf("%s","\n Deque is Empty");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		q = *f;
		while( q != (*r) )
		{
			printf("\t %d",q->d);
			q = q->next;
		}
		printf("\t%d",q->d);
	}
	getch();
}