//1036. 跟奥巴马一起编程(15)
#include<iostream>
using namespace std;
int main()
{
	int n;
	char x;
	while((cin>>n)!=NULL)
	{
		cin>>x;
		for(int i=0;i<n;i++)
			cout<<x;
		cout<<endl;
		for(int i=0;i<n*1.0/2-2;i++)
		{
			cout<<x;
			for(int j=0;j<n-2;j++)
				cout<<" ";
			cout<<x<<endl;
		}
		for(int i=0;i<n;i++)
			cout<<x;
		cout<<endl;
	}
	return 0;
}