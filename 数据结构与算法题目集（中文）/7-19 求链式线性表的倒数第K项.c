#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> a;
int main()
{
    int k;
    scanf("%d",&k);
    int count=0,x;
    while(1)
    {
        scanf("%d",&x);
        if(x<0)
            break;
        else
        {
            a.push_back(x);
            count++;
        }
    }
    if(count<k)
        printf("NULL\n");
    else
        printf("%d\n",a[count-k]);
    
    return 0;
}
