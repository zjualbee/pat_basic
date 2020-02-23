#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int vis[1000]={0};
int flag=0,judge=0;
void DFS(int x,int n, vector<vector<int> > G)
{
    vis[x]=1;
    if(flag==0)
        flag=1;
    else
        printf(" ");
    printf("%d",x);
    judge++;
    
    for(int i=0;i<G[x].size();i++)
    {
        if(vis[G[x][i]]==0){
            DFS(G[x][i],n,G);
            printf(" %d",x);
        }
    }
}
int main()
{
    int N,M,S;
    scanf("%d %d %d",&N,&M,&S);
    vector<vector<int> > G;
    vector<int> tmp;
    int tmp1,tmp2;
    for(int i=0;i<=N;i++)
        G.push_back(tmp);
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&tmp1,&tmp2);
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
    }
    for(int i=0;i<=N;i++)
        sort(G[i].begin(),G[i].end());
    DFS(S,N,G);
    
    if(judge<N)
        printf(" 0\n");
    return 0;
}
