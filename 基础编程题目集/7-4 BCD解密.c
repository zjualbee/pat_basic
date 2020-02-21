#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    a=n/16;
    b=n%16;
    if(a)
        printf("%d",a);
    printf("%d",b);
    return 0;
}
