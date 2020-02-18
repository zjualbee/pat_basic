//1024. Palindromic Number (25)
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string add(string s1,string s2)
{
	string result="";
	int len1=s1.size();
	int len2=s2.size();
	int carry=0,sum;
	for(int i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
	{
		if(i<0)
			sum=s2[j]-'0';
		else if(j<0)
			sum=s1[i]-'0';
		else
			sum=s1[i]-'0'+s2[j]-'0';
		sum+=carry;
		result.insert(result.begin(),sum%10+'0');
		carry=sum/10;
	}
	if(carry)
		result.insert(result.begin(),carry+'0');
	return result;
}
int main()
{
	string n;
	int k;
	while((cin>>n>>k)!=NULL)
	{
		int i=0,flag=0;
		for(i=0;i<k;i++)
		{
			string n2=n;
			reverse(n.begin(),n.end());
			if(n==n2)
				break;
			else
				n=add(n,n2);
		}
		if(flag==0)
		{
			cout<<n<<endl;
			cout<<i<<endl;
		}
	}
}