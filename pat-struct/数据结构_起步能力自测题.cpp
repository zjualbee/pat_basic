/*自测-1 打印沙漏 （20 分）
 
 本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印
#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
    int n;
    char fuhao;
    while(cin>>n)
    {
        getchar();
        scanf("%c",&fuhao);
        int max=sqrt((n+1)/2);
        int yu=n-(2*max*max-1);
        for(int i=max;i>0;i--)
        {
            for(int j=0;j<max-i;j++)
                printf(" ");
            for(int j=0;j<2*i-1;j++)
                printf("%c",fuhao);
            printf("\n");
        }
        for(int i=2;i<=max;i++)
        {
            for(int j=0;j<max-i;j++)
                printf(" ");
            for(int j=0;j<2*i-1;j++)
                printf("%c",fuhao);
            printf("\n");
        }
        printf("%d\n",yu);
    }
    return 0;
}*/
/*自测-2 素数对猜想 （20 分）
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool prime(int number)
{
    bool flag=false;
    int i;
    double m=sqrt(number*1.0);
    for(i=2;i<=m;i++)
    {
        if(number%i==0)
            break;
    }
    if(i>m)
        flag=true;
    return flag;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        vector<int> num;
        for(int i=3;i<=n;i+=2)
        {
            if(prime(i))
                num.push_back(i);
        }
        if(num.size())
        {
        for(int i=0;i<num.size()-1;i++)
        {
            if(num[i+1]-num[i]==2)
                count++;
        }
        }
        cout<<count<<endl;
    }
    return 0;
}*/
/*自测-3 数组元素循环右移问题 （20 分）
 一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> num(n);
        for(int i=0;i<n;i++)
            cin>>num[i];
        m=m%n;
        int flag=0;
        for(int i=n-m;i<n;i++){
            cout<<num[i];
            flag++;
            if(flag!=n)
                cout<<" ";
            else
                cout<<endl;
        }
        for(int i=0;i<n-m;i++)
        {
            cout<<num[i];
            flag++;
            if(flag!=n)
                cout<<" ";
            else
                cout<<endl;
        }
    }
    return 0;
}*/

/*自测-4 Have Fun with Numbers （20 分）
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string num;
    while(cin>>num)
    {
        int length=num.size(),fl=length;
        int onumber[20]={0},temp=0,jin=0,fnumber[20]={0},i,wei=0;
        int odigit[10]={0},fdigit[10]={0};
        for(i=length-1;i>=0;i--)
        {
            onumber[wei++]=num[i]-'0';
            odigit[num[i]-'0']++;
        }
        for(i=0;i<length;i++)
        {
            temp=onumber[i]*2+jin;
            fnumber[i]=temp%10;
            fdigit[temp%10]++;
            jin=temp/10;
        }
        if(jin){
            fnumber[i]=jin;
            fdigit[jin]++;
            fl++;
        }
 
        int flag=1;
        for(i=0;i<10;i++)
        {
            if(odigit[i]!=fdigit[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<"Yes"<<endl;
            for(i=length-1;i>=0;i--)
            {
                cout<<fnumber[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"No"<<endl;
            for(i=fl-1;i>=0;i--)
            {
                cout<<fnumber[i];
            }
            cout<<endl;
        }
    }
    return 0;
}*/
/*自测-5 Shuffling Machine （20 分）*/
#include<iostream>
#include<string>
using namespace std;
string card[54]={"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                 "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                 "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                 "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                 "J1", "J2"};
int main()
{
    int ntime;
    while(cin>>ntime)
    {
        int order[54],i;
        for(i=0;i<54;i++)
            cin>>order[i];
        int oposition[54],nposition[54];
        for(i=0;i<54;i++)
            oposition[i]=i;
        while(ntime--)
        {
            for(i=0;i<54;i++)
            {
                nposition[order[i]-1]=oposition[i];
            }
            for(i=0;i<54;i++)
            {
                oposition[i]=nposition[i];
            }
        }
        for(i=0;i<54;i++)
        {
            if(i!=53)
                cout<<card[nposition[i]]<<" ";
            else
                cout<<card[nposition[i]]<<endl;
        }
    }
    return 0;
}












