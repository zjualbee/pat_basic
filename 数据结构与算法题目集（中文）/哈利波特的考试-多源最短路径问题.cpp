#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define N 500
#define INF 99999999
int map[N][N];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=INF;
        }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
        map[b][a]=c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
            }
    int index=0;
    int min=INF;
    int max;
    for(int i=1;i<=n;i++)
    {
        max=0;
        for(int j=1;j<=n;j++)
        {
            if(map[i][j]>max)
                max=map[i][j];
        }
        if(max<min)
        {
            min=max;
            index=i;
        }
    }
    if(index==0)
        printf("0\n");
    else
        printf("%d %d\n",index,min);
    return 0;
}
