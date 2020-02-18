//1005. ¼ÌĞø(3n+1)²ÂÏë (25)
#include<iostream>
#include<algorithm>
using namespace std;
struct guess
{
	int num;
	int mark;
}m[101];
bool cmp(guess a,guess b)
{
	return a.num>b.num;
}
void check(int n,int data)
{
	while(data!=1)
	{
		if(data%2==0)
			data=data/2;
		else
			data=(3*data+1)/2;
		for(int k=0;k<n;k++)
		{
			if(data==m[k].num && m[k].mark!=1)
			{
				m[k].mark=1;
				break;
			}
		}
	}
}
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		guess final[101];
		for(int i=0;i<n;i++)
		{
			cin>>m[i].num;
			m[i].mark=0;
		}
		for(int i=0;i<n;i++)
		{
			if(m[i].mark!=1)
				check(n,m[i].num);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(m[i].mark!=1)
				final[count++]=m[i];
		}
		sort(final,final+count,cmp);
		for(int i=0;i<count;i++)
		{
			if(i!=0)
				cout<<" ";
			cout<<final[i].num;
		}
	}
	return 0;
}