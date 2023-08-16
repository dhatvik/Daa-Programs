// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// int i,j,n,m,w[10],p[10],v[10][10];

// int max(int a,int b)
// {
//     if(a>b)
//     return a;
//     else
//     return b;
// }
// void knapsack()
// {
//     for(i=0;i<=n;i++)
//     {
//         for(j=0;j<=m;j++)
//         {
//             if(i==0 || j==0)
//             {
//                 v[i][j]=0;
//             }
//             else if(j-w[i]<0)
//             {
//                 v[i][j]=v[i-1][j];
//             }
//             else
//             v[i][j]=max(v[i-1][j] , p[i]+v[i-1][j-w[i]]);
//         }
//     }
//     printf("optimal matrix is \n");
//     for(i=0;i<=n;i++)
//     {
//         for(j=0;j<=m;j++)
//         {
//             printf("%d\t",v[i][j]);
//         }
//         printf("\n");
//     }
// }
// void element()
// {
//     int x[n+1];
//     int maxprofit;
//     for(i=0;i<=n;i++)
//     {
//         x[i]=0;
//     }
//     i=n;
//     j=m;
//     while(i>0 && j>0)
//     {
//         if(v[i][j]!=v[i-1][j])
//         {
//             x[i]=1;

//             j=j-w[i];
//         }
//     }
//     for(i=1;i<=n;i++)
//     {
//         if(x[i]==1)
//         {
//             printf("%d/t",i);
//             maxprofit=maxprofit+p[i];
//         }
//     }
//     printf("Maximum profit is %d",maxprofit);
// }
// void main()
// {
//     printf("\nenter number of items");
//     scanf("%d",&n);
//     printf("\nEnter capacity of knapsack");
//     scanf("%d",&m);
//     printf("\nEnter the weights of items ");
//     for(i=1;i<=n;i++)
//     scanf("\n%d",&w[i]);
//     printf("\nenter the profits of each item");
//     for(i=1;i<=n;i++)
//     scanf("\n%d",&p[i]);

//     knapsack();
//     printf("\n");
//     element();
// }

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,j,n,m,w[10],p[10],v[10][10];

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void knapsack()
{
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                v[i][j]=0;
            }
            else if(j-w[i]<0)
            {
                v[i][j]=v[i-1][j];
            }
            else
            v[i][j]=max(v[i-1][j] , p[i]+v[i-1][j-w[i]]);
        }
    }
    printf("optimal matrix is \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
}
void element()
{
    int x[n+1];
    int maxprofit;
    for(i=0;i<=n;i++)
    {
        x[i]=0;
    }
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf("%d\t",i);
            // maxprofit=maxprofit+p[i];
        }
    }
    printf("Maximum profit is %d",v[n][m]);
}
void main()
{
    printf("\nenter number of items");
    scanf("%d",&n);
    printf("\nEnter capacity of knapsack");
    scanf("%d",&m);
    printf("\nEnter the weights of items ");
    for(i=1;i<=n;i++)
    scanf("\n%d",&w[i]);
    printf("\nenter the profits of each item");
    for(i=1;i<=n;i++)
    scanf("\n%d",&p[i]);

    knapsack();
    printf("\n");
    element();
}
