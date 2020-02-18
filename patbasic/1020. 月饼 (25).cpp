//1020. ÔÂ±ý (25)
#include<iostream>
using namespace std;
#include<map>
#include<iomanip>
int main()
{
	int n,d;
	while((cin>>n>>d)!=NULL)
	{
		if(n>0&&n<=1100&&d>0&&d<=500)
		{
			double type[1100],sell[1100];
			map<double,int> unit;
			int i=0;
			double temp;
			for(i=0;i<n;i++)
				cin>>type[i];
			for(i=0;i<n;i++)
				cin>>sell[i];
			for(i=0;i<n;i++)
			{
				temp=sell[i]/type[i];
				unit.insert(make_pair(temp,i));
			}
			double sum=0;
			map<double,int>::iterator it=unit.end();
			int flag=n;
			while(d>0&&n>0)
			{
				--it;
				--n;
				if(d>type[it->second])
				{
					sum+=sell[it->second];
					d-=type[it->second];
				}
				else
				{
					sum+=it->first*d;
					d-=d;
				}
			}
			cout<<fixed;
			cout<<setprecision(2)<<sum<<endl;
		}
	}
	return 0;
}
#include<stdio.h>  
#include<algorithm>  
using namespace std;  
struct N{  
	double num;  
	double total;  
	double price;  
}data[1100];  

bool cmp(N a,N b){  
	return a.price>b.price;  
}  
int main(){  
	int n,m;  
	scanf("%d%d",&n,&m);  

	for(int i=0;i<n;i++)  
		scanf("%lf",&data[i].num);  

	for(int i=0;i<n;i++)  
		scanf("%lf",&data[i].total);  
	for(int i=0;i<n;i++)  
		data[i].price=data[i].total/data[i].num;   
	sort(data,data+n,cmp);  
	double x=0;  
	int j=0;  
	while(m>0&&j<n){  
		if(m>data[j].num){
			m-=data[j].num;  
			x+=data[j].total;                 
		}  
		else{  

			x+=data[j].price*m;  
			m-=data[j].num;
		}  
		j++;   

	}     
	printf("%.2lf\n",x);    

	return 0;  
}  
