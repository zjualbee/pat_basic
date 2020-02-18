//1054. The Dominant Color (20)
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,int> count;
	int m,n,temp;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			if(count.find(temp)!=count.end())
				count.find(temp)->second++;
			else
				count.insert(make_pair(temp,1));
		}
	}
	for(map<int,int>::iterator it=count.begin();it!=count.end();++it)
	{
		if(it->second>m*n/2)
		{
			cout<<it->first<<endl;
			break;
		}
	}
	return 0;
}