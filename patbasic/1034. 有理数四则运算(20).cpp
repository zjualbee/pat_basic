//1034. 有理数四则运算(20)
#include<stdio.h>
using namespace std;
#include<math.h>
struct grade
{
	long long element;
	long long denominator;
	grade(long long e=0,long long d=1):element(e),denominator(d){}
};
void display(grade& a,grade& b,char ch);
void disnum(grade &num);
char operate[4]={'+','-','*','/'};
grade yuefen(grade& num);
int main()
{
	grade num1,num2;
	char c1,c2;
	while((scanf("%lld/%lld %lld/%lld",&num1.element,&num1.denominator,&num2.element,&num2.denominator))!=EOF)
	{
			num1=yuefen(num1);
			num2=yuefen(num2);
			for(int i=0;i<4;i++)
				display(num1,num2,operate[i]);
	}
	return 0;
}
void display(grade& a,grade& b,char ch)
{
	grade res;
	switch(ch)
	{
	case'+':
		{
			res.denominator=a.denominator*b.denominator;
			res.element=a.denominator*b.element+a.element*b.denominator;
			break;
		}
	case'-':
		{
			res.denominator=a.denominator*b.denominator;
			res.element=a.element*b.denominator-a.denominator*b.element;
			break;
		}
	case'*':
		{
			res.denominator=a.denominator*b.denominator;
			res.element=a.element*b.element;
			break;
		}
	case'/':
		{
			res.denominator=a.denominator*b.element;
			res.element=a.element*b.denominator;
			if(res.denominator<0)
			{
				res.denominator*=-1;
				res.element*=-1;
			}
			break;
		}
	default:break;
	}
	res=yuefen(res);

	disnum(a);
	printf(" %c ",ch);
	disnum(b);
	printf(" = ");
	disnum(res);
	printf("\n");
}
grade yuefen(grade& num)
{
	grade result=num;
	if(result.denominator==0)
	{
		result.denominator=0;
		result.element=1;
	}
	else if(result.element!=0&&result.denominator!=0)
	{
		if(result.element<0)
		{
			result.element=-1*result.element;
		}
		if(result.element<result.denominator)
		{
			int temp;
			temp=result.element;
			result.element=result.denominator;
			result.denominator=temp;
		}
		int c;	
		if(result.element%result.denominator==0)
		{
			c=result.denominator;
			result.element=num.element/c;
			result.denominator=num.denominator/c;
		}
		else
		{
			while(result.element%result.denominator!=0)
			{
				c=result.element%result.denominator;
				result.element=result.denominator;
				result.denominator=c;
			}
			result.element=num.element/c;
			result.denominator=num.denominator/c;
		}
	}
	else if(result.element==0&&result.denominator!=0)
	{
		result.element=0;
		result.denominator=1;
	}
	return result;
}
void disnum(grade &num)
{
	grade r=num;
	if(r.element==0)
	{
		printf("0");
		return;
	}
	if(r.denominator==0){printf("Inf");return;}
	int negative = 0;
	if(r.element<0)
	{
		negative = 1;
		r.element*=-1;
	}
	long long t=r.element/r.denominator;
	long long m=r.element%r.denominator;
	if(negative==1)
		printf("(-");
	if(t!=0)
		printf("%lld",t);
	if(m!=0)
	{
		if(t!=0)
			printf(" ");
		printf("%lld/%lld",m,r.denominator);
	}
	if(negative==1)
		printf(")");
}