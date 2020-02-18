//1041. Be Unique (20)
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		if(n>=1&&n<=10000)
		{
			int temp;
			unordered_map<int,int> num;
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				if(num.find(temp)!=num.end())
					++num.find(temp)->second;
				else
					num.insert(make_pair(temp,1));
			}
			int flag=0;
			for(unordered_map<int,int>::iterator it=num.begin();it!=num.end();++it)
			{
				if(it->second==1)
				{
					flag=1;
					cout<<it->first<<endl;
					break;
				}
			}
			if(flag==0)
				cout<<"None"<<endl;
		}
	}
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<int> v;
		int i,x,f=0;
		int array[10000]={0};
		for(i=0;i<n;i++)
		{
			cin>>x;
			array[x]++;
			v.push_back(x);
		}
		for(i=0;i<v.size();i++)
		{
			if(array[v[i]]==1)
			{
				f=1;
				cout<<v[i]<<endl;
				break;
			}
		}
		if(f==0)
			cout<<"None"<<endl;
	}
	return 0;
}