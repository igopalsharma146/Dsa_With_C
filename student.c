#include<stdio.h>
#include<conio.h>
int main()
{
    int a[10][10];
    char ch[100]="HIMCP";
for(int i=0;i<10;i++)
{for(int j=0;j<5;j++)
{
printf("Enter the %d student %c subject marks:",(i+1),ch[j]);
  scanf("%d",&a[i][j]);
}
}
printf("\t");
for(int j=0;j<5;j++)
printf("%c\t",ch[j]);
printf("\n");
for(int i=0;i<10;i++)
{
  printf("%d.\t ",(i+1));
for(int j=0;j<5;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
}