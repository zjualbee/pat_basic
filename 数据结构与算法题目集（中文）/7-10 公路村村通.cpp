#include<cstdio>
#include<iostream>
using namespace std;

#define N 1005
#define INF 99999999
int map[N][N];
int Top;
int Prime()
{
    int sumcost=0,min;
    int Lowcost[N]={0};
    int i,j,k;
    for(i=1;i<=Top;i++)
        Lowcost[i]=map[1][i];
    Lowcost[1]=0;
    for(i=2;i<=Top;i++)
    {
        Lowcost[i]=map[1][i];
    }
    for(i=2;i<=Top;i++)
    {
        min=INF;
        k=0;
        for(j=2;j<=Top;j++)
        {
            if(Lowcost[j]!=0 && Lowcost[j]<min)
            {
                min=Lowcost[j];
                k=j;
            }
        }
        if(k==0)
            return -1;
        Lowcost[k]=0;
        sumcost+=min;
        for(j=2;j<=Top;j++)
        {
            if(Lowcost[j]!=0 && map[k][j]<Lowcost[j])
                Lowcost[j]=map[k][j];
        }
    }
    return sumcost;
}
int main()
{
    int i,j,m,n;
    int x,y,w;
    scanf("%d %d",&n,&m);
    if(n<=0)
    {
        printf("-1\n");
        return 0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=INF;
        }
    Top=n;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        map[x][y]=w;
        map[y][x]=w;
    }
    printf("%d\n",Prime());
    return 0;
}
