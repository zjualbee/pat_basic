#include<stdio.h>
int main()
{
    int origin;
    while((scanf("%d",&origin))!=EOF)
    {
        if(origin<=60)
            printf("Speed: %d - OK\n",origin);
        else
            printf("Speed: %d - Speeding\n",origin);
    }
    return 0;
}
