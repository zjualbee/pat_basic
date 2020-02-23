#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;
int vis[30001];
int root[30001]={0};
int GetRoot(int x)
{
    if(vis[x]==x) return vis[x];
    vis[x]=GetRoot(vis[x]);
    return vis[x];
}
void Join(int a,int b)
{
    int x=GetRoot(a);
    int y=GetRoot(b);
    if(x!=y)
        vis[x]=y;
}
int main()
{
    int N,M,k,x,y;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        vis[i]=i;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&k,&x);
        for(int j=1;j<k;j++)
        {
            scanf("%d",&y);
            Join(x,y);
        }
    }
    int maxn=0;
    for(int i=1;i<=N;i++)
    {
        int t=GetRoot(i);
        root[t]++;
        if(root[t]>maxn) maxn=root[t];
    }
    printf("%d\n",maxn);
    return 0;
}

