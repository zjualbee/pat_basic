//7-29 删除字符串中的子串 （20 分）
//输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1(81,'\0'),s2(81,'\0');
    getline(cin,s1,'\n');
    getline(cin,s2,'\n');
    int i;
    while((i=s1.find(s2))!=string::npos)
        s1.replace(i,s2.size(),"");
    cout<<s1;
    
    return 0;
}
