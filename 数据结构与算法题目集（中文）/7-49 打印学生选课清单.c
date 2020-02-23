#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn=200005;
int n,k;
vector <int> stu[maxn];
char s[5];
int fun ()
{
    return ((s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A'))*10+s[3]-'0';
}
int main() {
    int n, k;
    cin >> n >> k;
    int id, num;
    // K门课的选课情况
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d",&id,&num);
        while (num--) {
            scanf("%s",s);
            stu[fun()].push_back(id);
        }
    }
    // N次查询
    while (n--) {
        scanf("%s",s);
        vector<int> &c = stu[fun()];
        sort(c.begin(), c.end());
        printf("%s %d",s,c.size());
        for (int i = 0; i < c.size(); ++i) {
            printf(" %d", c[i]);
        }
        printf("\n");
    }
    return 0;
}
