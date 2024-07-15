					/*	Write a program to implement
					a circular queue using an array	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5

void enqueue(int q[],int *f,int *r);
void dequeue(int q[],int *f,int *r);

int main(void)
{
	int ch;
	int q[SIZE],f=-1,r=-1;
	while(1)
	{
		printf("%s","\t\t\t Circular Queue Using Array");
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

void enqueue(int q[],int *f,int *r)
{
	if((*r+1)%SIZE == *f)
		printf("%s","\n Queue Is Overflow");
	else
	{
		*r = (*r+1)%SIZE;
		printf("%s","\n Enter Element : ");
		scanf("%d",&q[*r]);
		if(*f == -1)
			*f = 0;
		printf("%s","Element Successfully Inserted");
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
		if(*f == *r)
			*f = *r = -1;
		else
			*f = (*f+1) % SIZE;
	}
	getch();
}

