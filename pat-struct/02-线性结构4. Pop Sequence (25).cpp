//02-线性结构4. Pop Sequence (25)
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int check(const vector<int> &num,int m,int n)
{
	stack<int> stk;
	int i=0,j=1;
	while(1)
	{
		while(stk.empty()||stk.top()!=num[i])
		{
			stk.push(j++);
			if(stk.size()==m)
			{
				if(stk.top()==num[i])
				{
					stk.pop();
					i++;
					if(i==n)
					{
						if(stk.empty())
							cout<<"YES"<<endl;
						else
							cout<<"NO"<<endl;
						return 0;
					}
				}
				else
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		if(!stk.empty())
		{
			stk.pop();
			i++;
		}
		if(i==n&&stk.empty())
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
int main()
{
	int m,n,k;
	while((cin>>m>>n>>k)!=NULL)
	{
		vector<int> num(n);
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
				cin>>num[j];
			check(num,m,n);
		}
	}
	return 0;
}