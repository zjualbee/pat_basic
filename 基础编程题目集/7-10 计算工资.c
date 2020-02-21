#include<stdio.h>
int main()
{
    int a,b;
    while((scanf("%d%d",&b,&a))!=EOF)
    {
        double s=0;
        int salary[2]={30,50},flag;
        if(b<5)
            flag=0;
        else
            flag=1;
        if(a<=40)
            s=a*salary[flag];
        else
            s=40*salary[flag]+(a-40)*salary[flag]*1.5;
        printf("%.2f\n",s);
    }
    return 0;
}
