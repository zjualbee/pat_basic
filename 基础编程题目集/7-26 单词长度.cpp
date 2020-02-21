//7-26 单词长度 （15 分）

//你的程序要读入一行文本，其中以空格分隔为若干个单词，以.结束。你要输出每个单词的长度。这里的单词与语言无关，可以包括各种符号，比如it's算一个单词，长度为4。注意，行中可能出现连续的空格；最后的.不计算在内。
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s;
    getline(cin,s,'.');
    int begin=-1,end=0,len=0;
    vector<int> count;
    while((end=s.find(" "))!=string::npos)
    {
        len=end-begin-1;
        if(len)
            count.push_back(len);
        begin=end;
        s.replace(end,1,",");
    }
    len=s.size()-begin-1;
    if(len)
        count.push_back(len);
    for(int i=0;i<count.size();i++)
    {
        if(i==0)
            cout<<count[i];
        else
            cout<<" "<<count[i];
    }
    cout<<endl;
    return 0;
}
