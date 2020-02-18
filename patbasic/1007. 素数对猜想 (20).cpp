//1007. ËØÊı¶Ô²ÂÏë (20)
#include<iostream>
#include<math.h>
using namespace std;
bool prime(int num);
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		int count=0;
		for(int i=2;i<n-1;i++)
		{
			if(prime(i))
			{
				if(prime(i+2))
				{
					count++;
					//cout<<i<<" "<<i+2<<endl;
					i+=1;
				}
			}
		
		}
		cout<<count<<endl;
	}
}
bool prime(int num)
{
	bool res=false;
	if(num==1)
		return false;
	int i;
	for(i=2;i<=sqrt(1.0*num);i++)
		if(num%i==0)
			break;
	if(i>sqrt(1.0*num))
		res=true;

	return res;
}