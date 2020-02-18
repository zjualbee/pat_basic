//7-31 字符串循环左移 （20 分）

//输入一个字符串和一个非负整数N，要求将字符串循环左移N次。
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s,'\n');
    int n;
    cin>>n;
    for(int i=n;i<s.size();i++)
        cout<<s[i];
    for(int i=0;i<n;i++)
        cout<<s[i];
    cout<<endl;
    return 0;
}
