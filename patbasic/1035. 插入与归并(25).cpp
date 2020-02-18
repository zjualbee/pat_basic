//1035. ≤Â»Î”ÎπÈ≤¢(25)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertion(vector<int> &m,int count)
{
	int i,j,key;
	i=count;
	key=m[i];
	for(j=i-1;j>=0;--j)
	{
		if(m[j]>key)
			m[j+1]=m[j];
		else
			break;
	}
	m[j+1]=key;
}
void merge(vector<int> &m,int count)
{
	int t=m.size()/(2*count);
	for(int i=0;i<t;i++)
	    sort(m.begin()+i*2*count,m.begin()+(i+1)*2*count);
	sort(m.begin()+t*2*count,m.end());
}
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<int> origin;
		vector<int> midsort;
		int i=0,j=0,temp;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			origin.push_back(temp);
		}
		for(i=0;i<n;i++)
		{
			cin>>temp;
			midsort.push_back(temp);
		}
		int count=1,equal=0;
		for(i=0;i<n-1;i++)
		{
			if(midsort[i]<=midsort[i+1])
				++count;
			else
				break;
		}
		for(i=count;i<n;i++)
			if(origin[i]==midsort[i])
				equal++;				
		if(count+equal==n)
		{
			cout<<"Insertion Sort"<<endl;
			insertion(midsort,count);
			for(i=0;i<n;i++)
			{
				if(i!=0)
					cout<<" ";
				cout<<midsort[i];
			}
		}
		else
		{
			int gui=0;
			while(count!=1)
			{
				gui++;
				count/=2;
			}
			for(int i=0;i<gui;i++)
				count*=2;
			cout<<"Merge Sort"<<endl;
			for(i=0;i<n/count;i++)
			{				
				for(j=i*count;j<count*(i+1)-1;j++)
				{
					if(midsort[j]>midsort[j+1])
					{
						count/=2;
						i=0;
						break;
					}
				}
			}
		    merge(midsort,count);
			for(i=0;i<n;i++)
			{
				if(i!=0)
					cout<<" ";
				cout<<midsort[i];
			}
		}
		cout<<endl;
	}
	return 0;
}