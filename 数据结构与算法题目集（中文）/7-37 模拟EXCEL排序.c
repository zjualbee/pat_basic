#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N,C=0;
struct stu
{
    string id;
    string name;
    int score;
    bool operator<(const stu &o) const {
        if (C == 1) {
            return id < o.id;
        } else if (C == 2) {
            // 姓名非递减，ID递增
            if (name != o.name) return name < o.name;
            return id < o.id;
        } else{
            // 成绩非递减，ID递增
            if (score != o.score) return score <o.score;
            return id < o.id;
        }
    }
};
int main()
{
    cin>>N>>C;
    vector<stu> re(N);
    for(int i=0;i<N;i++)
        cin>>re[i].id>>re[i].name>>re[i].score;
    sort(re.begin(),re.end());
    for(int i=0;i<N;i++)
        cout << re[i].id << " " << re[i].name << " " << re[i].score << "\n";
    return 0;
}
