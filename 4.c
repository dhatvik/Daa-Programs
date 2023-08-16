#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    if(a>b)
        return b;
    else
    return a;    
}
void flyod(int a[10][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++) 
    {   
    printf("%d\t",a[i][j]);
    }
    printf("\n");
    }
    printf("\n");
    }
}
void main()
{
    int i,j,n;
    int a[10][10];
    printf("Enter order of matrix\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    flyod(a,n);
    printf("Shortest distance matrix is  \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

}