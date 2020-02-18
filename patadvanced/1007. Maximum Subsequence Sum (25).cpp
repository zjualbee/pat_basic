//1007. Maximum Subsequence Sum (25)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<int> m;
		int temp;
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
			if(thisSum<0)
			{
				thisSum=0;
				if(i!=n-1)
					curleft=m[i+1];
			}
		}
		if(maxSum==-1)
			maxSum=0;
		cout<<maxSum<<" "<<start<<" "<<end<<endl;
	}
	return 0;
}