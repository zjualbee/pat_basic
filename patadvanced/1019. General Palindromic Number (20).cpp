//1019. General Palindromic Number (20)
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long n,b;
	while((cin>>n>>b)!=NULL)
	{
		vector<long> digit;
		long temp;
		while(n!=0)
		{
			temp=n%b;
			digit.push_back(temp);
			n=n/b;
		}
		int len=digit.size(),flag=0;
		for(int i=0;i<(len*1.0)/2;i++)
		{
			if(digit[i]!=digit[len-1-i])
				flag=1;
		}
		if(flag==1)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		for(int i=len-1;i>=0;i--)
		{
			if(i!=len-1)
				cout<<" ";
			cout<<digit[i];
		}
		if(len==0)
			cout<<"0";
		cout<<endl;
	}
	return 0;
}