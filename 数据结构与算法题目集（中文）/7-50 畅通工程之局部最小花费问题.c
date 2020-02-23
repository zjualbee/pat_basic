#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define maxn 5000
int f[maxn];
set<int> st;
struct road
{
    int u,v;
    int cost;
    int flag;
    bool operator < (const road &a) const
    {
        if(flag==a.flag)
            return cost<a.cost;
        else
            return flag>a.flag;
    }
};
int find(int x)
{
    if(f[x]==x)
        return x;
    else
        return f[x]=find(f[x]);
}
int main()
{
    int N;
    scanf("%d",&N);
    vector<road> Graph;
    int num=N*(N-1)/2;
    road r;
    for(int i=0;i<=N;i++)
        f[i]=i;
    for(int i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&r.u,&r.v,&r.cost,&r.flag);
        Graph.push_back(r);
    }
    sort(Graph.begin(),Graph.end());
    
    int ans=0;
    for(int i=0;i<num;i++)
    {
        int start=find(Graph[i].u);
        int end=find(Graph[i].v);
        st.insert(Graph[i].u);
        st.insert(Graph[i].v);
        if(Graph[i].flag==1)
            f[start]=end;
        else if(start!=end)
        {
            ans+=Graph[i].cost;
            f[start]=end;
        }
        if(st.size()==N) break;
    }
    printf("%d\n",ans);
    return 0;
}
