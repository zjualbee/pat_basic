#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    vector<int> yh(N);
    for(int i=0;i<N;i++)
        scanf("%d",&yh[i]);
    int M;
    scanf("%d",&M);
    vector<int> price(M);
    for(int i=0;i<N;i++)
        scanf("%d",&price[i]);
    sort(yh.begin(),yh.end());
    sort(price.begin(),price.end());
    
    int i,j,len1=yh.size(),len2=price.size(),sum=0;
    for(i=len1-1,j=len2-1;i>=0&&j>=0;)
    {
        if(yh[i]>0 && price[j]>0)
        {
            sum+=yh[i]*price[j];
            i--;
            j--;
        }
        else
            break;
    }
    for(i=0,j=0;i<len1 && j<len2;)
    {
        if(yh[i]<0 && price[j]<0)
        {
            sum+=yh[i]*price[j];
            i++;
            j++;
        }
        else
            break;
    }
    printf("%d\n",sum);
    
    return 0;
}
