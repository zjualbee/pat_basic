#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
using namespace std;
struct customer
{
    string name;
    int arrive_t;
    int solve_p;
};
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    map<string,int> circles;
    int i,j,num_circle;
    string ntmp;
    for(i=0;i<M;i++)
    {
        scanf("%d",&num_circle);
        for(j=0;j<num_circle;j++)
        {
            cin>>ntmp;
            circles[ntmp]=i+1;
        }
    }
    vector<customer> persons;
    customer ctmp;
    for(i=0;i<N;i++)
    {
        cin>>ctmp.name>>ctmp.arrive_t>>ctmp.solve_p;
        if(ctmp.solve_p>60)
            ctmp.solve_p=60;
        persons.push_back(ctmp);
    }
    int ans=0,time=persons[0].arrive_t+persons[0].solve_p;
    queue<customer> q;
    vector<int> vis(N,0);
    q.push(persons[0]);
    vis[0]=1;
    int curpos=0;
    while(!q.empty())
    {
        ctmp=q.front();
        cout<<ctmp.name<<endl;
        q.pop();
        bool flag=false;
        if(circles.find(ctmp.name)!=circles.end()){
            int cur=circles[ctmp.name];
            for(i=curpos;i<N;i++)
            {
                if(vis[i])
                    continue;
                if(persons[i].arrive_t>time)
                    break;
                if(circles[persons[i].name]==cur)
                {
                    q.push(persons[i]);
                    vis[i]=1;
                    curpos=i;
                    flag=true;
                    ans+=time-persons[i].arrive_t;
                    time+=persons[i].solve_p;
                    break;
                }
            }
        }
        if(!flag)
        {
            for(i=1;i<N;i++)
            {
                if(vis[i])
                    continue;
                q.push(persons[i]);
                vis[i]=1;
                curpos=i;
                ans+=max(0,time-persons[i].arrive_t);
                if(persons[i].arrive_t>time) time=persons[i].arrive_t;
                time+=persons[i].solve_p;
                break;
            }
        }
    }
    printf("%.1f\n",1.0*ans/N);
    
    return 0;
}
