//1021. 个位数统计 (15)
#include<iostream>
using namespace std;
int digit[10];
int main()
{
	char num[1000];
	while((cin>>num)!=NULL)
	{
		for(int i=0;i<10;i++)
		    digit[i]=0;
		char *p=num;
		while(*p!='\0')
		{
			digit[*p-'0']++;
			p++;
		}
		for(int i=0;i<10;i++)
		{
			if(digit[i]!=0)
			   cout<<i<<":"<<digit[i]<<endl;
		}
	}
	return 0;
}