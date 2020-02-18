//1016. ²¿·ÖA+B (15)
#include<iostream>
using namespace std;
int main()
{
	char str1[10],str2[10];
	long int sum1=0,sum2=0;
	int a,b,i=0,j=0;
	cin>>str1>>a>>str2>>b;
	char *p=str1,*q=str2;
	while(*p!='\0')
	{
		if((*p-'0')==a)
		{
			sum1=sum1*10+a;
			++i;
		}
		++p;
	}
	while(*q!='\0')
	{
		if((*q-'0')==b)
		{
			sum2=sum2*10+b;
			++j;
		}
		++q;
	}
	cout<<sum1+sum2<<endl;
	return 0;
}
