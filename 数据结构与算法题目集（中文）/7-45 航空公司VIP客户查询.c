#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n,k;
map<string ,int> ma;
char  x[18];
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        int y;
        scanf("%s%d",x,&y);
        y= y<k? k:y;
        ma[x]+=y;
    }
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%s",x);
        if(ma.find(x)!=ma.end())
            printf("%d\n",ma[x]);
        else
            printf("No Info\n");
    }
    return 0;
}
