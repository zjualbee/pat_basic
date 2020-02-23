#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int tmp;
    vector<int> s1;
    
    while(1)
    {
        cin>>tmp;
        if(tmp!=-1)
            s1.push_back(tmp);
        else
            break;
    }
    while(1)
    {
        cin>>tmp;
        if(tmp!=-1)
            s1.push_back(tmp);
        else
            break;
    }
    
    if(s1.empty())
        printf("NULL\n");
    else{
        sort(s1.begin(),s1.end());
        
        int len=s1.size();
        for(int i=0;i<len;i++)
        {
            if(i==0)
                printf("%d",s1[i]);
            else
                printf(" %d",s1[i]);
        }
    }
    return 0;
}
