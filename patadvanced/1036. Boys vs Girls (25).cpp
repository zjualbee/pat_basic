//1036. Boys vs Girls (25)
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct stu
{
	string name;
	char gender;
	string id;
	int grade;
};
int main()
{
	int n;
	while((cin>>n)!=NULL)
	{
		vector<stu> m;
		stu temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp.name>>temp.gender>>temp.id>>temp.grade;
			m.push_back(temp);
		}
		int f1=0,f2=0;
		int min,max;
		for(int i=0;i<n;i++)
		{
			if(m[i].gender=='F')
			{
				if(f1==0)
				{
					max=i;
					f1=1;
				}
				else{
					if(m[i].grade>m[max].grade)
						max=i;
				}
			}
			else if(m[i].gender=='M')
			{
				if(f2==0)
				{
					min=i;
					f2=1;
				}
				else{
					if(m[i].grade<m[min].grade)
						min=i;
				}
			}
		}
		if(f1==0)
			cout<<"Absent"<<endl;
		else
			cout<<m[max].name<<" "<<m[max].id<<endl;
		if(f2==0)
			cout<<"Absent"<<endl;
		else
			cout<<m[min].name<<" "<<m[min].id<<endl;
		if(f1==0||f2==0)
			cout<<"NA"<<endl;
		else
			cout<<m[max].grade-m[min].grade<<endl;
	}
	return 0;
}