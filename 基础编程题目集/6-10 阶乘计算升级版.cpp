//6-10 阶乘计算升级版（20 分）

//本题要求实现一个打印非负整数阶乘的函数。
//其中N是用户传入的参数，其值不超过1000。如果N是非负整数，则该函数必须在一行中打印出N!的值，否则打印“Invalid input”。
#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial ( const int N )
{
    if(N>=0&&N<=12)
    {
        long int res=1;
        for(int i=1;i<=N;i++)
            res*=i;
        printf("%ld\n",res);
    }
    else if(N>12&&N<=1000)
    {
        int num[3001]={0};
        int i,j,k=1,n=0,temp=0;
        num[0]=1;
        for(i=2;i<=N;i++)
        {
            for(j=0;j<k;j++)
            {
                temp=num[j]*i+n;
                num[j]=temp%10;
                n=temp/10;
            }
            while (n != 0)
            {  //如果有进位
                num[k] = n % 10;  //新加一位，添加信息。位数增1
                k++;
                n = n / 10;   //看还能不能进位
            }
        }
        for(i=k-1;i>=0;i--)
            printf("%d",num[i]);
        printf("\n");
    }
    else
    {
        printf("Invalid input\n");
    }
}
