#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Exam
{
    string id;
    int score,num1,num2,num3;
    bool operator<(const Exam &b) const
    {
        if(score!=b.score)
            return score>b.score;
        else
            return id<b.id;
    }
};
int main()
{
    int N,m,cnt=0,start=0,end=0;
    scanf("%d",&N);
    vector<Exam> e;
    Exam tmp;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&m);
        start=end;
        for(int j=0;j<m;j++)
        {
            cin>>tmp.id>>tmp.score;
            tmp.num2=i;
            e.push_back(tmp);
            cnt++;
        }
        end=start+m;
        sort(e.begin()+start,e.begin()+end);
        for(int j=start;j<end;j++)
        {
            if(j!=start && e[j].score==e[j-1].score)
                e[j].num3=e[j-1].num3;
            else
                e[j].num3=j-start+1;
        }
    }
    sort(e.begin(),e.end());
    cout<<cnt<<endl;
    for(int j=0;j<cnt;j++)
    {
        if(j!=0 && e[j].score==e[j-1].score)
            e[j].num1=e[j-1].num1;
        else
            e[j].num1=j+1;
        cout<<e[j].id<<" "<<e[j].num1<<" "<<e[j].num2<<" "<<e[j].num3<<endl;
    }
    return 0;
}
