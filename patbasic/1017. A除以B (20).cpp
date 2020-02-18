//1017. A³ýÒÔB (20)
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	char str[1000];
	int num;
	vector<int> q;
	int temp,n=0;
	scanf("%s",str);
	scanf("%d",&num);
	if(num!=0)
	{
		char *p=str;
		while(*p!='\0')
		{
			n=n*10+(*p-'0');
			temp=n/num;
			q.push_back(temp);
			n=n%num;
			++p;
		}
		int flag=0;
		for(int i=0;i<q.size();i++)
		{
			if(flag==0&&q[i]!=0)
				flag=1;
			if(flag==1)
				cout<<q[i];
		}
		cout<<" "<<n;
	}
	return 0;
}