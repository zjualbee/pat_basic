//02-线性结构3. 求前缀表达式的值（25）
#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
#include<stdio.h>
#include<math.h>
using namespace std;

bool isop(string s)
{
	if(s=="+" || s=="-"|| s=="*"|| s=="/")
		return true;
	return false;
}

double stringToNum(string s)
{
	stringstream tmp;
	tmp<<s;
	double x;
	tmp>>x;
	return x;
}

string numToString(double num)
{
	stringstream tmp;
	tmp<<num;
	string s;
	tmp>>s;
	return s;
}

int main()
{
	vector<string> svec;
	string s;
	cin>>s;
	while(cin)
	{
		svec.push_back(s);
		cin>>s;
	}
	int n=svec.size();
	stack<string> sstack;

	double a=0,b=0;
	for(int i=n-1;i>=0;i--)
	{
		if(!isop(svec[i]))
			sstack.push(svec[i]);
		else
		{
			if(sstack.size()<2)
			{
				cout<<"ERROR";
				return 0;
			}
			else
			{
				a=stringToNum(sstack.top());
				sstack.pop();
				b=stringToNum(sstack.top());
				sstack.pop();
			}
			switch(svec[i][0])
			{
			case '+':
				a=a+b;
				sstack.push(numToString(a));
				break;
			case '-':
				a=a-b;
				sstack.push(numToString(a));
				break;
			case '*':
				a=a*b;
				sstack.push(numToString(a));
				break;
			case '/':
				if(fabs(b)<=1e-6){
					cout<<"ERROR"<<endl;
					return 0;
				}
				a=a/b;
				sstack.push(numToString(a));
				break;
			default:
				cout<<"ERROR"<<endl;
				return 0;
			}
		}
	}
	if(sstack.size()==1)
		printf("%.1f",stringToNum(sstack.top()));
	else
		printf("ERROR\n");
	return 0;
}