/*	Write a program to add two polynomials using linked list	*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	int c;
	int p;
	struct Node *next;
}node;

void add_node(node **p);
void display(node *p);
void add_poly(node *p1,node *p2,node **p3);
void add_node_poly(node **p,node *temp);

int main(void)
{
	node *start1 = NULL,*start2 = NULL;
	node *start3 = NULL;
	int ch;
	while(1)
	{
		printf("\n 1) Add Node for 1st Polynomial");
		printf("\n 2) Add Node for 2nd Polynomial");
		printf("\n 3) Add Polynomial");
		printf("\n 4) Display");
		printf("\n 5) EXIT...");
		printf("\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_node(&start1);
			break;
			case 2:
				add_node(&start2);
			break;
			case 3:
				add_poly(start1,start2,&start3);
			break;
			case 4:
				display(start1);
				display(start2);
				display(start3);
				getch();
			break;
			case 5:
				exit(0);
			default:
				printf("\n Invalid Input");
				getch();
		}
	}
}

void add_node(node **p)
{
	node *temp,*q;
	temp = (node *)malloc(sizeof(node));
	if(temp == NULL)
	{
		printf("\n Memory Problem");
		printf("\n Press Any Key to Cont...");
	}
	else
	{
		temp = (node *)malloc(sizeof(node));
		if(temp == NULL)
		{
			printf("%s","\n Memory Problem");
			printf("%s","\n Press Any Key to Cont...");
		}
		else
		{
			printf("%s","\n Enter Coefficient : ");
			scanf("%d",&temp->c);
			printf("%s","\n Enter Power : ");
			scanf("%d",&temp->p);
			temp->next = NULL;
			if(*p == NULL)
				*p = temp;
			else
			{
				q = *p;
				while(q->next != NULL)
					q = q->next;
				q->next = temp;
			}
			printf("%s","\n Node Successfully Added");
		}
	}
	getch();
}

void add_poly(node *p1,node *p2,node **p3)
{
	node *temp;
	while(p1!=NULL && p2!=NULL)
	{
		temp = (node *)malloc(sizeof(node));
		temp->next = NULL;
		if(temp == NULL)
		{
			printf("%s","\n Memory Problem");
			printf("%s","\n Press Any Key to Cont...");
		}
		else
		{
			if(p1->p == p2->p)
			{
				temp->c = p1->c + p2->c;
				temp->p = p1->p;
				p1 = p1->next;
				p2 = p2->next;
			}
			else if(p1->p > p2->p)
			{
				temp->c = p1->c;
				temp->p = p1->p;
				p1 = p1->next;
			}
			else
			{
				temp->c = p2->c;
				temp->p = p2->p;
				p2 = p2->next;
			}
		}
		add_node_poly(p3,temp);
	}
	while(p1!=NULL)
	{
		temp = (node *)malloc(sizeof(node));
		temp->next = NULL;
		if(temp == NULL)
		{
			printf("%s","\n Memory Problem");
			printf("%s","\n Press Any Key to Cont...");
		}
		else
		{
			temp->c = p1->c;
			temp->p = p1->p;
			p1 = p1->next;
		}
		add_node_poly(p3,temp);
	}
	while(p2!=NULL)
	{
		temp = (node *)malloc(sizeof(node));
		temp->next = NULL;
		if(temp == NULL)
		{
			printf("%s","\n Memory Problem");
			printf("%s","\n Press Any Key to Cont...");
		}
		else
		{
			temp->c = p2->c;
			temp->p = p2->p;
			p2 = p2->next;
		}
		add_node_poly(p3,temp);
	}
}

void add_node_poly(node **p,node *temp)
{
	node *q=*p;
	if(*p == NULL)
		*p = temp;
	else
	{
		while(q->next!=NULL)
			q = q->next;
		q->next = temp;
	}
}

void display(node *p)
{
	if(p == NULL)
		printf("%s","Polynomial Not Present");
	else
	{
		while(p!=NULL)
		{
			printf(" %dX%d ",p->c,p->p);
			p = p->next;
			if(p!=NULL)
				printf("+");
		}
	}
	printf("\n");
}



