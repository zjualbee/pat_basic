#include<stdio.h>
//混合类型数据格式化输入
int main()
{
    double x,y;
    int m;
    char ch[3];
    scanf("%lf%d%s%lf",&x,&m,ch,&y);
    printf("%s %d %.2f %.2f",ch,m,x,y);
    
    return 0;
}
