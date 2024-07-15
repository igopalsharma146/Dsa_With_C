#include<stdio.h>
#include<conio.h>
int main()
{
int a[100],i,pos,size,item;
printf("enter the size of array:");
scanf("%d",&size);
printf("enter array elements:");
for(i=0;i<size;i++)
{
    scanf("%d",&a[i]);
}
printf("enter the position that you want:");
{
    scanf("%d",&pos);
}
printf("enter the item that you want:");
{
    scanf("%d",&item);
}
for(i=size;i>pos;i--)
{
    a[i]=a[i-1];
}
a[pos]=item;
size++;
printf("new array:");
for(i=0;i<size;i++)
{
    printf("%d",a[i]);
}
getch();
}