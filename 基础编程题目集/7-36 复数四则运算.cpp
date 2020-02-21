//7-36 复数四则运算 （15 分）

//本题要求编写程序，计算2个复数的和、差、积、商。
#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

struct fushu
{
    double shi;
    double xu;
};
fushu a,b,res;

void print(fushu r,char c)
{
    if(a.xu>=0 && b.xu>=0)
        printf("(%.1lf+%.1lfi) %c (%.1lf+%.1lfi) = ",a.shi,a.xu,c,b.shi,b.xu);
    else if(a.xu<0 && b.xu>=0)
        printf("(%.1lf%.1lfi) %c (%.1lf+%.1lfi) = ",a.shi,a.xu,c,b.shi,b.xu);
    else if(a.xu>=0 && b.xu<0)
        printf("(%.1lf+%.1lfi) %c (%.1lf%.1lfi) = ",a.shi,a.xu,c,b.shi,b.xu);
    else
        if(a.xu>=0 && b.xu>=0)
            printf("(%.1lf%.1lfi) %c (%.1lf%.1lfi) = ",a.shi,a.xu,c,b.shi,b.xu);
    
    if(fabs(r.shi)<0.1 && fabs(r.xu)<0.1)
    {
        printf("0.0\n");
        return;
    }
    int flag=0;
    if(fabs(r.shi)>=0.1){
        printf("%.1lf",r.shi);
        flag++;
    }
    if(fabs(r.xu)>=0.1)
    {
        if(flag && r.xu>0)
            printf("+%.1lfi",r.xu);
        else
            printf("%.1lfi",r.xu);
    }
    cout<<endl;
}
int main()
{
    
    scanf("%lf %lf %lf %lf",&a.shi,&a.xu,&b.shi,&b.xu);
    res.shi=a.shi+b.shi;
    res.xu=a.xu+b.xu;
    print(res,'+');
    
    res.shi=a.shi-b.shi;
    res.xu=a.xu-b.xu;
    print(res,'-');
    
    res.shi=a.shi*b.shi-a.xu*b.xu;
    res.xu=a.shi*b.xu+a.xu*b.shi;
    print(res,'*');
    
    res.shi=(a.shi*b.shi+a.xu*b.xu)/(b.shi*b.shi+b.xu*b.xu);
    res.xu=(b.shi*a.xu-a.shi*b.xu)/(b.shi*b.shi+b.xu*b.xu);
    print(res,'/');
    return 0;
}
