#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    getchar();
    vector<string> name(N);
    map<string,string> father;
    for(int i=0;i<N;i++)
    {
        string s;
        getline(cin,s,'\n');
        int cnt=count(s.begin(),s.end(),' ');
        if(cnt==0)
        {
            father[s]="no";
            name[0]=s;
        }
        else{
            s=s.substr(cnt);
            father[s]=name[cnt/2-1];
            name[cnt/2]=s;
        }
    }
    for(int i=0;i<M;i++)
    {
        string a,b,c,d;
        cin>>a>>b>>b>>c>>b>>d;
        switch(c[0])
        {
            case 'p':
                swap(a,d);
            case 'c':
            {
                if(father[a]==d)
                    printf("True\n");
                else
                    printf("False\n");
                break;
            }
            case 's':
            {
                if(father[a]==father[d])
                    printf("True\n");
                else
                    printf("False\n");
                break;
            }
            case 'a':
                swap(a,d);
            case 'd':
            {
                while(father[a]!=d && father[a]!="no") a=father[a];
                if(father[a]=="no")
                    printf("False\n");
                else
                    printf("True\n");
                break;
            }
        }
    }
    return 0;
}
