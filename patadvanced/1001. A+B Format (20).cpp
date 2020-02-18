//1001. A+B Format (20)
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while((cin>>a>>b)!=NULL)
	{
		int res=a+b;
		int temp;
		int flag=0;
		if(res<0)
		{
			cout<<"-";
			res*=-1;
		}
		if(res>=1000000)
		{
			temp=res/1000000;
			cout<<temp<<",";
			res%=1000000;
			flag=1;
		}
		if(flag==1&&res<1000)
			cout<<"000"<<",";
		if(res>=1000)
		{
			temp=res/1000;
			if(flag==1)
			{
				if(temp<1000&&temp>=100)
					cout<<temp<<",";
				else if(temp<100&&temp>=10)
					cout<<"0"<<temp<<",";
				else if(temp<10)
					cout<<"00"<<temp<<",";
				flag=0;
			}
			else
				cout<<temp<<",";
			res%=1000;
			flag=1;
		}
		if(res>=0)
		{
			temp=res/1;
			if(flag==1)
			{
				if(temp<1000&&temp>=100)
					cout<<temp<<endl;
				else if(temp<100&&temp>=10)
					cout<<"0"<<temp<<endl;
				else if(temp<10)
					cout<<"00"<<temp<<endl;
			}
			else
				cout<<temp<<endl;
		}
	}
	return 0;
}