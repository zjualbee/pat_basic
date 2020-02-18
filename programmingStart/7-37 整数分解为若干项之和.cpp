//7-38 数列求和-加强版 （20 分）

//给定某数字A（1≤A≤9）以及非负整数N（0≤N≤100000），求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。例如A=1, N=3时，S=1+11+111=123。
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int a,n;
    cin>>a>>n;
    if(n==0 || a==0)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int> s;
    int cursum,jinwei=0;
    for(int i=0;i<n;i++)
    {
        cursum=a*(n-i)+jinwei;
        s.push_back(cursum%10);
        jinwei=cursum/10;
    }
    if(jinwei)
        cout<<jinwei;
    for(int i=s.size()-1;i>=0;i--)
        cout<<s[i];
    cout<<endl;
    return 0;
}
