//1022. D½øÖÆµÄA+B (20)
#include<iostream>
#include<string.h>
void test(int m,int k);
using namespace std;
int main()
{
	int a,b;
	int d;
	while((cin>>a>>b>>d)!=NULL)
	{
		int res=0;
		res=a+b;
		test(res,d);	
	}
	return 0;
}
void test(int m,int k)
{
	if(m/k==0)
		cout<<m;
	else
	{
		test(m/k,k);
		cout<<m%k;
	}
}