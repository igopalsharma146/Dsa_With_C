//Write a program to insert one element in an array and delete an element from an- array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
void insert_element(int a[],int n);
void delete_element(int a[],int n);
int main(void)
{
 int arr[SIZE],ch;
 int i,item,pos,n;
 printf("%s","\n Howmany Numbers : ");
 scanf("%d",&n);
 printf("%s","\n Enter Numbers : ");
 for(i=0;i<n;i++)
 scanf("%d",&arr[i]);
 printf("%s","\n Operation");
 printf("%s","\n 1) Insert An Element");
 printf("%s","\n 2) Delete An Element");
 printf("%s","\n Enter Your Choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 insert_element(arr,n);
 break;
 case 2:
 delete_element(arr,n);
 break;
 default:
 printf("%s","\n Invalid Input");
 }
}
void insert_element(int a[],int n)
{
 int i,item,pos;
 printf("%s","\n Array before insertion: ");
 for (i = 0; i < n; i++)
 printf("%d ", a[i]);
 if(n==SIZE)
 {
 printf("%s","\n There is no space in an array");
 return;
 }
 printf("%s","\n Enter the element to be inserted: ");
 scanf("%d",&item);
 printf("%s","\n Enter the position at which the element is to be inserted: ");
 scanf("%d",&pos);
 n++;
 for (i = n-1; i >= pos; i--)
 a[i] = a[i-1];
 a[pos - 1] = item;
 printf("%s","\n Array after insertion: ");
 for (i = 0; i < n; i++)
 printf("%d ", a[i]);
}
void delete_element(int a[],int n)
{
 int i,key,pos=-1;
 printf("%s","Array before deletion: ");
 for (i = 0; i < n; i++)
 printf("%d ", a[i]);
 printf("%s","\n Enter element to delete: ");
 scanf("%d",&key);
 for(i = 0; i < n; i++)
 {
 if(a[i] == key)
{
 pos = i;
 break;
 }
 }
 if(pos != -1)
 {
 for(i = pos; i < n - 1; i++)
 a[i] = a[i+1];
 n--;
 printf("%s","\n Array after deletion: ");
 for(i = 0; i <= n - 1; i++)
 printf("%d ",a[i]);
 }
 else
 printf("%s","\n Element Not Found\n");
}