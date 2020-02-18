#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MaxVertexNum 10005

typedef struct ENode *PtrToENode;
struct ENode
{
    int v1,v2;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
    int NumN;
    int NumE;
    int G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

int N,E;
MGraph Graph;
int vis[MaxVertexNum];
int cnt;
void BFS(int id);

int main()
{
    scanf("%d %d",&N,&E);
    
    Edge EN;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->NumN = N;
    Graph->NumE = E;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            Graph->G[i][j]=0;
            Graph->G[j][i]=0;
        }
    if(Graph->NumE)
    {
        EN=(Edge)malloc(sizeof(struct ENode));
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&EN->v1,&EN->v2);
            Graph->G[EN->v1-1][EN->v2-1]=1;
            Graph->G[EN->v2-1][EN->v1-1]=1;
        }
    }
    for(int i=0;i<N;i++)
    {
        cnt=0;
        for(int j=0;j<N;j++)
            vis[j]=0;
        vis[i]=1;
        BFS(i);
        double ans=cnt*1.0/N;
        printf("%d: %.2f%%\n",i+1,ans*100);
    }
    return 0;
}

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
            for(int j=0;j<N;j++)
            {
                if(Graph->G[j][xx]==1 && vis[j]==0)
                {
                    vis[j]=1;
                    cnt++;
                    Q.push(j);
                }
            }
        }
    }
}
