//1026. 程序运行时间(15)
#include<stdio.h>
void display(int n);
void display2(double n);
int main()
{
	int c1,c2;
	while((scanf("%d%d",&c1,&c2))!=EOF)
	{
		if(c1<c2 && c1>=0 && c2<=10000000)
		{
			double time=(c2-c1)*1.0/100;
			int hour=0,min=0;
			double sec=0;
			if(time>=3600)
			{
				hour=time/3600;
				time-=hour*3600;
			}
			if(time>=60)
			{
				min=time/60;
				time-=min*60;
			}
			if(time>=0)
			    sec=time;

			display(hour);
			printf(":");
			display(min);
			printf(":");
			display2(sec);
			printf("\n");
		}
	}
	return 0;
}
void display(int n)
{
	if(n<10)
		printf("0%d",n);
	else
		printf("%2d",n);
}
void display2(double n)
{
	if(n<10)
		printf("0%.0f",n);
	else
		printf("%2.0f",n);
}