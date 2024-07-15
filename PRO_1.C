//Write a program to find the mean and the median of the numbers stored in an array
#include <stdio.h>
#include <stdlib.h>
double findMean(int a[], int n);
double findMedian(int a[], int n);
void bubble_sort(int a[],int n);
int main(void)
{
    int a[10],n,i;
    printf("%s","\n Howmany Numbers : ");
    scanf("%d",&n);
    printf("%s","\n Enter Numbers : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Mean = %f\n", findMean(a, n));
    printf("Median = %f\n", findMedian(a, n));
    return 0;
}

double findMean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    sum += a[i];
    return (double)sum / (double)n;
}
double findMedian(int a[], int n)
{
    bubble_sort(a,n);
    if (n % 2 != 0)
    return (double)a[n / 2];
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
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