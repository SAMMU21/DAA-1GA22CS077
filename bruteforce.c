#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count;
int bfsm(char t[20], char p[10])
{
    int n,m,i,j;
    n=strlen(t);
    m=strlen(p);
    for(i=0;i<=n-m;i++)
    {
        j=0;
        while(j<m && p[j]==t[i+j])
        {
          j=j+1;
            count++;
        }
        count++;
        if(j==m)
            return i;
    }
    return -1;
}
int main()
{
    char t[20],p[10];
    int flag;
    printf("\n Read Text\n");
    scanf("%s",t);
    printf("\n Read pattern\n");
    scanf("%s",p);
    flag=bfsm(t,p);
    if(flag==-1)
        printf("\n pattern not found\n");
    else
        printf("\n pattern found at %d location\n",flag+1);
        printf("number of comparisions=%d",count-1);
    return 0;
}
