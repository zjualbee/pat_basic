//1027. Colors in Mars (20)
#include<iostream>
#include<stdio.h>
using namespace std;
void print(int num)
{
	int a,b;
	a=num/13;
	b=num%13;
	if(a>=0&&a<10)
		printf("%d",a);
	else
		printf("%c",'A'+a-10);
	if(b>=0&&b<10)
		printf("%d",b);
	else
		printf("%c",'A'+b-10);
}
int main()
{
	int r,g,b;
	while((cin>>r>>g>>b)!=NULL)
	{
		printf("#");
		print(r);
		print(g);
		print(b);
		printf("\n");
	}
	return 0;
}
