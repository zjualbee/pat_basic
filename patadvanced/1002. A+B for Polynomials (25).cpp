//1002. A+B for Polynomials (25)
#include<iostream>
#include<stdio.h>
using namespace std;
#include<map>
int main()
{
	int n1,n2;
	map<int,double> a;
	map<int,double>::iterator it;
	int exponent;
	double coefficient;
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>exponent>>coefficient;
		a.insert(make_pair(exponent,coefficient));
	}
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cin>>exponent>>coefficient;
		if(a.find(exponent)!=a.end())
		{
			it=a.find(exponent);
			it->second+=coefficient;
		}
		else
			a.insert(make_pair(exponent,coefficient));
	}
	int count=0;
	for(it=a.begin();it!=a.end();++it)
	{
		if(it->second!=0)
			++count;
	}
	if(count>0)
	{
		it=a.end();
		cout<<count;
		while(count>0)
		{
			--it;				
			if(it->second!=0)
			{
				if(it->second>-0.05&&it->second<=0)
					it->second=0;
				--count;
				printf(" %d %.1f",it->first,it->second);
			}
		}
	}
	else
		printf("0\n");
	return 0;
}