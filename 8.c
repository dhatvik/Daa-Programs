#include<stdio.h>
#define INF 999
int distance[50];
int cost[50][50];
int visited[50];
int source;
int n;

int min_distance()
{
    int min=INF;
    int min_index;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && distance[i]<=min)
        {
            min=distance[i];
            min_index=i;
        }
    }
    return min_index;
}

void printsol()
{
    printf("Vertex and Distance");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d",i,distance[i]);
    }
}

void dijkstras()
{

    for(int v=0;v<n;v++)
    {
        distance[v]=INF;
        visited[v]=0;
    }
    distance[source]=0;
    for(int i=0;i<n-1;i++)
    {
        int min=min_distance();
        visited[min]=1;

        for(int j=0;j<n;j++)
        {
            if(!visited[j] && cost[min][j] && (distance[min]!=INF) && (distance[j]>distance[min]+cost[min][j]))
            {
                distance[j]=distance[min]+cost[min][j];
            }
        }
    }


    printsol();
}
void main()
{

    printf("\nEnter the number node\n");
    scanf("%d",&n);
    printf("\n Enter the cost matrix");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("\nEnter source vertex");
    scanf("%d",&source);
    dijkstras();
}
