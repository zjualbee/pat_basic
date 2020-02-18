//1014. 福尔摩斯的约会 (20)
#include<stdio.h>
#include<string.h>
char *week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
void display(int num)
{
	if(num>=10)
		printf("%d",num);
	else
		printf("0%d",num);
}
int main()
{
	char str[4][61];
	for(int i=0;i<4;i++)
		gets(str[i]);
	char *p=str[0];
	char *q=str[1];
	int we=0;
	while(*p!='\0'&&*q!='\0')
	{
		if(*p==*q && (*p>='A' && *p<='G'))
		{
			we=*p-'A';
			break;
		}
		++p;
		++q;
	}
	++p;
	++q;
	int hour=0;
	while(*p!='\0'&&*q!='\0')
	{
		if(*p==*q &&((*p>='A' && *p<='N')||(*p>='0' && *p<='9')))
		{
			if(*p>='A' && *p<='N')
			{
				hour=10+*p-'A';
			}
			else
			{
				hour=*p-'0';
			}
			break;
		}
		++p;
		++q;
	}
	int min=0;
	p=str[2];
	q=str[3];
	while(*p!='\0'&&*q!='\0')
	{
		if(*p==*q)
		{
			if((*p>='A' && *p<='Z')||(*p>='a' && *p<='z'))
			break;
		}
		++min;
		++p;
		++q;
	}
	printf("%s ",week[we]);
	display(hour);
	printf(":");
	display(min);
	printf("\n");
	return 0;
}