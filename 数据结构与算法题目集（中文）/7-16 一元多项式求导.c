#include<stdio.h>
int main()
{
    int a,b,flag=0;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(b)
        {
            if(flag==1)
                printf(" ");
            printf("%d %d",a*b,b-1);
            flag=1;
        }
        if(getchar()!=' ')
            break;
    }
    if(!flag)
        printf("0 0");
    return 0;
}
