//03-树1. 二分法求多项式单根(20)
#include<iostream>
#include<stdio.h>
using namespace std;
double a3=0,a2=0,a1=0,a0=0;
double cal(double x)
{
	return a3*x*x*x+a2*x*x+a1*x+a0;
}
int main()
{
	while((cin>>a3>>a2>>a1>>a0)!=NULL)
	{
		double a,b;
		cin>>a>>b;
		double mid;
		if(cal(a)==0)
			printf("%.2f",a);
		else if(cal(b)==0)
			printf("%.2f",b);
		else
		{
		while(b-a>0.001||b-a<-0.001)
		{
			if(cal(a)*cal(b)<0)
			{
				mid=(a+b)/2;
				double resultmid=cal(mid);
				if(resultmid==0)
				{
					printf("%.2f\n",mid);
					return 0;
				}
				else if(resultmid*cal(a)>0)
				{
					a=mid;
					continue;
				}
				else
				{
					b=mid;
					continue;
				}	
			}
		}
		if(cal(mid)!=0)
			printf("%.2f\n",mid);
		}
	}
	return 0;
}