#include<stdio.h>
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
        int y,f,ok=0;
        for(y=0;y<100;y++)
        {
            for(f=y;f<100;f++)
            {
                if(199*y+n==98*f)
                {
                    f=(199*y+n)/98;
                    ok=1;
                    printf("%d.%d\n",y,f);
                    break;
                }
            }
        }
        if(!ok)
            printf("No Solution\n");
    }
}
