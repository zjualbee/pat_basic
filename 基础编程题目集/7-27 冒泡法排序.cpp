#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int i,j,tmp,num[100]={0};
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<k;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(num[j]>num[j+1])
            {
                tmp=num[j];
                num[j]=num[j+1];
                num[j+1]=tmp;
            }
        }
    }
    for(i=0;i<n-1;i++)
        printf("%d ",num[i]);
    printf("%d\n",num[i]);
    return 0;
}
