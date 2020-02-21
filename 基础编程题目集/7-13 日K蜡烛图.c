#include<stdio.h>
int main()
{
    double Open,High,Low,Close;
    while((scanf("%lf %lf %lf %lf",&Open,&High,&Low,&Close))!=EOF)
    {
        if(Open>Close)
        {
            printf("BW-Solid");
        }
        else if(Open<Close)
        {
            printf("R-Hollow");
        }
        else
        {
            printf("R-Cross");
        }
        
        int a,b;
        a=Low<Open && Low<Close;
        b=High>Open && High>Close;
        if(a && !b)
        {
            printf(" with Lower Shadow");
        }
        else if(!a && b)
        {
            printf(" with Upper Shadow");
        }
        else if(a && b)
        {
            printf(" with Lower Shadow and Upper Shadow");
        }
    }
    return 0;
}
