#include<stdio.h>
int main()
{
    int a,b;
    while((scanf("%d%d",&a,&b))!=EOF)
    {
        int flag=0,sum=0;
        for(int i=a;i<=b;i++)
        {
            printf("%5d",i);
            flag++;
            sum+=i;
            if(flag%5==0)
                printf("\n");
        }
        if(flag%5!=0)
            printf("\n");
        printf("Sum = %d",sum);
    }
    return 0;
}
