//1081. Rational Sum (20)
#include<iostream>
#include<stdio.h>
using namespace std;
struct num
{
	int n;
	int d;
	num(int a=0,int b=1):n(a),d(b){}
};
num yuefen(num& m)
{
	num res=m;
	int c;
	if(res.n<0)
		res.n*=-1;
	if(res.n!=0)
	{
		if(res.n%res.d==0)
		{
			m.n=m.n/m.d;
			m.d=1;
		}
		else
		{
			while(res.n%res.d!=0)
			{
				c=res.n%res.d;
				res.n=res.d;
				res.d=c;
			}
			m.n/=c;
			m.d/=c;
		}
	}
	return m;	
}
void display(num& a)
{
	if(a.n<0)
	{
		cout<<"-";
		a.n*=-1;
	}
	
	int z=a.n/a.d;
	int y=a.n%a.d;
	if(z!=0)
	{
		cout<<z;
		if(y!=0)
			cout<<" "<<y<<"/"<<a.d;
	}
	else 
	{
		if(y!=0)
			cout<<y<<"/"<<a.d;
		else
			cout<<"0";
	}
	cout<<endl;
}
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		num sum,temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d/%d",&temp.n,&temp.d);
			sum.n=sum.n*temp.d+sum.d*temp.n;
			sum.d=sum.d*temp.d;
			sum=yuefen(sum);
		}
		display(sum);
	}
	return 0;
}