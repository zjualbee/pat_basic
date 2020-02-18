//1012. Êı×Ö·ÖÀà (20)
#include<iostream>
using namespace std;
#include<vector>
#include<iomanip>
int main()
{
	int n;
	
	while((cin>>n)!=NULL)
	{
		vector<int> num;
	    int temp;
		int res[5],count[5];
		for(int i=0;i<5;i++)
		{
			res[i]=0;
			count[i]=0;
		}
		int flag=1;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			num.push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			temp=num[i]%5;
			switch(temp)
			{
			case 0:
				{
					if(num[i]%2==0)
					{
						res[0]+=num[i];
						count[0]++;
					}
					break;
				}
			case 1:
				{
					count[1]++;
					res[1]+=flag*num[i];
					flag*=-1;
					break;
				}
			case 2:
				{
					count[2]++;
					res[2]++;
					break;
				}
			case 3:
				{
					res[3]+=num[i];
					count[3]++;
					break;
				}
			case 4:
				{
					count[4]++;
					if(num[i]>res[4])
						res[4]=num[i];	
					break;
				}
			}
		}
		double ave;
		if(count[3]!=0)
		    ave=(double)res[3]/count[3];
		if(ave>-0.05&&ave<=0)
			ave=0;
		int m=0;
		for(int i=0;i<5;i++)
		{
			if(m==1)
				cout<<" ";
			if(i==3&&count[3]!=0)
			{
				cout<<fixed;
				cout<<setprecision(1)<<ave;
				continue;
			}
			if(count[i]==0)
			{
				cout<<"N";
				m=1;
			}
			else
			{
				cout<<res[i];
				m=1;
			}
		}
	}
	return 0;
}
