#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int root[1001]={0};
int Find(int X)
{
    if(root[X]==X) return X;
    else
        root[X]=Find(root[X]);
    return root[X];
}
void Union(int root1, int root2)
{
    int a=Find(root1);
    int b=Find(root2);
    if(a!=b)
        root[root1]=root2;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int tmp1,tmp2;
    vector<vector<int> > G;
    vector<int>  tmp;
    for(int i=0;i<=N;i++){
        G.push_back(tmp);
        root[i]=i;
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&tmp1,&tmp2);
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
        Union(tmp1, tmp2);
    }
    int cnt=0;
    int flag=1;
    for(int i=1;i<=N;i++)
    {
        if(Find(i)==i){
            cnt++;
        }
    }
    
    if(cnt==1){
        for(int i=1;i<=N;i++)
        {
            if(G[i].size()%2!=0){
                flag=0;
                break;
            }
        }
    }
    else
        flag=0;
    if(flag)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}
