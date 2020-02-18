//数组-11. 猴子选大王(20)
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	struct monkey
	{
		int id;
		int flag;
	};
	vector<monkey> king;
	monkey temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		temp.id=i;
		temp.flag=1;
		king.push_back(temp);
	}
	int num=n,i=0,k=0;
	while(num>1)
	{
		if(king[i%n].flag==1)
		{
			++k;
			if(k%3==0)
			{
				king[i%n].flag=0;
				--num;
			}
		}
		++i;
	}
	for(i=0;i<king.size();i++)
		if(king[i].flag==1)
			cout<<i+1<<endl;
	return 0;
}