#include<stdio.h>
int main()
{
    int a,b;
    char c,t1,t2;
    while((scanf("%d%c%c%c%d",&a,&t1,&c,&t2,&b))!=EOF)
    {
        int res,flag=1;
        switch(c)
        {
            case '+':res=a+b;break;
            case '-':res=a-b;break;
            case '*':res=a*b;break;
            case '/':res=a/b;break;
            case '%':res=a%b;break;
            default:flag=0;break;
        }
        if(!flag)
            printf("ERROR\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
