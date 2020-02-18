//1005. Spell It Right (20)
#include<stdio.h>
char *c[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
#include<stack>
using namespace std;
int main()
{
	char num[101];
	while((scanf("%s",num))!=EOF)
	{
		int i=0,sum=0;
		while(num[i]!='\0')
		{
			sum+=num[i]-'0';
			++i;
		}
		stack<int> digit;
		while(sum!=0)
		{
			digit.push(sum%10);
			sum/=10;
		}
		int flag=0;
		if(digit.empty())
			printf("%s",c[0]);
		else{
			while(!digit.empty())
			{
				if(flag==0)
					flag=1;
				else
					printf(" ");
				printf("%s",c[digit.top()]);
				digit.pop();
			}
		}
		printf("\n");
	}
	return 0;
}