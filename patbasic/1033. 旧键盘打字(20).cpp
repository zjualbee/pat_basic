//1033. ¾É¼üÅÌ´ò×Ö(20)
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	char origin[100001],error[100001];
	gets(error);
	gets(origin);
	char *in=origin;
	map<char,int> e;
	char *p=error;
	int count=0;
	while(*p!='\0')
	{
		e.insert(make_pair(*p,count++));
		if(*p>='A'&&*p<='Z')
			e.insert(make_pair(*p-'A'+'a',count++));
		++p;
	}
	while(*in!='\0')
	{
		if((*in>='A'&&*in<='Z') && (e.find('+')!=e.end()))
		{
			++in;
			continue;
		}
		if(e.find(*in)==e.end())
		{
			printf("%c",*in);			
		}
		++in;
	}
	printf("\n");
	return 0;
}