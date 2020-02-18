//1008. Elevator (20)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<int> elevator;
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			elevator.push_back(temp);
		}
		int present=0,up=0,down=0;
		for(int i=0;i<n;i++)
		{
			if(elevator[i]-present<0)
				down+=present-elevator[i];
			else
				up+=elevator[i]-present;
			present=elevator[i];
		}
		int sum=6*up+4*down+5*n;
		cout<<sum<<endl;
	}
	return 0;
}