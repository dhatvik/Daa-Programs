#include<stdio.h>
#include<stdlib.h>
 
 typedef struct queue
 {
    int size;
    int f;
    int r;
    int* arr;
 }queue;

void enqueue(queue* q,int val)
{
    q->arr[++q->r]=val;
}

int dequeue(queue* q)
{
    return q->arr[++q->f];
}

int IsEmpty(queue* q)
{
    if(q->f==q->r)
    return 1;
    else 
    return 0;
}

void main()
{
    int n,initial;
    printf("Enter no of nodes\n");
    scanf("%d",&n);

    queue q;
    q.size;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*(sizeof(int)));

    int a[n][n];
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&a[i][j]);

    int visited[100]={0};

    printf("Enter Initail node\t");
    scanf("%d",&initial);

    visited[initial]=1;
    enqueue(&q,initial);
    printf("%d",initial);

    while(!IsEmpty(&q))
    {
        int node=dequeue(&q);
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && a[node][j])
            {
                enqueue(&q,j);
                visited[j]=1;
                printf("->%d",j);
            }
        }
    }

}