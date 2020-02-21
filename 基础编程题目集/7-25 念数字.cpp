//7-25 念数字 （15 分）

//输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。十个数字对应的拼音如下：
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string ping[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string num;
    cin>>num;
    int len=num.size();
    for(int i=0;i<len;i++)
    {
        if(num[i]=='-'){
            cout<<"fu"<<" ";
        }
        else{
            if(i!=len-1)
                cout<<ping[num[i]-'0']<<" ";
            else
                cout<<ping[num[i]-'0']<<endl;
        }
    }
    return 0;
}
