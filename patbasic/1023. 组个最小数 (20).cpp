//1023. 组个最小数 (20)
#include<iostream>
using namespace std;
int digit[10];
int main()
{
	for(int i=0;i<10;i++)
		cin>>digit[i];
	if(digit[0]!=0)
	{
		for(int i=1;i<10;i++)
		{
			if(digit[i]!=0)
			{
				cout<<i;
				--digit[i];
				break;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		if(digit[i]!=0)
		{
			while(digit[i]!=0)
			{
				cout<<i;
				--digit[i];
			}
		}
	}
	return 0;
}