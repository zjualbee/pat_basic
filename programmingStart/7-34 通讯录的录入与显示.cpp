//7-34 通讯录的录入与显示 （10 分）

//通讯录中的一条记录包含下述基本信息：朋友的姓名、出生日期、性别、固定电话号码、移动电话号码。 本题要求编写程序，录入N条记录，并且根据要求显示任意某条记录。
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct sinfo
{
    char name[11];
    char bir[15];
    char gender[2];
    char phone[20];
    char mobile[20];
};
int main()
{
    unsigned int n;
    scanf("%u",&n);
    vector<sinfo> s(n);
    for(int i=0;i<n;i++)
        scanf("%s %s %s %s %s",s[i].name,s[i].bir,s[i].gender,s[i].phone,s[i].mobile);
    unsigned int k,temp;
    scanf("%u",&k);
    vector<unsigned int> query_array(k);
    for(unsigned int i=0;i<k;++i)
        scanf("%u",&query_array[i]);
    for(int i=0;i<k;i++)
    {
        temp=query_array[i];
        if(temp>=n)
            cout<<"Not Found"<<endl;
        else
            printf("%s %s %s %s %s\n",s[temp].name,s[temp].phone,s[temp].mobile,s[temp].gender,s[temp].bir);
    }
    return 0;
}
