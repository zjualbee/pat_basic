#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int hour,min;
    char c;
    while((scanf("%d%c%d",&hour,&c,&min))!=EOF)
    {
        if(hour>12)
            printf("%d:%d PM\n",hour-12,min);
        else if(hour==12)
            printf("%d:%d PM\n",hour,min);
        else
            printf("%d:%d AM\n",hour,min);
    }
    return 0;
}
