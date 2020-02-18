//1008. 数组元素循环右移问题 (20)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int m,n;
	vector<int> num;
	while((cin>>n)!=NULL)
	{
		cin>>m;
		if(m>=0&&n>=1&&n<=100)
		{
			m%=n;
			int temp;
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				num.push_back(temp);
			}
			int flag=0;
			for(int i=n-m;i<n;i++)
			{
				if(flag==0)
					flag=1;
				else
					cout<<" ";
				cout<<num[i];
			}
			for(int i=0;i<n-m;i++)
			{
				if(flag==0)
					flag=1;
				else
					cout<<" ";
				cout<<num[i];
			}
		}
	}
}