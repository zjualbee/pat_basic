//6-9 统计个位数字（15 分）

//本题要求实现一个函数，可统计任一整数中某个位数出现的次数。例如-21252中，2出现了3次，则该函数应该返回3。

#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
int Count_Digit ( const int N, const int D )
{
    int num[10]={0},temp=0;
    int num2=N;
    if(num2<0)
        num2*=-1;
    else if(num2==0)
        return 0;
    while(num2)
    {
        temp=num2%10;
        num[temp]++;
        num2/=10;
    }
    return num[D];
}
