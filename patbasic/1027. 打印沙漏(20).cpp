//1027. ´òÓ¡É³Â©(20)
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	while((scanf("%d",&n))!=EOF)
	{
		char c;
		getchar();
		scanf("%c",&c);
		if(n<=1000)
		{
			int num=sqrt(1.0*(n+1)/2);
			int yushu=n-(2*num*num-1);
			int i=0,j=0;
			for(i=num;i>0;i--)
			{
				for(j=0;j<num-i;j++)
					printf(" ");
				for(j=0;j<2*i-1;j++)
					printf("%c",c);
				printf("\n");
			}
			for(i=2;i<=num;i++)
			{
				for(j=0;j<num-i;j++)
					printf(" ");
				for(j=0;j<2*i-1;j++)
					printf("%c",c);
				printf("\n");
			}
			printf("%d\n",yushu);
		}
	}
	return 0;
}