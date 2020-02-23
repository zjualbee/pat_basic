//01-2. Maximum Subsequence Sum (25)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		int temp;
		vector<int> m;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			m.push_back(temp);
		}
		int thisSum=0,maxSum=-1;
		int start=m[0],end=m[n-1];
		int curleft=m[0];
		for(int i=0;i<n;i++)
		{
			thisSum+=m[i];
			if(thisSum>maxSum)
			{
				maxSum=thisSum;
				end=m[i];
				start=curleft;
			}
			else if(thisSum<0)
			{
				thisSum=0;
				if(i!=n-1)
				   curleft=m[i+1];
			}
		}
		if(-1==maxSum)
			maxSum=0;
		cout<<maxSum<<" "<<start<<" "<<end<<endl;
	}
	return 0;
}