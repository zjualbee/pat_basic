#include<stdio.h>
double a3,a2,a1,a0;
double f(double x)
{
    return a3*x*x*x+a2*x*x+a1*x+a0;
}
int main()
{
    double a,b;
    int ok=1;
    scanf("%lf %lf %lf %lf",&a3,&a2,&a1,&a0);
    scanf("%lf %lf",&a,&b);
    while((b-a)>0.001)
    {
        if(f((a+b)/2)==0)
        {
            printf("%.2f\n",(a+b)/2);
            ok=0;
            break;
        }
        else if(f(a)*f((a+b)/2)<0)
        {
            b=(a+b)/2;
        }
        else
        {
            a=(a+b)/2;
        }
    }
    if(ok)
        printf("%.2f\n",(a+b)/2);
    return 0;
}
