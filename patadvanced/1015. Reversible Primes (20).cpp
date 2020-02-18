//1015. Reversible Primes (20)
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
bool prime(int num)
{
	if(num==1||num==0)
		return false;
	int i;
	for(i=2;i<=sqrt(num*1.0);i++)
	{
		if(num%i==0)
			break;
	}
	if(i>sqrt(num*1.0))
		return true;
	else
		return false;
}
int main()
{
	int n,d;
	cin>>n;
	while(n>0)
	{
		cin>>d;
		vector<int> digit;
		int origin=n;
		int sum=0;
		while(n!=0)
		{
			sum=sum*d+n%d;
			n/=d;
		}

		if(prime(origin)&&prime(sum))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		cin>>n;
	}
	return 0;
}