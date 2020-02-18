//1028. List Sorting (25)
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
int n,c;
struct stu
{
	int id;
	char name[9];
	int grade;
	//Í¬ºÅµÝÔöË³Ðò
	bool operator<(const stu& a) const
	{
		if(c==1)
		{
			return id<a.id;
		}
		else if(c==2)
		{
			if(strcmp(name,a.name)!=0)
			{
				int flag=strcmp(name,a.name);
				if(flag<0)
					return true;
				else
					return false;
			}
			else
				return id<a.id;
		}
		else
		{
			if(grade!=a.grade)
			    return grade<a.grade;
			else
				return id<a.id;
		}
	}
};
int main()
{	
	while((cin>>n>>c)!=NULL)
	{
		stu temp;
		vector<stu> m;
		for(int i=0;i<n;i++)
		{
			cin>>temp.id>>temp.name>>temp.grade;
			m.push_back(temp);
		}
		sort(m.begin(),m.end());
		for(int i=0;i<m.size();i++)
		{
			printf("%06d %s %d\n",m[i].id,m[i].name,m[i].grade);
		}
	}
	return 0;
}