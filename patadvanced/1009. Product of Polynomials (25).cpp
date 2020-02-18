//1009. Product of Polynomials (25)
#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
struct po
{
	int zhi;
	double xi;
};
int main()
{
	map<int,double> e,f;
	po temp;
	int n1;
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>temp.zhi>>temp.xi;
		e.insert(make_pair(temp.zhi,temp.xi));
	}
	int n2;
	cin>>n2;
	map<int,double>::iterator it;
	for(int i=0;i<n2;i++)
	{
		cin>>temp.zhi>>temp.xi;
		for(it=e.begin();it!=e.end();++it)
		{
			if(f.find(it->first+temp.zhi)!=f.end())
				f.find(it->first+temp.zhi)->second+=it->second*temp.xi;
			else
				f.insert(make_pair(it->first+temp.zhi,it->second*temp.xi));
		}
	}
	int count=0,cc=0;
	for(it=f.begin();it!=f.end();++it)
	{
		++cc;
		if(it->second<=0&&it->second>-0.05)
			it->second=0;
		if(it->second!=0)
			++count;
	}
	cout<<count<<" ";
	int flag=0;
	it=f.end();
	while(cc!=0)
	{
		--it;
		--cc;
		if(it->second!=0)
		{
			if(flag==0)
				flag=1;
			else
				cout<<" ";
			printf("%d %.1f",it->first,it->second);
		}
	}
	cout<<endl;
	return 0;
}