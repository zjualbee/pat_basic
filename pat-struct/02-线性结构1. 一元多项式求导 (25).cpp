//02-线性结构1. 一元多项式求导 (25)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	struct num
	{
		int xi;
		int zhi;
	};
	vector<num> a;
	num temp;
	char ch='s';
	while(ch!='\n')
	{
		cin>>temp.xi>>temp.zhi;
		a.push_back(temp);
		ch=getchar();
	}
	int flag=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i].zhi!=0)
		{
			if(!flag)
			{
				flag=1;
				cout<<a[i].xi*a[i].zhi<<" "<<a[i].zhi-1;
			}
			else
			    cout<<" "<<a[i].xi*a[i].zhi<<" "<<a[i].zhi-1;
		}
	}
	if(!flag)
		cout<<"0 0"<<endl;
	return 0;
}