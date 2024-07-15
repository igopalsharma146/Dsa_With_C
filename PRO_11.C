				/*	Write a program to implement
					a queue using an array and linked list	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Node
{
	int d;
	struct Node *next;
}node;

void enqueue(int q[],int *f,int *r);
void dequeue(int q[],int *f,int *r);
void enqueue_ll(node **f,node **r);
void dequeue_ll(node **f,node **r);

int main(void)
{
	int ch;
	int q[SIZE],f=-1,r=-1;
	node *front=NULL,*rear=NULL;
	printf("%s","\n 1) Queue Using Array");
	printf("%s","\n 2) Queue Using Linked List");
	printf("%s","\n 3) EXIT...");
	printf("%s","\n\n Enter Your Choice : ");
	scanf("%d",&ch);
	if(ch == 1)
	{
		while(1)
		{
			printf("%s","\t\t\t Queue Using Array");
			printf("%s","\n 1) Enqueue");
			printf("%s","\n 2) Dequeue");
			printf("%s","\n 3) EXIT...");
			printf("%s","\n\n Enter Your Choice : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					enqueue(q,&f,&r);
				break;
				case 2:
					dequeue(q,&f,&r);
				break;
				case 3:
					exit(0);
				default:
					printf("%s","\n Invalid Input");
					printf("%s","\n Press Any Key to Cont...");
					getch();
			}
		}
	}
	else if(ch == 2)
	{
		while(1)
		{
			printf("%s","\t\t\t Queue Using Linked List");
			printf("%s","\n 1) Enqueue");
			printf("%s","\n 2) Dequeue");
			printf("%s","\n 3) EXIT...");
			printf("%s","\n\n Enter Your Choice : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					enqueue_ll(&front,&rear);
				break;
				case 2:
					dequeue_ll(&front,&rear);
				break;
				case 3:
					exit(0);
				default:
					printf("%s","\n Invalid Input");
					printf("%s","\n Press Any Key to Cont...");
					getch();
			}
		}
	}
	else if(ch == 3)
		exit(0);
	else
	{
		printf("%s","\n Invalid Input");
		printf("%s","\n Press Any Key...");
		getch();
	}
}

void enqueue(int q[],int *f,int *r)
{
	if(*r == SIZE - 1)
		printf("%s","\n Queue Is Overflow");
	else
	{
		(*r)++;
		printf("%s","\n Enter Element : ");
		scanf("%d",&q[*r]);
		if(*f == -1)
			(*f)++;
		printf("%s","\n Data Successfully Inserted");
	}
	getch();
}

void dequeue(int q[],int *f,int *r)
{
	if(*f == -1)
		printf("%s","\n Queue Is Underflow");
	else
	{
		printf("\n Deleted Element Is : %d",q[*f]);
		(*f)++;
		if(*f > *r)
			*f = *r = -1;
	}
	getch();
}

void enqueue_ll(node **f,node **r)
{
	node *temp;
	temp = (node *)malloc(sizeof(node *));
	if(temp == NULL)
	{
		printf("%s","\n Memory Problem");
		printf("%s","\n Queue Is Overflow");
	}
	else
	{
		printf("%s","\n Enter Data : ");
		scanf("%d",&temp->d);
		temp->next = NULL;
		if(*r == NULL)
			*f = *r = temp;
		else
		{
			(*r)->next = temp;
			*r = temp;
		}
		printf("%s","\n Node Successfully Inserted");
	}
	getch();
}

void dequeue_ll(node **f,node **r)
{
	node *q;
	if(*f == NULL)
		printf("%s","\n Queue Is Underflow");
	else
	{
		q = *f;
		printf("\n Deleted Data Is : %d",(*f)->d);
		(*f) = (*f)->next;
		if(*f==NULL)
			*r = NULL;
		free(q);
	}
	getch();
}
