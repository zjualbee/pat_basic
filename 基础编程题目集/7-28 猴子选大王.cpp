//7-28 猴子选大王 （20 分）

//一群猴子要选新猴王。新猴王的选择方法是：让N只候选猴子围成一圈，从某位置起顺序编号为1~N号。从第1号开始报数，每轮从1报到3，凡报到3的猴子即退出圈子，接着又从紧邻的下一只猴子开始同样的报数。如此不断循环，最后剩下的一只猴子就选为猴王。请问是原来第几号猴子当选猴王？
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> monkey;
    for(int i=1;i<=n;i++)
        monkey.push_back(i);
    int last=0,i;
    while(monkey.size()!=1)
    {
        for(i=0;i<monkey.size();i++)
        {
            last++;
            if(last%3==0)
            {
                monkey.erase(monkey.begin()+i);
                i--;
            }
        }
    }
    cout<<monkey[0]<<endl;
    return 0;
}
