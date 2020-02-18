#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        map<long long,int> mp;
        long long s,temp;
        int max=0;
        for(int i=0;i<2*n;i++)
        {
            scanf("%lld",&s);
            mp[s]++;
            if(max<mp[s])
                max=mp[s];
        }
        map<long long,int>::iterator it;
        int count=0;
        long long numb;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second == max)
            {
                count++;
                if(count==1)
                    numb=it->first;
            }
        }
        printf("%lld %d",numb,max);
        if(count>1)
            printf(" %d\n",count);
    }
    return 0;
}
