#include<stdio.h>
int main()
{
    int origin,pass;
    while((scanf("%d%d",&origin,&pass))!=EOF)
    {
        int hour,min,fh,fm,t;
        hour=origin/100;
        min=origin%100;
        t=60*hour+min;
        t=t+pass;
        if(t<0)
            t=t+24*60;
        if(t>=24*60)
            t=t-24*60;
        fh=t/60;
        fm=t-fh*60;
        printf("%d%02d\n",fh,fm);
    }
    return 0;
}
