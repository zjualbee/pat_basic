//1010. 一元多项式求导 (25)
#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
struct dao
{
	long int xi;
	long int zhi;
};
int main()
{
	char ch='s';
	vector<dao> num;
	dao temp;
	while(ch!='\n')
	{
		cin>>temp.xi>>temp.zhi;
		num.push_back(temp);
		ch=getchar();
	}
	for(int i=0;i<num.size();i++)
	{
		if(num[i].zhi!=0)
		{
			num[i].xi*=num[i].zhi;
			num[i].zhi-=1;
			if(i!=0)
				cout<<" ";
			if(num[i].xi!=0)
			    cout<<num[i].xi<<" "<<num[i].zhi;
		}
	}
	return 0;
}