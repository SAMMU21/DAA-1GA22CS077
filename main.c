#include <stdio.h>
#include <stdlib.h>
void dfs(int a[10][10],int n,int visited[10],int source)
{
    int i;
    visited[source]=1;
    for(i=1;i<=n;i++)
    {
        if(a[source][i]==1 && visited[i]==0)
            dfs(a,n,visited,i);
    }
}
int main()
{
    int n,a[10][10],i,j,visited[10],count=0;
    printf("read number of nodes:\n");
    scanf("%d",&n);
    printf("read adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(a,n,visited,i);
            count++;
        }
    }
    if(count==1)
        printf("graph is connected,%d component\n",count);
    else
        printf("graph is not connected, %d component",count);
    return 0;
}
