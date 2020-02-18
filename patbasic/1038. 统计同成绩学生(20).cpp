//1038. 统计同成绩学生(20)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
	int n;
	unordered_map<int,int> num;
	while((cin>>n)!=NULL)
	{
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			unordered_map<int,int>::iterator it=num.find(temp);
			if(it!=num.end())
				it->second++;
			else
				num.insert(make_pair(temp,1));
		}
		int m;
		cin>>m;
		vector<int> check(m);
		for(int i=0;i<m;i++)
			cin>>check[i];
		vector<int> shu(m);
		for(int i=0;i<m;i++)
		{
			unordered_map<int,int>::iterator it2=num.find(check[i]);
			if(it2==num.end())
				shu[i]=0;
			else
				shu[i]=it2->second;
		}
		for(int i=0;i<m;i++)
		{
			if(i==0)
				cout<<shu[i];
			else
			    cout<<" "<<shu[i];
		}
		cout<<endl;
	}
	return 0;
}