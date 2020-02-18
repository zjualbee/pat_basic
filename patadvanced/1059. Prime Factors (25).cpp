//1059. Prime Factors (25)
#include<iostream>
#include<math.h>
#include<map>
using namespace std;
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		if(n==1)
			cout<<"1=1"<<endl;
		else
		{
			map<int,int> m;
			int i;
			int num=n;
			for(i=2;i<=sqrt((double)num);i++)
			{
				if(n%i==0)
				{
					if(m.find(i)!=m.end())
						m.find(i)->second++;
					else
						m.insert(make_pair(i,1));
					n/=i;
					--i;
				}
				if(n==1||i>sqrt((double)num))
					break;
			}
			cout<<num<<"=";
			int count=0;
			for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
			{
				if(it->second==1)
					cout<<it->first;
				else
				    cout<<it->first<<"^"<<it->second;
				++count;
				if(count!=m.size())
					cout<<"*";
			}
			if(m.size()==0)
				cout<<num;
			cout<<endl;
		}
	}
}