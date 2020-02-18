//1019. Êý×ÖºÚ¶´ (20)
#include<iostream>
using namespace std;
struct fm
{
	int digit[4];
};
fm format(int num);
int big(int num);
int small(int num);
void display(int a);
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		if(n<10000 && n>0)
		{
			int a=0,b=0;
			do
			{
				a=big(n);
				b=small(n);
				n=a-b;
				display(a);
				cout<<" - ";
			    display(b);
				cout<<" = ";
				display(n);
				cout<<endl;				
				if(n%1111==0)
					break;
			}while(n!=6174);
		}
	}
	return 0;
}
fm format(int num)
{
	fm s;
	int i=0,j=0;
	for(i=0;i<4;i++)
	{
		s.digit[i]=num%10;
		num/=10;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3-i;j++)
		{
			if(s.digit[j]<s.digit[j+1])
			{
				int temp;
				temp=s.digit[j];
				s.digit[j]=s.digit[j+1];
				s.digit[j+1]=temp;
			}
		}
	}
	return s;
}
int big(int num)
{
	int res=0;
	fm t=format(num);
	for(int i=0;i<4;i++)
	{
		res=10*res+t.digit[i];
	}
	return res;
}
int small(int num)
{
	int res=0;
	fm t=format(num);
	for(int i=3;i>=0;i--)
	{
		res=10*res+t.digit[i];
	}
	return res;
}
void display(int a)
{
	if(a>=1000)
		cout<<a;
	else if(a>=100)
		cout<<"0"<<a;
	else if(a>=10)
		cout<<"00"<<a;
	else if(a>=0)
		cout<<"000"<<a;
}