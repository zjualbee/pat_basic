//7-35 有理数均值 （20 分）

//本题要求编写程序，计算N个有理数的平均值。
#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;
struct fenshu
{
    int zi;
    int mu;
};
fenshu yuefen(fenshu t)
{
    int i,min,flag=1;
    fenshu res;
    if(t.zi<0)
        flag=-1;
    int fenzi=fabs(t.zi);
    int fenmu=t.mu;
    min=fenzi<fenmu?fenzi:fenmu;
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
    res.zi=fenzi*flag;
    res.mu=fenmu;
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<fenshu> s(n);
    
    fenshu sum;
    sum.zi=0;
    sum.mu=1;
    if(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d/%d",&s[i].zi,&s[i].mu);
            sum.zi=sum.mu*s[i].zi+sum.zi*s[i].mu;
            sum.mu=sum.mu*s[i].mu;
            sum=yuefen(sum);
        }
        sum.mu*=n;
        sum=yuefen(sum);
    }
    if(sum.zi==0)
        printf("0\n");
    else if(sum.mu!=1)
        printf("%d/%d\n",sum.zi,sum.mu);
    else
        printf("%d\n",sum.zi);
    return 0;
}
