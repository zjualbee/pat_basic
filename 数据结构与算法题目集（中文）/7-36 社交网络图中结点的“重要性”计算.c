#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define INF 10001
int f[INF];
int find(int x)
{
    if(f[x]==x) return x;
    else
        return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    int a=find(x),b=find(y);
    if(a!=b)
        f[a]=b;
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int **Dis=(int**)malloc(sizeof(int*)*(N));
    for(int i=0; i<N; i++) {
        Dis[i]=(int*)malloc(sizeof(int)*(N));
        for(int j=0; j<N; j++) {
            if(i==j)
                Dis[i][j]=0;
            else
                Dis[i][j]=INF;
        }
    }
    int i,j,k;
    for(i=0;i<M;i++)
    {
        scanf("%d%d",&j,&k);
        j--;k--;
        merge(j,k);
        Dis[j][k]=1;
        Dis[k][j]=1;
    }
    
    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                if(Dis[i][j]>Dis[i][k]+Dis[k][j])
                    Dis[i][j]=Dis[i][k]+Dis[k][j];
    
    scanf("%d",&k);
    int num,flag=1;
    set<int> s;
    for(i=0;i<N;i++)
        s.insert(find(i));
    if(s.size()>1)
        flag=0;
    for(i=0;i<k;i++)
    {
        scanf("%d",&num);
        num--;
        int sum=0;
        for(j=0;j<N;j++){
            if(Dis[num][j]==INF)
            {
                flag=0;
                break;
            }
            else
                sum+=Dis[num][j];
        }
        if(flag!=0)
            printf("Cc(%d)=%.2lf\n",num+1,(N-1)*1.0/sum);
        else
            printf("Cc(%d)=0.00\n",num+1);
    }
    return 0;
}
