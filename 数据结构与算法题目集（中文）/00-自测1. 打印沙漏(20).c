//00-×Ô²â1. ´òÓ¡É³Â©(20)
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	char x;
	while((scanf("%d",&n))!=EOF)
	{
		getchar();
		scanf("%c",&x);
		int row;
		row=sqrt((n+1)*1.0/2);
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<i;j++)
				printf(" ");
			for(int j=0;j<2*(row-i)-1;j++)
				printf("%c",x);
			printf("\n");
		}
		for(int i=1;i<row;i++)
		{
			for(int j=0;j<row-i-1;j++)
				printf(" ");
			for(int j=0;j<2*i+1;j++)
				printf("%c",x);
			printf("\n");
		}
		printf("%d\n",n+1-2*row*row);
	}
	return 0;
}