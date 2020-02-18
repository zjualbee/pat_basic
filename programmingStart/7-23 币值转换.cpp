//7-23 币值转换 （20 分）

//输入一个整数（位数不超过9位）代表一个人民币值（单位为元），请转换成财务要求的大写中文格式。如23108元，转换后变成“贰万叁仟壹百零捌”元。为了简化输出，用小写英文字母a-j顺序代表大写数字0-9，用S、B、Q、W、Y分别代表拾、百、仟、万、亿。于是23108元应被转换输出为“cWdQbBai”元。
#include<iostream>
using namespace std;
int main()
{
    char num[10]={'a','b','c','d','e','f','g','h','i','j'};
    char unit[10]={0,0,'S','B','Q','W','S','B','Q','Y'};
    char res[17];
    int n;
    cin>>n;
    if(!n)
    {
        cout<<num[0]<<endl;
        return 0;
    }
    int k=0,bitnum=0,cur,pre=0;
    while(n)
    {
        cur=n%10;
        n/=10;
        bitnum++;
        if(cur)
        {
            if(bitnum>1)
                res[k++]=unit[bitnum];
            res[k++]=num[cur];
        }
        else
        {
            if(bitnum==5)
                res[k++]=unit[bitnum];
            else if(bitnum==9)
                res[k++]=unit[bitnum];
            else if(pre!=0&&bitnum!=4&&bitnum!=1)//若不为万位，千位，个位，且前一位不为0
                res[k++]=num[cur];
        }
        pre=cur;
    }
    for(int i=k-1;i>=0;i--)
        cout<<res[i];
    
    return 0;
}
