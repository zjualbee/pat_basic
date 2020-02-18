#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        map<int,int> mp;
        int tmp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            mp[tmp]++;
        }
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            printf("%d:%d\n",(*it).first,(*it).second);
        }
    }
    return 0;
}
