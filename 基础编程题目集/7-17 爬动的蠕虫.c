#include<stdio.h>
int main()
{
    int N,U,D;
    while((scanf("%d %d %d",&N,&U,&D))!=EOF)
    {
        int high=0,min=0;
        while(high<N)
        {
            if(min!=0)
            {
                high-=D;
                ++min;
            }
            high+=U;
            ++min;
        }
        printf("%d",min);
    }
    return 0;
}
