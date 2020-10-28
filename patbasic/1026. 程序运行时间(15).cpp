#include "stdio.h"
int main()
{
    int c1,c2;
    scanf("%d%d",&c1,&c2);
    int time=(c2-c1)/100;
    int tmp=0;
    if ((c2-c1)%100>49)
        tmp=1;
    int hh,mm,ss;
    hh=time/3600;
    time=time%3600;
    mm=time/60;
    time=time%60;
    ss=time+tmp;
    printf("%d:%d:%d\n",hh,mm,ss);
    return 0;
}
