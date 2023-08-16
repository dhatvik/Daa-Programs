#include<stdio.h>
int cost[20][20];
int visited[20]={0};
int min_cost=0;
int i,j;

void prims(int n)
{
    int ne=1;
    int a;
    int b;
    while(ne<n)
    {
        int min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(visited[a]==0 || visited[b]==0)
        {
            printf("\n Edge %d :from %d to %d ,cost:%d",ne,a,b,min);
            min_cost=min_cost+min;
            ne++;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999; 
    }
    printf("\nMin cost is %d",min_cost);
}
void main()
{
    int n;
    printf("\nEnter the number node\n");
    scanf("%d",&n);
    printf("\n Enter the cost matrix");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }
    int source;
    printf("\nEnter source vertex");
    scanf("%d",&source);
    visited[source]=1;
    prims(n);
}