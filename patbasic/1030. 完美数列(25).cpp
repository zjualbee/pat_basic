//1030. 完美数列(25)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	unsigned long long p;
	unsigned int n;
	while((cin>>n>>p)!=NULL)
	{
		vector<unsigned long long> num;
		unsigned long long temp,max;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp>0&&temp<=1000000000)
			    num.push_back(temp);
		}
		sort(num.begin(),num.end());
		temp=num[0]*p;
		int j=0,count=0;
		for(int i=0;i<num.size();i++)
		{
			while(j<i&&temp<num[i])
				temp=num[++j]*p;
			if(count<i-j+1)
				count=i-j+1;
		}
		cout<<count<<endl;
	}
	return 0;
}