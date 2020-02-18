//01-复杂度1. 最大子列和问题(20)
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<int> number;
		int temp,maxsum=0,indexsum=0,index;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			number.push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			indexsum+=number[i];
			if(indexsum>maxsum)
				maxsum=indexsum;
			else if(indexsum<0)
				indexsum=0;
		}
		cout<<maxsum<<endl;
	}
	return 0;
}