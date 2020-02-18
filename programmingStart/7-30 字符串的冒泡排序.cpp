//7-30 字符串的冒泡排序 （20 分）

//我们已经知道了将N个整数按从小到大排序的冒泡排序法。本题要求将此方法用于字符串序列，并对任意给定的K（<N），输出扫描完第K遍后的中间结果序列。

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s[j]>s[j+1])
            {
                swap(s[j],s[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
    return 0;
}
