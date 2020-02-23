#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

#define INF 0x3f3f3f3f

int n,e;
int mp[15][15];
int vis[15];
int haveprint[15];
void bfs(int s)
{
    queue<int> q;
    int i;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        printf("%d ",x);
        q.pop();
        for(i=0;i<n;i++)
        {
            if(mp[x][i]==1 && !vis[i])
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }
    
}
void dfs(int s)
{
    int i;
    printf("%d ",s);
    for(i=0;i<n;i++)
    {
        if(mp[s][i]==1 && !vis[i])
        {
            vis[i]=1;
            dfs(i);
        }
    }
}

int main()
{
    memset(mp,INF,sizeof(mp));
    scanf("%d %d",&n,&e);
    int i;
    int u,v;
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&u,&v);
        mp[u][v]=1;
        mp[v][u]=1;
    }
    
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            printf("{ ");
            dfs(i);
            printf("}\n");
        }
    }
    
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            printf("{ ");
            bfs(i);
            printf("}\n");
        }
    }
    return 0;
}
