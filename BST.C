#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *lc;
	int d;
	struct Node *rc;
}node;

void add_node(node **p);
void inorder(node *p);
void preorder(node *p);
void postorder(node *p);

int main(void)
{
	node *start = NULL;
	int ch;
	while(1)
	{
		printf("%s","\n 1) Add Node");
		printf("%s","\n 2) Inorder");
		printf("%s","\n 3) Preorder");
		printf("%s","\n 4) Postorder");
		printf("%s","\n 5) EXIT...");
		printf("%s","\n\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_node(&start);
			break;
			case 2:
				inorder(start);
				getch();
			break;
			case 3:
				preorder(start);
				getch();
			break;
			case 4:
				postorder(start);
				getch();
			break;
			case 5:
				exit(0);
			default:
				printf("%s","\n Invalid Input");
				printf("%s","\n Press Any Key to Cont...");
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
		printf("%s","\n Memory Problem");
		printf("%s","\n Press Any Key to Cont...");
	}
	else
	{
		printf("%s","\n Enter Data : ");
		scanf("%d",&temp->d);
		temp->lc = NULL;
		temp->rc = NULL;
		if(*p == NULL)
			*p = temp;
		else
		{
			q = *p;
			while(1)
			{
				if(temp->d < q->d)
				{
					if(q->lc == NULL)
					{
						q->lc = temp;
						break;
					}
					else
						q = q->lc;
				}
				else
				{
					if(q->rc == NULL)
					{
						q->rc = temp;
						break;
					}
					else
						q = q->rc;
				}
			}
		}
		printf("%s","\n Data Successfully Added");
	}
}

void inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->lc);
		printf("\t%d",p->d);
		inorder(p->rc);
	}
}

void preorder(node *p)
{
	if(p!=NULL)
	{
		printf("\t%d",p->d);
		preorder(p->lc);
		preorder(p->rc);
	}
}

void postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->lc);
		postorder(p->rc);
		printf("\t%d",p->d);
	}
}


