//Write a program to store the marks obtained by 10 students in 5 courses in a two- dimensional array
#include <stdio.h>
int main(void)
{
 int stu[10][5];
 int i,j,tot=0;
 printf("%s","\n Enter 10 Students Marks\n");
 for(i = 0;i < 10;i++)
 {
 for(j = 0;j < 5;j++)
 {
 printf("Enter %d Student %d Subject Marks : ",i+1,j+1);
 scanf("%d",&stu[i][j]);
 }
 }
 printf("%s","\n Input Information Is \n");
 printf("\n\tStu\tM1\tM2\tM3\tM4\tM5\tTot\n");
 for(i=0;i<10;i++)
 {
 tot=0;
 printf("\t%d",i+1);
 for(j=0;j<5;j++)
 {
 printf("\t%d",stu[i][j]);
 tot+=stu[i][j];
 }
 printf("\t%d\n",tot);
 }
 return 0;
}