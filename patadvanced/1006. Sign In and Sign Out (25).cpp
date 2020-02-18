//1006. Sign In and Sign Out (25)
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
struct person
{
	char id[16];
	char begin[10];
	char end[10];
};
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<person> m;
		person temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp.id>>temp.begin>>temp.end;
			m.push_back(temp);
		}
		int min=0,max=0;
		for(int i=0;i<n;i++)
		{
			if(strcmp(m[min].begin,m[i].begin)>0)
				min=i;
			if(strcmp(m[max].end,m[i].end)<0)
				max=i;
		}
		cout<<m[min].id<<" "<<m[max].id<<endl;
	}
}