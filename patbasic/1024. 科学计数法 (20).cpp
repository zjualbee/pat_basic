//1024. 科学计数法 (20)
#include<stdio.h>
#include<string.h>
int main()
{
	//freopen("in.txt","r",stdin);
	char s[10000];
	while((scanf("%s",s))!=EOF)
	{
		char num[10000];
		int n;
		sscanf(s,"%[^E]",num);
		sscanf(s,"%*[^E]E%d",&n);
		int m=strlen(num);
		if(s[0]=='-')
			printf("-");
		if(n<0)
		{
			printf("0.");
			for(int i=n;i<-1;i++)
				printf("0");
			printf("%c",num[1]);
			int i=3;
			while(num[i]!='\0')
				printf("%c",num[i++]);
			printf("\n");
		}
		else if(n==0)
		{
			int i=1;
			while(num[i]!='\0')
				printf("%c",num[i++]);
			printf("\n");
		}
		else
		{
			printf("%c",num[1]);
			int i=3;
			if(m-3>n)
			{
				for(i=3;i<3+n;i++)
					printf("%c",num[i]);
				printf(".");
				while(num[i]!='\0')
					printf("%c",num[i++]);
				printf("\n");
			}
			else
			{
				int i=3;
				while(num[i]!='\0')
					printf("%c",num[i++]);
				for(i=0;i<n-(m-3);i++)
					printf("0");
				printf("\n");
			}
		}
	}
	return 0;
}