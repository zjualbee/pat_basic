//7-24 约分最简分式 （15 分）

//分数可以表示为分子/分母的形式。编写一个程序，要求用户输入一个分数，然后将其约分为最简分式。最简分式是指分子和分母不具有可以约分的成分了。如6/12可以被约分为1/2。当分子大于分母时，不需要表达为整数又分数的形式，即11/8还是11/8；而当分子分母相等时，仍然表达为1/1的分数形式。
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int fenzi,fenmu,min,i;
    scanf("%d/%d",&fenzi,&fenmu);
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
    printf("%d/%d\n",fenzi,fenmu);
    return 0;
}
