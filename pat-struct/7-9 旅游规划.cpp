#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
struct ENode
{
    int next;
    int dis;
    int fee;
};
#define N 501
#define INF 66666666
int n,m,v,d;
int Know[N];//flag of shortest path
int Dist[N];//shortest path
int Pay[N];//minimum fee
vector<ENode> map[501];

int main()
{
    scanf("%d %d %d %d",&n,&m,&v,&d);
    int i,j;
    ENode temp;
    int newp;
    if(n==0 && m==0)
        return 0;
    for(i=0;i<=n;i++)//why is the equal
    {
        map[i].clear();
        Dist[i]=-1;
        Know[i]=0;
        Pay[i]=0;
    }
    for(i=0;i<m;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        temp.next=b;
        temp.dis=c;
        temp.fee=d;
        map[a].push_back(temp);
        temp.next=a;
        map[b].push_back(temp);
    }
    int next,min,cost;
    
    Know[v]=1;
    Dist[v]=0;
    newp=v;
    for(i=1;i<n;i++)
    {
        for(j=0;j<map[newp].size();j++)
        {
            next=map[newp][j].next;
            cost=map[newp][j].fee;
            min=map[newp][j].dis;
            if(Know[next]==1) continue;
            if(Dist[next]==-1 || Dist[next]>Dist[newp]+min || ((Dist[next]==Dist[newp]+min)&&(Pay[next]>Pay[newp]+cost)))
            {
                Dist[next]=Dist[newp]+min;
                Pay[next]=Pay[newp]+cost;
            }
        }
        int minx=INF;
        for(j=0;j<=n;j++)
        {
            if(Know[j]==1) continue;
            if(Dist[j]==-1) continue;
            if(Dist[j]<minx)
            {
                minx=Dist[j];
                newp=j;
            }
        }
        Know[newp]=1;
    }
    printf("%d %d\n",Dist[d],Pay[d]);
    return 0;
}
