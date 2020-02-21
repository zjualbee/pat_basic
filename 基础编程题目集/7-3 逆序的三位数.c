#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while((cin>>n)!=NULL)
    {
        int t=n,ge,flag=0;
        while(t)
        {
            ge=t%10;
            if(ge!=0&&flag==0)
                flag=1;
            if(flag)
                printf("%d",ge);
            t/=10;
        }
    }
    return 0;
}
