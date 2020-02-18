//1028. ÈË¿ÚÆÕ²é(20)
#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
struct person
{
	char name[6];
	char bir[11];
};
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		if(n>0&&n<=100000)
		{
			vector<person> p;
			person temp,old,young;
			int count=0;
			for(int i=0;i<n;i++)
			{
				cin>>temp.name>>temp.bir;
				if(strcmp(temp.bir,"1814/09/06")>=0 && strcmp(temp.bir,"2014/09/06")<=0)
				{
					p.push_back(temp);
					count++;
				}
			}
			if(p.size()>0)
			{
				old=p[0];
				young=p[0];
				for(int i=1;i<p.size();i++)
				{
					if(strcmp(p[i].bir,old.bir)<0)
					{
						strcpy(old.bir,p[i].bir);
						strcpy(old.name,p[i].name);
					}
					if(strcmp(p[i].bir,young.bir)>0)
					{
						strcpy(young.bir,p[i].bir);
						strcpy(young.name,p[i].name);
					}
				}
				cout<<count<<" "<<old.name<<" "<<young.name<<endl;
			}
			else
				cout<<"0"<<endl;
		}
	}
}
