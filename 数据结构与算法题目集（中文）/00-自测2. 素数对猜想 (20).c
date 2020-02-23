//00-自测2. 素数对猜想 (20)
#include<iostream>
#include<math.h>
using namespace std;
bool prime(int num);
int main()
{
	int n;
	
	while((cin>>n)!=NULL)
	{
		int su=0;
		for(int i=3;i<n-1;i+=2)
		{
			if(prime(i)&&prime(i+2))
				++su;
		}
		cout<<su<<endl;
	}
	return 0;
}
bool prime(int num)
{
	bool result=false;
	if(num==1)
		return false;
	int i;
	for(i=2;i<=sqrt(num*1.0);i++)
		if(num%i==0)
			break;
	if(i>sqrt(num*1.0))
		result = true;
	return result;
}