					/*	Write a program to implement different
						types of sorting ( Bubble, Insertion,
						Quick, Selection, Merge, Heap )	*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void bubble_sort(int a[],int n);
void insertion_sort(int a[],int n);
void selection_sort(int a[],int n);
void quick_sort(int a[],int l,int h);
int quick(int a[],int l,int h);
void merge_sort(int a[],int l,int h);
void merge(int a[],int l,int m,int h);
void heap_sort(int a[], int n);
void swap(int *a, int *b);
void heapify(int a[], int n, int i);

int main(void)
{
	int a[10],n,i,ch;
	printf("%s","\n Howmany Elements : ");
	scanf("%d",&n);
	printf("%s","\n Enter Number : ");
	for(i = 0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%s","\n Which Sorting Algorithm do You Want to Apply");
	printf("%s","\n 1) Bubble Sorting");
	printf("%s","\n 2) Insertion Sorting");
	printf("%s","\n 3) Selection Sorting");
	printf("%s","\n 4) Quick Sorting");
	printf("%s","\n 5) Merge Sorting");
	printf("%s","\n 6) Heap Sorting");
	printf("%s","\n\n Enter Your Choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			bubble_sort(a,n);
		break;
		case 2:
			insertion_sort(a,n);
		break;
		case 3:
			selection_sort(a,n);
		break;
		case 4:
			quick_sort(a,0,n-1);
		break;
		case 5:
			merge_sort(a,0,n-1);
		break;
		case 6:
			heap_sort(a,n);
		break;
		default:
			printf("%s","\n Invalid Input");
			printf("%s","\n Press Any Key...");
			exit(0);
	}
	printf("%s","\n Elements After Sorting Are : ");
	for(i = 0;i<n;i++)
		printf("  %d",a[i]);
	getch();
}

void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for(i = n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void insertion_sort(int a[],int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void selection_sort(int a[],int n)
{
	int i,j,t,pos;
	for(i=0;i<n-1;i++)
	{
		pos = i;
		for(j=i+1;j<n;j++)
		{
			if(a[pos]>a[j])
				pos = j;
		}
		if(pos != i)
		{
			t = a[i];
			a[i] = a[pos];
			a[pos] = t;
		}
	}
}

void quick_sort(int a[],int l,int h)
{
	int pos;
	if(l<h)
	{
		pos = quick(a,l,h);
		quick_sort(a,l,pos-1);
		quick_sort(a,pos+1,h);
	}
}

int quick(int a[],int l,int h)
{
	int pos,key,temp;
	pos = l;
	key = a[l];
	while(l<=h)
	{
		while((a[l]<=key) && (l<=h))
			l++;
		while((a[h]>key))
			h--;
		if(l<h)
		{
			temp = a[l];
			a[l] = a[h];
			a[h] = temp;
		}
	}
	temp = a[pos];
	a[pos] = a[h];
	a[h] = temp;
	return h;
}

void merge_sort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid = ( l + h ) / 2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}

void merge(int a[],int l,int m,int h)
{
	int b[100],i,j,k;
	i = l;
	j = m+1;
	k = 0;
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
		else if(a[j]<a[i])
		{
			b[k] = a[j];
			j++;
			k++;
		}
		else
		{
			b[k] = a[i];
			i++;
			k++;
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while(i<=m)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while(j<=h)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	for(i = l,j=0;i<=h;i++,j++)
		a[i] = b[j];
}

void heap_sort(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (i = n - 1; i >= 0; i--)
	{
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

void swap(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[largest])
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;
	if (largest != i)
	{
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}