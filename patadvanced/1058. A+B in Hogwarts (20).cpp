//1058. A+B in Hogwarts (20)
#include<iostream>
using namespace std;
#include<stdio.h>
struct num
{
	int a;
	int b;
	int c;
};
int main()
{
	num m,n,res;
	int flag=0;
	scanf("%d.%d.%d%d.%d.%d",&m.a,&m.b,&m.c,&n.a,&n.b,&n.c);
	res.c=(m.c+n.c)%29;
	flag=(m.c+n.c)/29;
	res.b=(m.b+n.b+flag)%17;
	flag=(m.b+n.b+flag)/17;
	res.a=m.a+n.a+flag;
    printf("%d.%d.%d\n",res.a,res.b,res.c);
	return 0;
}