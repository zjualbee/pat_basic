#include<stdio.h>
int main()
{
    double m;
    while((scanf("%lf",&m))!=EOF)
    {
        double pai=0,tmp=1;
        double fenzi=1,fenmu=1,i=0;
        while(tmp>=m)
        {
            if(i!=0)
                fenzi*=i;
            fenmu=fenmu*(i*2+1);
            tmp=fenzi/fenmu;
            pai+=tmp;
            ++i;
        }
        printf("%.6f",pai*2);
    }
    return 0;
}
