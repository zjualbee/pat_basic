//1069. The Black Hole of Numbers (20)
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
int transfer(int num)
{
	vector<int> digit;
	int i;
	while(num!=0)
	{
		digit.push_back(num%10);
		num/=10;
	}
	int l=digit.size();
	for(i=0;i<4-l;i++)
		digit.push_back(0);
	sort(digit.begin(),digit.end());
	int min,max;
	min=1000*digit[0]+100*digit[1]+10*digit[2]+digit[3];
	max=1000*digit[3]+100*digit[2]+10*digit[1]+digit[0];
	printf("%04d - %04d = %04d\n",max,min,max-min);
	return max-min;
}
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		if(n>0&&n<10000)
		{
			do
			{
				if(n%1111==0)
				{
					printf("%04d - %04d = %04d\n",n,n,n-n);
					break;
				}
				n=transfer(n);
			}while(n!=6174);
		}
	}
}