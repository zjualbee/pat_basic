#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
        int max=sqrt(n),count=0;
        for(int i=1;i<=max;i++)
        {
            int tmp=sqrt((n-i*i));
            if(i>tmp)
                break;
            if(tmp*tmp+i*i==n)
            {
                count++;
                printf("%d %d\n",i,tmp);
            }
        }
        if(!count)
            printf("No Solution\n");
    }
    return 0;
}
