#include<stdio.h>
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
        double x,y;
        x=n*0.01/0.3048;
        int chi=x;
        y=(x-chi)*12;
        int cun=y;
        printf("%d %d\n",chi,cun);
    }
    return 0;
}
