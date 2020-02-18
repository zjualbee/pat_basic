//7-33 有理数加法 （15 分）

//本题要求编写程序，计算两个有理数的和。
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int zi1,zi2,mu1,mu2,fenzi,fenmu,i;
    scanf("%d/%d",&zi1,&mu1);
    scanf("%d/%d",&zi2,&mu2);
    fenmu=mu1*mu2;
    fenzi=zi1*mu2+zi2*mu1;
    int min=fenzi<fenmu?fenzi:fenmu;
    for(i=2;i<=min;i++)
    {
        if(fenzi%i==0 && fenmu%i==0)
        {
            fenzi/=i;
            fenmu/=i;
            min=fenzi<fenmu?fenzi:fenmu;
            i=1;
        }
    }
    if(fenmu!=1)
        printf("%d/%d\n",fenzi,fenmu);
    else
        printf("%d\n",fenzi);
    return 0;
}
