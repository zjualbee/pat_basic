//1035. Password (20)
#include<string>
#include<iostream>
#include<vector>
using namespace std;

struct pat
{
	string name;
	string pwd;
	int flag;
	pat(string n="",string p="",int f=0):name(n),pwd(p),flag(f){}
};
bool transfer(string &s)
{
	int len=s.size();
	int num=0;
	for(int i=0;i<len;i++)
	{
		switch(s[i])
		{
		case'1':
			{
				s[i]='@';
				num++;
				break;
			}
		case'l':
			{
				s[i]='L';
				num++;
				break;
			}
		case'0':
			{
				s[i]='%';
				num++;
				break;
			}
		case'O':
			{
				s[i]='o';
				num++;
				break;
			}
		default:break;
		}
	}
	if(num!=0)
		return true;
	else
		return false;
}
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		if(n!=1&&n>0&&n<=1000)
		{
			vector<pat> m;
			pat temp;
			for(int i=0;i<n;i++)
			{
				cin>>temp.name>>temp.pwd;
				m.push_back(temp);
			}
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(transfer(m[i].pwd))
				{
					m[i].flag=1;
					count++;
				}
			}
			if(count==0)
				cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
			else
			{
				cout<<count<<endl;
				for(int i=0;i<n;i++)
					if(m[i].flag==1)
						cout<<m[i].name<<" "<<m[i].pwd<<endl;
			}
		}
		else if(n==1)
			cout<<"There is 1 account and no account is modified"<<endl;
	}
}