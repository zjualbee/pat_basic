//1002. 写出这个数 (20)
#include<iostream>
#include<stack>
#include<cstdio>
#include<string>
using namespace std;

void solve();
string dig[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char s[101];
int main()
{
	while((cin>>s)!=NULL)
		solve();
}
void solve()
{
	int sum=0,i=0;
	while(s[i]!='\0')
	{
		sum+=s[i]-'0';
		++i;
	}
	stack<int> sk;
	while(sum)
	{
		sk.push(sum%10);
		sum/=10;
	}
	while(sk.size()>1)
	{
		cout<<dig[sk.top()]<<" ";
		sk.pop(); 
	}
	cout<<dig[sk.top()]<<endl;
	sk.pop();
}