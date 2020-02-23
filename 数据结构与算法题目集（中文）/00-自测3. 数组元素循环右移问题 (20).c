//00-自测3. 数组元素循环右移问题 (20)
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	int num[100];
	while((cin>>n>>m)!=NULL)
	{
		int flag=0;
		m = m % n;
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=n-m;i<n;i++)
		{
			if(!flag)
			{
				cout<<num[i];
				flag=1;
			}
			else
				cout<<" "<<num[i];
		}
		for(int i=0;i<n-m;i++)
		{
			if(!flag)
			{
				cout<<num[i];
				flag=1;
			}
			else
				cout<<" "<<num[i];
		}
		cout<<endl;
	}
	return 0;
}