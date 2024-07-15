#include<stdio.h>
#include<conio.h>
float meanx(int*,int);
float medianx(int*,int);
int max();
int main()
{
     int a[10],n;
     float mean,median;
     printf("Enter the n\n");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
     printf("Enter the element a[%d]:",i);
     scanf("%d",&a[i]);
     }
   mean=meanx(&a[0],n);
   median=medianx(&a[0],n);
    printf("%f",mean);
    getch();
    return 0;
}
float meanx(int*p,int n)
{
    float sum=0,mean;
 for(int i=0 ;i<n;p++,i++)
  {  
    sum=sum+*p;
  }
 return mean=sum/n;
}
float medianx(int*p,int n)
{
for(int j=0;j<n;j++)
 a[j]=max(n);
}
int max()
{

}