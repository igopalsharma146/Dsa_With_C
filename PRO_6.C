/*	Write a program to print the elements of a linked list
	in reverse order without disturbing the linked list	*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	int d;
	struct Node *next;
}node;

void add_beg(node **p);
void display_rev(node *p);
void display(node *p);

int main(void)
{
	node *start = NULL;
	int ch;
	while(1)
	{
		printf("\n 1) Add at Beginning");
		printf("\n 2) Display Reverse");
		printf("\n 3) Display");
		printf("\n 4) EXIT...");
		printf("\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_beg(&start);
			break;
			case 2:
				if(start == NULL)
					printf("%s","\n Linked List Not Present");
				else
					display_rev(start);
				getch();
			break;
			case 3:
				display(start);
			break;
			case 4:
				exit(0);
			default:
				printf("\n Invalid Input");
				getch();
		}
	}
}

void add_beg(node **p)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp == NULL)
	{
		printf("\n Memory Problem");
		printf("\n Press Any Key to Cont...");
	}
	else
	{
		printf("\n Enter Number : ");
		scanf("%d",&temp->d);
		temp->next = *p;
		*p = temp;
		printf("\n Data Successfully Added");
	}
	getch();
}

void display_rev(node *p)
{
	if(p == NULL)
		return;
	else
	{
		display_rev(p->next);
		printf("\t%d",p->d);
	}
}

void display(node *p)
{
	if(p == NULL)
		printf("\n Linked List is Empty");
	else
	{
		while(p!=NULL)
		{
			printf("\t%d",p->d);
			p = p->next;
		}
	}
	getch();
}



