//1029. ¾É¼üÅÌ(20)
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int main()
{
	char origin[81],final[81];
	gets(origin);
	gets(final);
	char *in=origin;
	char *out=final;
	int count=0;
	map<char,int> error;
	while(*in!='\0')
	{
		if(*in==*out)
		{
			++in;
			++out;
			continue;
		}
		else
		{
			if(*in>='a'&&*in<='z')
				*in=*in-'a'+'A';
			if(error.find(*in)==error.end())
			{
				printf("%c",*in);
				error.insert(make_pair(*in,count++));
			}
			++in;
		}
	}
	printf("\n");
	return 0;
}