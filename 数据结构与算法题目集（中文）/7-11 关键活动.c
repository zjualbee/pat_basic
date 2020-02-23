#include <cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct data
{
    int b,lenth;
};
typedef struct node *Node;
struct node
{
    vector<data> Next;
    int Output;
    vector<data> From;
    int Input;
    node(int x=0,int y=0):Output(x),Input(y){}
};

int TopSort(vector<node> V,int n);

int main()
{
    
    int n,m;
    scanf("%d%d",&n,&m);
    vector<node> V(n+1);
    
    while(m--)
    {
        int disk1,disk2,lenth;
        data t;
        scanf("%d%d%d",&disk1,&disk2,&lenth);
        t.b=disk2;
        t.lenth=lenth;
        V[disk1].Next.push_back(t);
        t.b=disk1;
        V[disk2].From.push_back(t);
    }
    for(int i=1;i<=n;i++)
    {
        V[i].Input=V[i].From.size();
        V[i].Output=V[i].Next.size();
    }
    int Coast =TopSort(V,n);
    return 0;
}

int TopSort(vector<node> V,int n)
{
    vector<int> Earliest(n+1);
    
    while(1)
    {
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(0==V[i].Input)
            {
                flag=1;
                for(int j=0; j<V[i].Next.size(); j++)
                {
                    if(Earliest[V[i].Next[j].b]<Earliest[i]+V[i].Next[j].lenth)
                    {
                        Earliest[V[i].Next[j].b]=Earliest[i]+V[i].Next[j].lenth;
                    }
                    V[V[i].Next[j].b].Input-=1;
                }
                V[i].Input =-1;
            }
        }
        if(!flag)break;
    }
    
    int max=0,index;
    for(int i=1; i<=n; i++)
    {
        if(V[i].Input >0)
        {
            max=0;
            break;
        }
        if(Earliest[i]>max)
        {
            max=Earliest[i];
            index=i;
        }
    }
    printf("%d",max);
    if(max==0)return 0;
    
    vector<int> Latest(n+1,max);
    while(1)
    {
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(0==V[i].Output)
            {
                flag=1;
                for(int j=0; j<V[i].From.size(); j++)
                {
                    if(Latest[V[i].From[j].b]>Latest[i]-V[i].From[j].lenth)
                    {
                        Latest[V[i].From[j].b]=Latest[i]-V[i].From[j].lenth;
                    }
                    V[V[i].From[j].b].Output  -=1;
                }
                V[i].Output   =-1;
            }
        }
        if(!flag)break;
    }
    
    for(int i=1; i<=n; i++)
    {
        //      printf("{%d,%d}",Earliest[i],Latest[i]);
        if(Latest[i]==Earliest[i])
        {
            for(int j=V[i].Next.size()-1; j>=0; j--)
            {
                if(Latest[V[i].Next[j].b]==Latest[i]+V[i].Next[j].lenth )
                {
                    printf("\n%d->%d",i,V[i].Next[j].b);
                }
            }
        }
    }
    return max;
}
