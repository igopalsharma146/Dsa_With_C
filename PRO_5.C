/*	Write down a program to implement single linked list,
	including insertion, deletion and
	searching in the linked list.	*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	int d;
	struct Node *next;
}node;

void add_beg(node **p);
void del(node **p);
int count(node *p);
void search(node *p);
void display(node *p);

int main(void)
{
	node *start = NULL;
	int ch;
	while(1)
	{
		printf("\n 1) Add at Beginning");
		printf("\n 2) Delete Node");
		printf("\n 3) Search Node");
		printf("\n 4) Display");
		printf("\n 5) EXIT...");
		printf("\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_beg(&start);
			break;
			case 2:
				del(&start);
			break;
			case 3:
				search(start);
			break;
			case 4:
				display(start);
			break;
			case 5:
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

void del(node **p)
{
	int n,tot;
	node *q,*temp;
	if(*p == NULL)
	{
		printf("%s","\n Linked List Not Present");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		printf("%s","\n Enter Node No(for deletion) : ");
		scanf("%d",&n);
		tot = count(*p);
		if(n<1 || n>tot)
		{
			printf("%s","\n Node Number is Invalid");
			printf("%s","\n Press Any Key to Cont...");
		}
		else
		{
			if(n == 1)
			{
				temp = *p;
				*p = (*p)->next;
				free(temp);
			}
			else
			{
				q = *p;
				while(n>2)
				{
					n--;
					q = q->next;
				}
				temp = q->next;
				q->next = q->next->next;
				free(temp);
			}
			printf("%s","\n Data Successfully Deleted");
		}
	}
	getch();
}

int count(node *p)
{
	int tot = 0;
	if(p == NULL)
		return 0;
	else
	{
		while(p!=NULL)
		{
			tot++;
			p=p->next;
		}
	}
	return tot;
}

void search(node *p)
{
	int t = 0,se;
	if(p == NULL)
	{
		printf("%s","\n Linked List Not Present");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		printf("%s","\n Enter Search Element : ");
		scanf("%d",&se);
		while(p != NULL)
		{
			t++;
			if(p->d == se)
				printf("%s%d","\n Data Present at Node No : ",t);
			p=p->next;
		}
	}
	getch();
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



