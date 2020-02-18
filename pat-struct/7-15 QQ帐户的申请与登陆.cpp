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
        map<long long,string> mp;
        long long s;
        char type;
        string pwd;
        for(int i=0;i<n;i++)
        {
            cin>>type>>s>>pwd;
            if(type=='N')
            {
                if(mp.find(s)==mp.end())
                {
                    mp[s]=pwd;
                    printf("New: OK\n");
                }
                else
                {
                    printf("ERROR: Exist\n");
                }
            }
            else if(type=='L')
            {
                if(mp.find(s)!=mp.end())
                {
                    if(mp.find(s)->second==pwd)
                        printf("Login: OK\n");
                    else
                        printf("ERROR: Wrong PW\n");
                }
                else
                    printf("ERROR: Not Exist\n");
            }
        }
    }
    return 0;
}
