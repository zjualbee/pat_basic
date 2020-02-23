#include <bits/stdc++.h>
using namespace std;
struct News
{
    char name[10];
    int pow;
    bool operator<(const News &b) const
    {
        return pow>b.pow;
    }
};

priority_queue<News> pque;
int main()
{
    int N;
    char type[4];
    News news;
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%s",type);
            if(type[0]=='P'){
                scanf("%s %d",news.name,&news.pow);
                pque.push(news);
            }
            if(type[0]=='G')
            {
                if(pque.size())
                {
                    news=pque.top();
                    pque.pop();
                    printf("%s\n",news.name);
                }
                else
                    printf("EMPTY QUEUE!\n");
            }
        }
    }
    return 0;
}
