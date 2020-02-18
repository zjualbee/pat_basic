//结构-06. 复数四则运算(15)
#include<stdio.h>
struct fushu
{
	double real;
	double virt;
};
void disEquation(fushu &num1,fushu &num2,char ch);
void disResult(fushu &num1,fushu &num2,char ch);
int main()
{
	double a1,b1,a2,b2;
	scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);

	fushu n1,n2;
	n1.real=a1;
	n1.virt=b1;
	n2.real=a2;
	n2.virt=b2;
	disEquation(n1,n2,'+');
	disResult(n1,n2,'+');
	disEquation(n1,n2,'-');
	disResult(n1,n2,'-');
	disEquation(n1,n2,'*');
	disResult(n1,n2,'*');
	disEquation(n1,n2,'/');
	disResult(n1,n2,'/');

	return 0;
}
void disEquation(fushu &num1,fushu &num2,char ch)
{
	if(num1.real>-0.05&&num1.real<=0)
		num1.real=0;
	if(num1.virt>-0.05&&num1.virt<=0)
		num1.virt=0;
	if(num2.real>-0.05&&num2.real<=0)
		num2.real=0;
	if(num2.virt>-0.05&&num2.virt<=0)
		num2.virt=0;

	if(num1.virt<0)
		printf("(%.1f%.1fi)",num1.real,num1.virt);
	else
		printf("(%.1f+%.1fi)",num1.real,num1.virt);

	switch(ch)
	{
	case'+':printf(" + ");break;
	case'-':printf(" - ");break;
	case'*':printf(" * ");break;
	case'/':printf(" / ");break;
	default:break;
	}

	if(num2.virt<0)
		printf("(%.1f%.1fi) = ",num2.real,num2.virt);
	else
		printf("(%.1f+%.1fi) = ",num2.real,num2.virt);
}
void disResult(fushu &num1,fushu &num2,char ch)
{
	fushu res;
	switch(ch)
	{
	case'+':
		{
			res.real=num1.real+num2.real;
			res.virt=num1.virt+num2.virt;
			break;
		}
	case'-':
		{
			res.real=num1.real-num2.real;
			res.virt=num1.virt-num2.virt;
			break;
		}
	case'*':
		{
			res.real=num1.real*num2.real-num1.virt*num2.virt;
			res.virt=num1.real*num2.virt+num2.real*num1.virt;
			break;
		}
	case'/':
		{
			res.real=(num1.real*num2.real+num1.virt*num2.virt)/(num2.real*num2.real+num2.virt*num2.virt);
			res.virt=(num2.real*num1.virt-num1.real*num2.virt)/(num2.real*num2.real+num2.virt*num2.virt);
			break;
		}
	default:break;
	}

	if(res.real>-0.05&&res.real<=0 || res.real>0&&res.real<0.05)
		res.real=0;
	if(res.virt>-0.05&&res.virt<=0 || res.virt>0&&res.virt<0.05)
		res.virt=0;

	if(res.real==0 && res.virt==0)
		printf("%.1f\n",res.real);
	else if(res.real==0 && res.virt!=0)
		printf("%.1fi\n",res.virt);
	else if(res.real!=0 && res.virt==0)
		printf("%.1f\n",res.real);
	else
	{
		if(res.virt<0)
			printf("%.1f%.1fi\n",res.real,res.virt);
		else
			printf("%.1f+%.1fi\n",res.real,res.virt);
	}
}