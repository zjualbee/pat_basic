//00-вт╡Б4. Have Fun with Numbers (20)
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string doubleNumber(string num)
{
	int n=num.size();
	string res="";
	int carry=0,sum;
	for(int i=n-1;i>=0;i--)
	{
		sum=(num[i]-'0')*2+carry;
		res.insert(res.begin(),sum%10+'0');
		carry=sum/10;
	}
	if(carry)
		res.insert(res.begin(),carry+'0');
	return res;
}

int main()
{
	string a,b;
	while((cin>>a)!=NULL)
	{
		string b = doubleNumber(a);
		string c=b;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(a==b)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		cout<<c<<endl;
	}
	return 0;
}