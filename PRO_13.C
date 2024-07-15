			/*	Write a program to implement a
				priority queue using a linked list	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	int d;
	int p;
	struct Node *next;
}node;

void enqueue(node **f,node **r);
void dequeue(node **f,node **r);
void display(node *f,node *r);

int main(void)
{
	node *front = NULL,*rear = NULL;
	int ch;
	while(1)
	{
		printf("%s","\n 1) Enqueue");
		printf("%s","\n 2) Dequeue");
		printf("%s","\n 3) Display");
		printf("%s","\n 4) EXIT...");
		printf("%s","\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue(&front,&rear);
			break;
			case 2:
				dequeue(&front,&rear);
			break;
			case 3:
				display(front,rear);
			break;
			case 4:
				exit(0);
			default:
				printf("%s","\n Invalid Input");
				printf("%s","\n Press Any Key to Cont...");
				getch();
		}
	}
}

void enqueue(node **f,node **r)
{
	node *temp,*q,*t;
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
		printf("%s","\n Enter Priority : ");
		scanf("%d",&temp->p);
		if(*r == NULL)
		{
			*f = *r = temp;
			temp->next = NULL;
		}
		else
		{
			if(temp->p >= (*r)->p)
			{
				temp->next = NULL;
				(*r)->next = temp;
				(*r) = temp;
			}
			else if(temp->p < (*f)->p)
			{
				temp->next = *f;
				*f = temp;
			}
			else
			{
				q = *f;
				while( (q->p <= temp->p) )
				{
					t = q;
					q = q->next;
				}
				temp->next = q;
				t->next = temp;
			}
		}
		printf("%s","\n Node Successfully Inserted");
	}
	getch();
}

void dequeue(node **f,node **r)
{
	node *q;
	if(*f == NULL)
	{
		printf("%s","\n Priority Queue Is Underflow");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		q = *f;
		printf("Deleted Node Is : %d",(*f)->d);
		(*f) = (*f)->next;
		if(*f == NULL)
			*r = NULL;
		free(q);
	}
	getch();
}

void display(node *f,node *r)
{
	if(f == NULL)
	{
		printf("%s","\n No Element In Priority Queue");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		while(f != r)
		{
			printf("%d(%d)  ",f->d,f->p);
			f = f->next;
		}
		printf("%d(%d)  ",f->d,f->p);
	}
	getch();
}