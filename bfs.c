#include <stdio.h>
#include <stdlib.h>
void bfs(int a[10][10],int n,int visited[10],int source)
{
    int q[10],r=-1,f=0,delnode,i;
    visited[source]=1;
    q[++r]=source;
    while(f<=r)
    {
       delnode=q[f++];
       for(i=1;i<=n;i++)
       {
           if(a[delnode][i]==1 && visited[i]==0)
           {
               q[++r]=i;
               visited[i]=1;
           }
       }
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
            bfs(a,n,visited,i);
            count++;
        }
    }
    if(count==1)
        printf("graph is connected,%d component\n",count);
    else
        printf("graph is not connected, %d component",count);
    return 0;
}
