#include<stdio.h>
#include<conio.h>
int main()
{
    int a[20],i,j,temp,n;
    float sum=0,mean,median;
    printf("enter the value of element in array\n");
    scanf("%d",&n);
    printf("enter the elements in array");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    //increasing order
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("array is:");
    for(j=0;j<n;j++)
    {
        printf("%d\t",a[j]);
    }
    // for mean
    for(j=0;j<n;j++)
    {
        sum=sum+a[j];
    }
    mean=sum/n;
    printf("\nmean is:%f",mean);
    //for median
    for(j=0;j<n;j++)
    {
    if(n%2!=0)
    {
    median=a[(n/2)];
    }
    if(n%2==0)
    {
    median=(a[n/2]+a[n/2-1])/2.0;
    }
    }
    printf("\nmedian is:%f",median);
    getch();
}