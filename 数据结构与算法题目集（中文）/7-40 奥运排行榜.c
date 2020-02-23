#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int id;     // 国家ID
    int gold;   // 金牌数
    int medal;  // 奖牌数
    double avgGold;     // 人均金牌数
    double avgMedal;    // 人均奖牌数
    int popu;   // 人口数
    int ranking[4];     // 金牌、奖牌、人均金牌、人均奖牌 的排名
};

int main() {
    // N个国家，编号0~N-1
    int n, m;
    cin >> n >> m;
    
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) {
        // 金牌数、奖牌数、国民人口数（单位为百万）
        cin >> a[i].gold >> a[i].medal >> a[i].popu;
        a[i].id = i;
        a[i].avgGold = 1.0 * a[i].gold / a[i].popu;
        a[i].avgMedal = 1.0 * a[i].medal / a[i].popu;
    }
    for(int c=0;c<4;++c)
    {
        sort(a.begin(),a.end(),[c](const Node &a, const Node &b)->bool
             {
                 if(c==0){
                     if(a.gold!=b.gold) return a.gold>b.gold;
                 }
                 else if(c==1){
                     if(a.medal!=b.medal) return a.medal>b.medal;
                 }
                 else if(c==2){
                     if(a.avgGold!=b.avgGold) return a.avgGold>b.avgGold;
                 }
                 else if(c==3){
                     if(a.avgMedal!=b.avgMedal) return a.avgMedal>b.avgMedal;
                 }
                 return a.id<b.id;
             });
        a[0].ranking[c]=1;
        for(int i=1;i<a.size();++i)
        {
            if((c==0 && a[i].gold==a[i-1].gold) ||
               (c==1 && a[i].medal==a[i-1].medal) ||
               (c==2 && a[i].avgGold==a[i-1].avgGold)||
               (c==3 && a[i].avgMedal==a[i-1].avgMedal))
            {
                a[i].ranking[c]=a[i-1].ranking[c];
            }
            else
                a[i].ranking[c]=i+1;
            
        }
    }
    // ID归位
    sort(a.begin(), a.end(), [] (const Node &a, const Node &b) -> bool {
        return a.id < b.id;
    });
    
    for(int i=0;i<m;++i)
    {
        int id;
        cin>>id;
        int *p=min_element(a[id].ranking,a[id].ranking+4);
        cout<<*p<<":"<<(p-a[id].ranking+1)<<(i==m-1?'\n':' ');
    }
    return 0;
}
