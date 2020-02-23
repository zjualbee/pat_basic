#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<long int> value(N);
    for(int i=0;i<N;i++)
        scanf("%ld",&value[i]);
    sort(value.begin(),value.end());
    int len=N;
    for(int i=0;i<M;i++)
    {
        if(len>0){
            if(i==0)
                printf("%ld",value[--len]);
            else
                printf(" %ld",value[--len]);
        }
    }
    return 0;
}
