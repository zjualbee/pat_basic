#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector< vector<int>> G;
int n,m;
int cnt;
vector<int> vis;

void BFS(int id)
{
    queue<int> Q;
    Q.push(id);
    vis[id]=1;
    cnt++;
    for(int deep=0;deep<6;deep++)
    {
        vector<int> v;
        while(Q.size()>0)
        {
            int tmp=Q.front();
            Q.pop();
            v.push_back(tmp);
        }
        for(int i=0;i<v.size();i++)
        {
            int xx=v[i];
            int len=G[xx].size();
            for(int j=0;j<len;j++)
            {
                int index=G[xx][j];
                if(vis[index]==0)
                {
                    vis[index]=1;
                    cnt++;
                    Q.push(index);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    vector<int> tmp;
    for(int i=0;i<=n;i++)
        G.push_back(tmp);
    for(int j=0;j<=n;j++)
        vis.push_back(0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        for(int j=0;j<=n;j++)
            vis[j]=0;
        BFS(i);
        double ans=cnt*1.0/n;
        printf("%d: %.2f%%\n",i,ans*100);
    }
    return 0;
}
