#include<stdio.h>
int main()
{
    char a;
    while((scanf("%c",&a))!=EOF)
    {
        int i,j,k,count=0;
        char num[4]={a,a+1,a+2,a+3};
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
                if(i!=j)
                {
                    for(k=0;k<=3;k++)
                    {
                        if(k!=i && k!=j)
                        {
                            count++;
                            if(count%6!=0)
                                printf("%c%c%c ",num[i],num[j],num[k]);
                            else
                                printf("%c%c%c",num[i],num[j],num[k]);
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
