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
