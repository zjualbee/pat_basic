//02-线性结构2. Reversing Linked List (25)
#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
struct node
{
	int address;
	int data;
	int next;
};
int main()
{
	int head,n,k;
	while((cin>>head>>n>>k)!=NULL)
	{
		vector<node> m;
	    node temp;
		map<int,int> link;
		int dat[100000];
		for(int i=0;i<n;i++)
		{
			cin>>temp.address>>temp.data>>temp.next;
			link.insert(make_pair(temp.address,temp.next));
			dat[temp.address]=temp.data;
		}
		int index=head;
		while(index!=-1)
		{
			node x={index,dat[index],link.find(index)->second};
			m.push_back(x);
			index=x.next;
		}
		int length=m.size();
		int t=length/k;
		for(int i=0;i<t;i++)
			reverse(m.begin()+i*k,m.begin()+(i+1)*k);
		for(int i=0;i<length-1;i++)
			printf("%05d %d %05d\n",m[i].address,m[i].data,m[i+1].address);
		printf("%05d %d -1\n",m[length-1].address,m[length-1].data);
	}
	return 0;
}