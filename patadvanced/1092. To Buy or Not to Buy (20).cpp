//1092. To Buy or Not to Buy (20)
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	unordered_map<char,int> sell;
	unordered_map<char,int>  buy;
	unordered_map<char,int>::iterator it1;
	unordered_map<char,int>::iterator it2;
	for(int i=0;i<s1.size();i++)
	{
		it1=sell.find(s1[i]);
		if(it1!=sell.end())
			it1->second++;
		else
			sell.insert(make_pair(s1[i],1));
	}
	for(int i=0;i<s2.size();i++)
	{
		it2=buy.find(s2[i]);
		if(it2!=buy.end())
			it2->second++;
		else
			buy.insert(make_pair(s2[i],1));
	}
	int cha=0,flag=0;
	for(it2=buy.begin();it2!=buy.end();++it2)
	{
		it1=sell.find(it2->first);
		if(it1!=sell.end()&&it1->second<it2->second)
		{
			cha+=it2->second-it1->second;
			flag=1;
		}
		else if(it1==sell.end())
		{
			cha+=it2->second;
			flag=1;
		}
	}

	if(flag)
		cout<<"No "<<cha<<endl;
	else
		cout<<"Yes "<<s1.size()-s2.size()<<endl;
	return 0;
}