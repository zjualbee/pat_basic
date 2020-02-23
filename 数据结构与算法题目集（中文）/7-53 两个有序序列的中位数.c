#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> num;
        int tmp;
        for(int i=0;i<n*2;i++)
        {
            cin>>tmp;
            num.push_back(tmp);
        }
        sort(num.begin(),num.end());
        cout<<num[(2*n-1)/2]<<endl;
    }
    return 0;
}
