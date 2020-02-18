//1074. Reversing Linked List (25)
#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct link
{
	int address;
	int data;
	int next;
};
int main()
{
	int head,n,p;
	while((cin>>head>>n>>p)!=NULL)
	{
		map<int,int> ne;
		vector<link> m;
		int d[100000];
		link temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp.address>>temp.data>>temp.next;
			ne.insert(make_pair(temp.address,temp.next));
			d[temp.address]=temp.data;
		}
		int add=head;
		while(add!=-1)
		{
			temp.address=add;
			temp.data=d[add];
			temp.next=ne.find(add)->second;
			m.push_back(temp);
			add=ne.find(add)->second;
		}
		int k=m.size()/p;
		for(int i=0;i<k;i++)
			reverse(m.begin()+i*p,m.begin()+(i+1)*p);
		for(int i=0;i<m.size()-1;i++)
			printf("%05d %d %05d\n",m[i].address,m[i].data,m[i+1].address);
		printf("%05d %d -1\n",m[m.size()-1].address,m[m.size()-1].data);
	}
	return 0;
}
