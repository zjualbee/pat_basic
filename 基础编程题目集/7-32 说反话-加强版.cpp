//7-32 说反话-加强版 （20 分）

//给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s;
    getline(cin,s,'\n');
    int begin=0,end=s.size(),len=0;
    vector<string> words;
    while((begin=s.rfind(" "))!=string::npos)
    {
        len=end-begin-1;
        if(len)
        {
            string temp=s.substr(begin+1,len);
            words.push_back(temp);
        }
        end=begin;
        s.replace(begin,1,",");
    }
    if(end)
    {
        string temp=s.substr(0,end);
        words.push_back(temp);
    }
    for(int i=0;i<words.size();i++)
    {
        if(i==0)
            cout<<words[i];
        else
            cout<<" "<<words[i];
    }
    cout<<endl;
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
string str;
stack<string> s;
int main()
{
    while(getline(cin,str))
    {
        istringstream it(str);
        bool isfirst = true;
        while ( it >> str )
        {
            s.push(str);
        }
        while (!s.empty())
        {
            if (isfirst)
            {
                isfirst = false;
                cout<<s.top();
            }
            else
            {
                cout<<" "<<s.top();
            }
            s.pop();
        }
        cout<< endl;
    }
    
    return 0;
}

