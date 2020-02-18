//1025. ·´×ªÁ´±í (25)
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<map>
using namespace std;
struct node
{
	int address;
	int data;
	int next;
};
int main()
{
	int n,p;
	int head;
	while((scanf("%d%d%d",&head,&n,&p))!=EOF)
	{
		vector<node> m;
		map<int,int> col;
		int data[100000];
		node temp;
		char address[6];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&temp.address,&temp.data,&temp.next);
			col.insert(make_pair(temp.address,temp.next));
			data[temp.address]=temp.data;
		}
		int index=head,i=1;
		map<int,int>::iterator it=col.begin();
		while(index!=-1)
		{
			node x={index,data[index],col.find(index)->second};
			m.push_back(x);
			index=x.next;		
		}
		int length=m.size();
		int t=length/p;
		for(int i=0;i<t;i++)
			reverse(m.begin()+i*p,m.begin()+(i+1)*p);	
		for(int i=0;i<m.size()-1;i++)
		{
			printf("%05d %d %05d\n",m[i].address,m[i].data,m[i+1].address);
		}
		printf("%05d %d -1\n",m[length-1].address,m[length-1].data);
	}
	return 0;
}