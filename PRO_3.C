//Write a program to Linear & Binary search for a number in an array
#include <stdio.h>
void linear_search(int a[],int n,int s);
int binary_search(int a[], int n,int s);
void bubble_sort(int a[],int n); 
int main(void)
{
 int a[100],s,i,n,ch;
 int result;
 printf("%s","Enter the number of elements in array\n");
 scanf("%d",&n);
 printf("Enter %d numbers\n", n);
 for ( i = 0 ; i < n ; i++ )
 scanf("%d",&a[i]);
 printf("%s","\n Enter the number to search : ");
 scanf("%d",&s);
 printf("%s","\n Search Technique");
 printf("%s","\n 1) Linear Search");
 printf("%s","\n 2) Binary Search");
 printf("%s","\n Enter Your Choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 linear_search(a,n,s);
 break;
 case 2:
 result = binary_search(a,n,s);
 if (result == -1)
 printf("%s","Element Not found");
 else
 printf("Element is found at index %d", result);
 break;
 default:
 printf("%s","\n Invalid Choice");
 }
}
void linear_search(int a[],int n,int s)
{
 int i;
 for ( i = 0 ; i < n ; i++ )
 {
 if ( a[i] == s ) 
 {
 printf("%d is present at location %d.\n", s, i+1);
 break;
 }
 }
 if ( i == n )
 printf("%d is not present in array.\n", s);
}
int binary_search(int a[], int n,int s)
{
 int l,h,mid;
 bubble_sort(a,n);
 l=0;
 h=n-1;
 while (l <= h)
 {
 mid = (l + h) / 2;
 if (a[mid] == s)
 return mid;
 if (a[mid] < s)
 l = mid + 1;
 else
 h = mid - 1;
 }
 return -1;
}
void bubble_sort(int a[],int n) 
{
 int i,j,temp;
 for(i=0;i<n-1;i++)
 {
 for(j = n-1;j>i;j--)
 {
 if(a[j]<a[j-1])
 {
 temp = a[j];
 a[j] = a[j-1];
 a[j-1] = temp;
 }
 }
 }
}