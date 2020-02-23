#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        queue<int> a,b,c;
        int tmp,flag=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            if(tmp%2!=0)
                a.push(tmp);
            else
                b.push(tmp);
        }
        while(!a.empty() && !b.empty())
        {
            tmp=a.front();
            a.pop();
            c.push(tmp);
            if(!a.empty())
            {
                tmp=a.front();
                a.pop();
                c.push(tmp);
            }
            tmp=b.front();
            b.pop();
            c.push(tmp);
        }
        while(!a.empty())
        {
            tmp=a.front();
            a.pop();
            c.push(tmp);
        }
        while(!b.empty())
        {
            tmp=b.front();
            b.pop();
            c.push(tmp);
        }
        while(!c.empty())
        {
            if(flag==0){
                printf("%d",c.front());
                c.pop();
                flag=1;
            }
            else
            {
                printf(" %d",c.front());
                c.pop();
            }
        }
    }
    return 0;
}
