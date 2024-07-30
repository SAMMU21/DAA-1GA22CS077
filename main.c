#include <stdio.h>
#include <stdlib.h>
void dijkstras(int cost[10][10],int n,int source)
{
    int i,visited[10],dist[10],u,v,count=1,min;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=cost[source][i];
    }
    visited[source]=1;
    dist[source]=0;
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0 && dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=i;
        count++;
        for(i=1;i<=n;i++)
        {
            if(dist[i]>dist[u]+cost[u][i])
                dist[i]=dist[u]+cost[u][i];
        }
    }
    printf("\n shortest path from %d\n",source);
    for(i=1;i<=n;i++)
        printf("\n %d to %d is %d",source,i,dist[i]);
}
int main()
{
    int n,cost[10][10],i,j,source;
    printf("\n Read number of nodes:\n");
    scanf("%d",&n);
    printf("\n Read source vertex\n");
    scanf("%d",&source);
    printf("\n Read cost Matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    dijkstras(cost,n,source);
    return 0;
}
