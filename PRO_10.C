			/*	Write a program to implement a
				stack using an array and linked list	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define  SIZE 5

typedef struct Node
{
	int d;
	struct Node *next;
}node;

void push(int st[],int *t);
void pop(int st[],int *t);

void push_ll(node **p);
void pop_ll(node **p);

int main(void)
{
	int st[SIZE],top=-1;
	node *top1 = NULL;
	int ch;
	printf("\n 1) Stack Using Array");
	printf("\n 2) Stack Using Linked List");
	printf("\n 3) EXIT...");
	printf("\n\n Enter Your Choice : ");
	scanf("%d",&ch);
	if(ch == 1)
	{
		while(1)
		{
			printf("\t\t\t Stack Using Array");
			printf("\n 1) Push");
			printf("\n 2) Pop");
			printf("\n 3) EXIT");
			printf("\n\n Enter Your Choice : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					push(st,&top);
				break;
				case 2:
					pop(st,&top);
				break;
				case 3:
					exit(0);
				default:
					printf("\n Invalid Input");
					getch();
			}
		}
	}
	else if(ch == 2)
	{
		while(1)
		{
			printf("\t\t\t Stack Using Linked List");
			printf("\n 1) Push");
			printf("\n 2) Pop");
			printf("\n 3) EXIT");
			printf("\n\n Enter Your Choice : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					push_ll(&top1);
				break;
				case 2:
					pop_ll(&top1);
				break;
				case 3:
					exit(0);
				default:
					printf("\n Invalid Input");
					getch();
			}
		}
	}
	else if(ch == 3)
		exit(0);
	else
	{
		printf("\n Invalid Input");
		getch();
	}
}

void push(int st[],int *t)
{
	if(*t == SIZE - 1)
		printf("\n Stack Is Overflow");
	else
	{
		(*t)++;
		printf("\n Enter Data : ");
		scanf("%d",&st[*t]);
		printf("\n Data Successfully Pushed");
	}
	getch();
}

void pop(int st[],int *t)
{
	if(*t == -1)
		printf("\n Stack Is Underflow");
	else
	{
		printf("\n Popped Data : %d",st[*t]);
		(*t)--;
	}
	getch();
}

void push_ll(node **p)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp == NULL)
		printf("\n Memory Problem (Overflow) ");
	else
	{
		printf("\n Enter Data : ");
		scanf("%d",&temp->d);
		temp->next = *p;
		*p = temp;
		printf("\n Data Successfully Pushed");
	}
	getch();
}

void pop_ll(node **p)
{
	node *q;
	if(*p == NULL)
		printf("\n Stack Is Underflow");
	else
	{
		q = *p;
		printf("\n Popped Data Is : %d",(*p)->d);
		(*p) = (*p)->next;
		free(q);
	}
	getch();
}



