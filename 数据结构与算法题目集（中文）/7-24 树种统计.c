#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
string tname;

int main()
{
    int N;
    while(cin>>N)
    {
        getchar();
        map<string,double> num;
        map<string,double>::iterator it;
        for(int i=0;i<N;i++){
            getline(cin,tname,'\n');
            it=num.find(tname);
            if(it!=num.end())
                num[tname]++;
            else
                num.insert(pair<string,double>(tname,1));
        }
        for(it=num.begin();it!=num.end();++it){
            cout<<it->first;
            printf(" %.4f%%\n",it->second/N*100);
        }
    }
    return 0;
}
