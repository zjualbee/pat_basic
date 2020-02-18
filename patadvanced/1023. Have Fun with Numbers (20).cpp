//1023. Have Fun with Numbers (20)
#include<stdio.h>
#include<vector>
using namespace std;
int digit[2][10]={0};
int main()
{
	char n[21];
	while((scanf("%s",n))!=EOF)
	{
		int len=0;
		char *p=n;
		while(*p!='\0')
		{		
			digit[0][*p-'0']++;
			++p;
			++len;
		}
		vector<int> n2;
		int z=0,g=0,s=0;
		for(int i=len-1;i>=0;i--)
		{
			s=2*(n[i]-'0');
			g=s%10+z;
			n2.push_back(g);
			z=s/10;
		}
		if(z!=0)
			n2.push_back(z);
		for(int i=0;i<n2.size();i++)
			digit[1][n2[i]]++;
		int flag=0;
		for(int i=0;i<10;i++)
		{
			if(digit[0][i]!=digit[1][i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("Yes\n");
		else
			printf("No\n");
		for(int i=n2.size()-1;i>=0;i--)
			printf("%d",n2[i]);
		printf("\n");
	}
}