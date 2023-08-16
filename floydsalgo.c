/*Suppose in a network of cities, you are interested in finding shortest paths between all 
cities. Design a ‘C’ program to implement this using Floyd’s algorithm. Give the trace of 
this algorithm.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int min(int,int);
void flyod(int d[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
} //finding each pair shortest distance
int min(int a ,int b)
{
 if(a<b)
 return a;
 else
 return b;
} //for finging minimum among 2 values

void main()
{
 int i,j,d[10][10];
 int n;
 printf("Enter Number of Vertices");  //taking input
 scanf("%d",&n);
 printf("Enter the Distance Matrix");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 scanf("%d",&d[i][j]);
 }
 printf("\n");
 }
 flyod(d,n);  //computing shortest distance
 printf("The Shortest Distance Matrix is:");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 printf("%d\t",d[i][j]);
 }//end of for (j)
 printf("\n");
 }//end of for (i)
}//end of main
 