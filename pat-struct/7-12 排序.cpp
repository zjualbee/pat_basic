#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    long long  a[100001];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(i!=0)cout<<" ";
        cout<<a[i];
    }
    return 0;
}
