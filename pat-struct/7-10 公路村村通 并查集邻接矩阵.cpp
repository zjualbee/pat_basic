#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 1000+10
#define INF 99999999
int map[N][N];
int pre[N];//每个点前驱
int n,m;
int dis[N];//点与点之间最短距离
int sum = 0;
bool book[N];
int find(int x){
    if(x != pre[x]){
        return pre[x] = find(pre[x]);//查询并且压缩路径
    }
    return x;
}
void Union(int x,int y){
    int a = find(x);
    int b = find(y);
    if(a != b){//两个数根节点不同就合并
        pre[a] = b;
    }
}
void prime(int n){
    memset(book,false,sizeof(book));
    for(int i = 1;i <= n;i++){
        dis[i] = map[i][1];//距离数组初始化
    }
    book[1] = true;
    for(int i = 0;i < n - 1;i++){
        int index = 1;
        int min = INF;
        for(int j = 1;j <= n;j++){
            if(!book[j]&&dis[j] < min){
                min = dis[j];
                index = j;
            }
        }
        sum += dis[index];
        book[index] = true;
        for(int j = 1;j <= n;j++){
            if(!book[j]&&dis[j] > map[index][j]){
                dis[j] = map[index][j];//更新最小距离数组
            }
        }
    }
}
int main(){
    int a,b,c;
    //    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    //对map进行初始化
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j){
                map[i][j] = 0;
            }else{
                map[i][j] = INF;
            }
        }
        pre[i] = i;
    }
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        map[a][b] = c;
        map[b][a] = c;
        Union(a,b);
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(pre[i] == i){
            cnt++;
        }
    }
    if(cnt > 1){//判断是否连通，有两个或两个以上根节点则不连通
        printf("-1\n");
    }else{
        prime(n);
        printf("%d\n",sum);
    }
    return 0;
}
