#include<cstdio>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n,p,num;
    int i;
    scanf("%d%d", &n, &p);
    vector<int> H(p,-1);
    for(i = 0; i < n; i++) {
        scanf("%d", &num);
        int hash=num%p;
        while(1)
        {
            if(hash>=p) hash-=p;
            if(H[hash]==num)
            {
                cout<<hash;
                break;
            }
            if(H[hash]==-1)
            {
                H[hash]=num;
                cout<<hash;
                break;
            }
            else
                hash++;
        }
        
        if(i!=n-1)
            cout<<" ";
    }
    return 0;
}
