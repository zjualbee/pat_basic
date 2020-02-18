//1015. µÂ²ÅÂÛ (25)
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct stu
{
	int id;
	int de;
	int cai;
	bool operator<(const stu &b) const
	{ 
		if((de+cai)!=(b.de+b.cai))
			return (de+cai)>(b.de+b.cai);
		else
		{
			if(de!=b.de)
				return de>b.de;
			else
				return id<b.id;
		}
	} 
};
int N,L,H;

int main()
{
	while((cin>>N>>L>>H)!=NULL)
	{
		if(N<=100000 && L>=60 && H<100)
		{
			int count=0;
			vector<stu> v1,v2,v3,v4;
			stu m;
			for(int i=0;i<N;i++)
			{
				cin>>m.id>>m.de>>m.cai;
				if(m.de>=L && m.cai>=L)
				{
					++count;
					if(m.de>=H && m.cai>=H)
						v1.push_back(m);
					else if(m.de>=H &&m.cai<H)
						v2.push_back(m);
					else if(m.de<H && m.cai<H && m.de>=m.cai)
						v3.push_back(m);
					else
						v4.push_back(m);
				}
			}
			sort(v1.begin(),v1.end());
			sort(v2.begin(),v2.end());
			sort(v3.begin(),v3.end());
			sort(v4.begin(),v4.end());
			printf("%d\n",count);
			for(int i=0;i<v1.size();i++)
				printf("%d %d %d\n",v1[i].id,v1[i].de,v1[i].cai);
			for(int i=0;i<v2.size();i++)
				printf("%d %d %d\n",v2[i].id,v2[i].de,v2[i].cai);
			for(int i=0;i<v3.size();i++)
				printf("%d %d %d\n",v3[i].id,v3[i].de,v3[i].cai);
			for(int i=0;i<v4.size();i++)
				printf("%d %d %d\n",v4[i].id,v4[i].de,v4[i].cai);
		}
	}
	return 0;
}