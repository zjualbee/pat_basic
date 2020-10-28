//7-51 两个有序链表序列的合并 （20 分）
/*
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
}*/
//7-51 两个有序链表序列的交集 （20 分）
/*
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef struct LNode *List;
struct LNode {
    int Data;
    List Next;
};

List Create()
{
    int d;
    List head=(List)malloc(sizeof(struct LNode)),q;
    head->Next=NULL;
    q=head;
    while(1)
    {
        scanf("%d",&d);
        if(d!=-1)
        {
            List p=(List)malloc(sizeof(struct LNode));
            p->Data=d;
            p->Next=NULL;
            q->Next=p;
            q=p;
        }
        else
            break;
    }
    return head;
}
List Intersection(List a,List b)
{
    a=a->Next;
    b=b->Next;
    List head=(List)malloc(sizeof(struct LNode));
    head->Next=NULL;
    List q=head;
    while(a && b)
    {
        if(a==NULL || a->Data > b->Data)
            b=b->Next;
        else if(b==NULL || a->Data < b->Data)
            a=a->Next;
        else
        {
            List p=(List)malloc(sizeof(struct LNode));
            p->Next=NULL;
            p->Data=b->Data;
            q->Next=p;
            q=p;
            a=a->Next;
            b=b->Next;
        }
    }
    return head;
}

int main()
{
    List a=Create();
    List b=Create();
    List c=Intersection(a,b);
    c=c->Next;
    int flag=0;
    if(c==NULL)
        printf("NULL\n");
    while(c)
    {
        if(flag==0){
            printf("%d",c->Data);
            flag=1;
        }
        else
            printf(" %d",c->Data);
        c=c->Next;
    }
    return 0;
}*/
//7-51 两个有序链表序列的合并 （20 分）
/*
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef struct LNode *List;
struct LNode {
    int Data;
    List Next;
};

List Create()
{
    int d;
    List head=(List)malloc(sizeof(struct LNode)),q;
    head->Next=NULL;
    q=head;
    while(1)
    {
        scanf("%d",&d);
        if(d!=-1)
        {
            List p=(List)malloc(sizeof(struct LNode));
            p->Data=d;
            p->Next=NULL;
            q->Next=p;
            q=p;
        }
        else
            break;
    }
    return head;
}
List Intersection(List a,List b)
{
    a=a->Next;
    b=b->Next;
    List head=(List)malloc(sizeof(struct LNode));
    head->Next=NULL;
    List q=head;
    while(a && b)
    {
            if(a->Data > b->Data)
           {
            List p=(List)malloc(sizeof(struct LNode));
            p->Next=NULL;
            p->Data=b->Data;
            q->Next=p;
            q=p;
            b=b->Next;
            }
            else
            {
                List p=(List)malloc(sizeof(struct LNode));
                p->Next=NULL;
                p->Data=a->Data;
                q->Next=p;
                q=p;
                a=a->Next;
            }
    }
    while(a)
    {
        List p=(List)malloc(sizeof(struct LNode));
        p->Next=NULL;
        p->Data=a->Data;
        q->Next=p;
        q=p;
        a=a->Next;
    }
    while(b)
    {
        List p=(List)malloc(sizeof(struct LNode));
        p->Next=NULL;
        p->Data=b->Data;
        q->Next=p;
        q=p;
        b=b->Next;
    }
    return head;
}

int main()
{
    List a=Create();
    List b=Create();
    List c=Intersection(a,b);
    c=c->Next;
    int flag=0;
    if(c==NULL)
        printf("NULL\n");
    while(c)
    {
        if(flag==0){
            printf("%d",c->Data);
            flag=1;
        }
        else
            printf(" %d",c->Data);
        c=c->Next;
    }
    return 0;
}
*/
//7-53 两个有序序列的中位数 （25 分）
/*
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
}*/
//7-19 求链式线性表的倒数第K项 （20 分）
/*
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> a;
int main()
{
    int k;
    scanf("%d",&k);
        int count=0,x;
        while(1)
        {
            scanf("%d",&x);
            if(x<0)
                break;
            else
            {
                a.push_back(x);
                count++;
            }
        }
        if(count<k)
            printf("NULL\n");
        else
            printf("%d\n",a[count-k]);
    
    return 0;
}*/
//7-40 奥运排行榜 （25 分）
/*
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
}*/
//7-41 PAT排名汇总 （25 分）
/*
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
}*/
//7-47 打印选课学生名单 （25 分）
/*
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<vector<string> > Class;
int main() {
    int s, c;
    cin >> s >> c;
    int num,tmp;
    Class.resize(s+1);
    string nametmp;
    // K门课的选课情况
    for (int i = 1; i <= s; ++i) {
        cin>>nametmp>>num;
        while (num--) {
            scanf("%d",&tmp);
            Class[tmp].push_back(nametmp);
        }
    }
    for(int i=1;i<=c;i++)
    {
        tmp=Class[i].size();
        if(tmp)
        {
            printf("%d %d\n",i,tmp);
            sort(Class[i].begin(),Class[i].end());
            for(int j=0;j<tmp;j++)
                    cout<<Class[i][j]<<endl;
        }
    }
    return 0;
}*/
//7-49 打印学生选课清单 （25 分）
/*
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
}*/

//7-17 汉诺塔的非递归实现 （25 分）
/*
#include<iostream>
#include<cstdio>
using namespace std;
void move(char getone, char putone)
{
    printf("%c -> %c\n",getone,putone);
}
void hanoi(int n, char one,char two,char three)
{
    if(n==1)
        move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        hanoi(n,'a','b','c');
    }
    return 0;
}
*/
//7-18 银行业务队列简单模拟 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        queue<int> a,b,c;
        int tmp,flag=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            if(tmp%2!=0)
                a.push(tmp);
            else
                b.push(tmp);
        }
        while(!a.empty() && !b.empty())
        {
            tmp=a.front();
            a.pop();
            c.push(tmp);
            if(!a.empty())
            {
                tmp=a.front();
                a.pop();
                c.push(tmp);
            }
            tmp=b.front();
            b.pop();
            c.push(tmp);
        }
        while(!a.empty())
        {
            tmp=a.front();
            a.pop();
            c.push(tmp);
        }
        while(!b.empty())
        {
            tmp=b.front();
            b.pop();
            c.push(tmp);
        }
        while(!c.empty())
        {
            if(flag==0){
                printf("%d",c.front());
                c.pop();
                flag=1;
            }
            else
            {
                printf(" %d",c.front());
                c.pop();
            }
        }
    }
    return 0;
}*/
//7-45 航空公司VIP客户查询 （25 分）
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int n,k;
map<string ,int> ma;
char  x[18];
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        int y;
        scanf("%s%d",x,&y);
        y= y<k? k:y;
        ma[x]+=y;
    }
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%s",x);
        if(ma.find(x)!=ma.end())
            printf("%d\n",ma[x]);
        else
            printf("No Info\n");
    }
    return 0;
}*/

//7-39 魔法优惠券 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    vector<int> yh(N);
    for(int i=0;i<N;i++)
        scanf("%d",&yh[i]);
    int M;
    scanf("%d",&M);
    vector<int> price(M);
    for(int i=0;i<N;i++)
        scanf("%d",&price[i]);
    sort(yh.begin(),yh.end());
    sort(price.begin(),price.end());
    
    int i,j,len1=yh.size(),len2=price.size(),sum=0;
    for(i=len1-1,j=len2-1;i>=0&&j>=0;)
    {
        if(yh[i]>0 && price[j]>0)
        {
            sum+=yh[i]*price[j];
            i--;
            j--;
        }
        else
            break;
    }
    for(i=0,j=0;i<len1 && j<len2;)
    {
        if(yh[i]<0 && price[j]<0)
        {
            sum+=yh[i]*price[j];
            i++;
            j++;
        }
        else
            break;
    }
    printf("%d\n",sum);
    
    return 0;
}*/
//7-38 寻找大富翁 （25 分）
/*
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
}*/
//7-37 模拟EXCEL排序 （25 分）
/*
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
}*/
//7-21 求前缀表达式的值 （25 分）
/*
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s,'\n');
    int len=s.length();
    double a,b,res;
    stack<double> st;
    double num;
    int i,multiple;
    for(i=len-1;i>=0;i--)
    {
        if(s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            num=s[i]-'0';
            multiple=10;
            for(i--;i>=0;i--)
            {
                if((s[i]-'0'>=0 && s[i]-'0'<=9) || s[i]=='.')
                {
                    if(s[i]-'0'>=0 && s[i]-'0'<=9)
                    {
                       num+=multiple*(s[i]-'0');
                       multiple*=10;
                    }
                    else{
                        num/=multiple;
                        multiple=1;
                    }
                }
               
                else if(s[i]=='-')
                {
                    num*=-1;
                }
                else
                    break;
            }
            st.push(num);
        }
        else if(s[i]==' ')
            continue;
        else
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            if(s[i]=='+')
                res=a+b;
            else if(s[i]=='-')
                res=a-b;
            else if(s[i]=='*')
                res=a*b;
            else if(s[i]=='/')
            {
                if(b==0){
                    printf("ERROR\n");
                    return 0;
                }
                else
                    res=a/b;
            }
            st.push(res);
        }
    }
    printf("%.1f\n",st.top());
    return 0;
}*/
//7-22 堆栈模拟队列 （25 分）
/*
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s1,s2;
    int v1,v2;
    cin>>v1>>v2;
    if(v1>v2)
    {
        v1 ^= v2;
        v2 ^= v1;
        v1 ^= v2;
    }
    int num;
    char op;
    while(true)
    {
        cin>>op;
        if(op=='A')
        {
            cin>>num;
            if(s1.size()==v1)
            {
                if(s2.size()==0)
                {
                    while(s1.size())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s1.push(num);
                }
                else{
                    cout<<"ERROR:Full"<<endl;
                    continue;
                }
            }
         else
            s1.push(num);
        }
        else if(op=='D')
        {
            if(s2.size()==0)
            {
                if(s1.size()==0){
                    cout<<"ERROR:Empty"<<endl;
                    continue;
                }
                else{
                    while(s1.size())
                    {
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
            }
            cout<<s2.top()<<endl;
            s2.pop();
        }
        else if(op=='T')
            exit(0);
    }
    return 0;
    
}*/
//7-23 还原二叉树 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
#define Max 51
using namespace std;
typedef char ElemType;
typedef struct TNode *Bintree;
struct TNode
{
    ElemType Data;
    Bintree lchild;
    Bintree rchild;
};

Bintree Recover(ElemType Pre[],ElemType In[],int len)
{
    Bintree T;
    int i;
    if(!len)
        return NULL;
    else
    {
        T=(Bintree)malloc(sizeof(struct TNode));
        T->Data=Pre[0];
        for(i=0;i<len;i++)//在中序遍历序列中找根节点
        {
            if(Pre[0]==In[i])
                break;
        }
        //递归构建左右子树
        T->lchild=Recover(Pre+1,In,i);
        T->rchild=Recover(Pre+1+i,In+i+1,len-i-1);
    }
    return T;
}

int GetHigh(Bintree T)
{
    int hl,hr,height=0;
    if(!T)
        return 0;
    else
    {
        hl=GetHigh(T->lchild);
        hr=GetHigh(T->rchild);
        height=hl>hr?hl:hr;
        height++;
    }
    return height;
}

int main()
{
    Bintree Tree;
    ElemType Preorder[Max],Inorder[Max];
    int N,H;
    scanf("%d",&N);
    scanf("%s",Preorder);
    scanf("%s",Inorder);
    Tree = Recover(Preorder, Inorder, N);
    H=GetHigh(Tree);
    printf("%d\n",H);
    return 0;
}*/
//7-24 树种统计 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
string tname;
int main()
{
    int N;
    while(cin>>N)
    {
        map<string,double> num;
        map<string,double>::iterator it;
        for(int i=0;i<N;i++){
            getline(cin,tname,'\n');
            it=num.find(tname);
            if(it!=num.end())
                num[tname]++;
            else
                num.insert(pair<string,double>(tname,1));
        }
        for(it=num.begin();it!=num.end();++it){
            cout<<it->first;
            printf(" %.4f%%\n",it->second/N*100);
        }
    }
    return 0;
}*/
//7-25 朋友圈 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
#include<map>
using namespace std;
int vis[30001];
int root[30001]={0};
int GetRoot(int x)
{
    if(vis[x]==x) return vis[x];
    vis[x]=GetRoot(vis[x]);
    return vis[x];
}
void Join(int a,int b)
{
    int x=GetRoot(a);
    int y=GetRoot(b);
    if(x!=y)
        vis[y]=x;
}
int main()
{
    int N,M,k,x,y;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        vis[i]=i;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&k,&x);
        for(int j=1;j<k;j++)
        {
            scanf("%d",&y);
            Join(x,y);
        }
    }
    int maxn=0;
    for(int i=1;i<=N;i++)
    {
        int t=GetRoot(i);
        root[t]++;
        if(root[t]>maxn) maxn=root[t];
    }
    printf("%d\n",maxn);
    return 0;
}*/
//7-26 Windows消息队列 （25 分）
/*
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
}*/
//7-28 搜索树判断 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
#define Max 1005
using namespace std;
typedef int ElemType;
typedef struct TNode *Bintree;
struct TNode
{
    ElemType Data;
    Bintree lchild;
    Bintree rchild;
};

int flag=0,flag1=1,flag2=1;
Bintree Find(ElemType Pre[],int len)
{
    Bintree T;
    int i,j;
    if(!len)
        return NULL;
    else
    {
        T=(Bintree)malloc(sizeof(struct TNode));
        T->Data=*Pre;
        for(i=1;i<len;i++)//在遍历序列中找根节点
        {
            if(Pre[i]>=T->Data)
                break;
        }
        for(j=i;j<len;j++)
        {
            if(Pre[j]<T->Data)
            {
                flag1=0;
                return NULL;
            }
        }
        //递归构建左右子树
        T->lchild = Find( Pre+1, i-1);
        T->rchild = Find( Pre+i, len-i);
    }
    return T;
}

Bintree FindMirror(ElemType Pre[],int len)
{
    Bintree T;
    int i,j;
    if(!len)
        return NULL;
    else
    {
        T=(Bintree)malloc(sizeof(struct TNode));
        T->Data=*Pre;
        for(i=1;i<len;i++)//在遍历序列中找根节点
        {
            if(Pre[i]<T->Data)
                break;
        }
        for(j=i;j<len;j++)
        {
            if(Pre[j]>=T->Data)
            {
                flag2=0;
                return NULL;
            }
        }
        //递归构建左右子树
        T->lchild = FindMirror( Pre+1, i-1);
        T->rchild = FindMirror( Pre+i, len-i);
    }
    return T;
}

void PrintPost(Bintree T)
{
    if(T)
    {
        PrintPost(T->lchild);
        PrintPost(T->rchild);
        if(flag==0)
            flag=1;
        else
            printf(" ");
        printf("%d",T->Data);
    }
}

int main()
{
    Bintree Tree, TreeMirror;
    ElemType Preorder[Max];
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++)
        scanf("%d",&Preorder[i]);
    
    Tree = Find(Preorder,len);
    TreeMirror = FindMirror(Preorder,len);
    
    if(Tree && flag1)
    {
        printf("Yes\n");
        PrintPost(Tree);
        printf("\n");
    }
    else if(TreeMirror && flag2)
    {
        printf("Yes\n");
        PrintPost(TreeMirror);
        printf("\n");
    }
    else
        printf("No\n");
    return 0;
}*/
//7-29 修理牧场 （25 分）  优先队列
/*
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pq.push(x);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + b;
        pq.push(c);
        sum += c;
    }
    cout << sum;
    return 0;
}
*/
//7-29 修理牧场 （25 分）  最小堆
/*
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define MinData -1
#define Max 100
typedef int ElemType;
typedef struct HeapStruct *MinHeap;
struct HeapStruct
{
    ElemType Data[Max];
    int size;
};

MinHeap Create(int size)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    //H->Data = (ElemType *)malloc(sizeof(ElemType)*(size+1));
    H->size=0;
    H->Data[0]=MinData;
    return H;
}

void Insert(MinHeap H, ElemType X)
{
    int i=++H->size;
    for(;H->Data[i/2]>X;i/=2)
        H->Data[i]=H->Data[i/2];
    H->Data[i]=X;
}

ElemType DeleMin(MinHeap H)
{
    if(H->size<1)
        return -1;
    ElemType MinItem=H->Data[1];
    ElemType Item=H->Data[H->size--];
    int parent,child;
    for(parent=1;parent*2<=H->size;parent=child)
    {
        child = parent*2;
        if(child!=H->size && (H->Data[child+1]<H->Data[child]))
            child++;
        if(Item <= H->Data[child])
            break;
        else
            H->Data[parent]=H->Data[child];
    }
    H->Data[parent]=Item;
    return MinItem;
}

void PrintHeap(MinHeap H)
{
    int i,len=H->size;
    for(i=1;i<=len;i++)
    {
        if(i==1)
            printf("%d",H->Data[i]);
        else
            printf(" %d",H->Data[i]);
    }
    printf("\n");
}
int main()
{
    int len=0,tmp=0;
    scanf("%d",&len);
    MinHeap H=Create(len);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&tmp);
        Insert(H, tmp);
        //PrintHeap(H);
    }
    int a,b,c,sum=0;
    for(int i=0;i<len-1;i++)
    {
        a=DeleMin(H);
        b=DeleMin(H);
        c=a+b;
        Insert(H, c);
        sum+=c;
        //PrintHeap(H);
    }
    printf("%d\n",sum);
    return 0;
}*/

//7-31 笛卡尔树 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct DNode
{
    int k1,k2;
    int lchild,rchild;
};
int main()
{
    int N;
    scanf("%d",&N);
    vector<DNode> Diker(N);
    vector<int>  vis(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d %d",&Diker[i].k1,&Diker[i].k2,&Diker[i].lchild,&Diker[i].rchild);
        if(Diker[i].lchild != -1)
            vis[Diker[i].lchild]=1;
        if(Diker[i].rchild != -1)
            vis[Diker[i].rchild]=1;
    }
    int l,r,flag=1;
    for(int i=0;i<N;i++)
    {
        if((l=Diker[i].lchild)!=-1){
            if(Diker[l].k1>=Diker[i].k1 || Diker[l].k2<Diker[i].k2){
                flag=0;
                break;
            }
        }
        if((r=Diker[i].rchild)!=-1)
        {
            if(Diker[r].k1<Diker[i].k1 || Diker[r].k2<Diker[i].k2){
                flag=0;
                break;
            }
        }
    }
    if(N && flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}*/
//7-32 哥尼斯堡的“七桥问题” （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int root[1001]={0};
int Find(int X)
{
    if(root[X]==X) return X;
    else
        root[X]=Find(root[X]);
    return root[X];
}
void Union(int root1, int root2)
{
    int a=Find(root1);
    int b=Find(root2);
    if(a!=b)
        root[root1]=root2;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int tmp1,tmp2;
    vector<vector<int> > G;
    vector<int>  tmp;
    for(int i=0;i<=N;i++){
        G.push_back(tmp);
        root[i]=i;
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&tmp1,&tmp2);
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
        Union(tmp1, tmp2);
    }
    int cnt=0;
    int flag=1;
    for(int i=1;i<=N;i++)
    {
        if(Find(i)==i){
            cnt++;
        }
    }
    
    if(cnt==1){
    for(int i=1;i<=N;i++)
    {
        if(G[i].size()%2!=0){
            flag=0;
            break;
        }
    }
    }
    else
        flag=0;
    if(flag)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}*/
//7-33 地下迷宫探索 （30 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int vis[1000]={0};
int flag=0,judge=0;;
void DFS(int x,int n, vector<vector<int> > G)
{
    vis[x]=1;
    if(flag==0)
        flag=1;
    else
        printf(" ");
    printf("%d",x);
    judge++;
    
    for(int i=0;i<G[x].size();i++)
    {
        if(vis[G[x][i]]==0){
            DFS(G[x][i],n,G);
            printf(" %d",x);
        }
    }
}
int main()
{
    int N,M,S;
    scanf("%d %d %d",&N,&M,&S);
    vector<vector<int> > G;
    vector<int> tmp;
    int tmp1,tmp2;
    for(int i=0;i<=N;i++)
        G.push_back(tmp);
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&tmp1,&tmp2);
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
    }
    for(int i=0;i<=N;i++)
        sort(G[i].begin(),G[i].end());
    DFS(S,N,G);

    if(judge<N)
        printf(" 0");
    return 0;
}*/
//7-35 城市间紧急救援 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define INF 66666666
struct ENode
{
    int next;
    int dis;
};
int main()
{
    int N,M,S,D;
    scanf("%d %d %d %d",&N,&M,&S,&D);
    int i,j;
    vector<int> Jy(N);
    vector<vector<ENode> > map;
    vector<ENode> tmp;
    for(i=0;i<N;i++){
        scanf("%d",&Jy[i]);
        map.push_back(tmp);
    }
    int a,b,c;
    ENode node;
    for(i=0;i<M;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        node.next=b;
        node.dis=c;
        map[a].push_back(node);
        node.next=a;
        map[b].push_back(node);
    }
    vector<int> Know(N),Dist(N,-1),Jiuyuan(N),pre(N,-1),cnt(N);
    int newp,next,min,jiu;
    Know[S]=1;
    Dist[S]=0;
    Jiuyuan[S]=Jy[S];
    cnt[S]=1;
    newp=S;
    for(i=1;i<N;i++)
    {
        for(j=0;j<map[newp].size();j++)
        {
            next=map[newp][j].next;
            min=map[newp][j].dis;
            jiu=Jy[next];
            if(Know[next]==1)
                continue;
            if(Dist[next]==-1)
            {
                Dist[next]=Dist[newp]+min;
                Jiuyuan[next]=Jiuyuan[newp]+jiu;
                cnt[next]=cnt[newp];
            }
            else if(Dist[next]>Dist[newp]+min)
            {
                Dist[next]=Dist[newp]+min;
                Jiuyuan[next]=Jiuyuan[newp]+jiu;
                pre[next]=newp;
                cnt[next]=cnt[newp];
            }
            else if((Dist[next]==Dist[newp]+min)&&(Jiuyuan[next]<Jiuyuan[newp]+jiu))
            {
                Jiuyuan[next]=Jiuyuan[newp]+jiu;
                pre[next]=newp;
                cnt[next]+=cnt[newp];
            }
        }
        int minx=INF;
        for(j=0;j<N;j++)
        {
            if(Know[j]==1) continue;
            if(Dist[j]==-1) continue;
            if(Dist[j]<minx)
            {
                minx=Dist[j];
                newp=j;
            }
        }
        Know[newp]=1;
    }
    int flag=0;
    printf("%d %d\n",cnt[D],Jiuyuan[D]);
    vector<int> road;
    int t=D;
    while(t!=S)
    {
        road.push_back(t);
        t=pre[t];
    }
    road.push_back(S);
    for(i=road.size()-1;i>=0;i--)
    {
        if(flag==0)
            flag=1;
        else
            printf(" ");
        printf("%d",road[i]);
    }
    return 0;
}
*/
//
/*
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    int n,tmp;
    scanf("%d",&n);
    map<int,int> age;
    map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        if(age.find(tmp)==age.end())
            age.insert(pair<int,int>(tmp,1));
        else
            age[tmp]++;
    }
    for(it=age.begin();it!=age.end();++it)
    {
        printf("%d:%d\n",it->first,it->second);
    }
    return 0;
}
*/
//KMP 串的模式匹配 （25 分）
/*
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    string s,p;
    int n,pos=0;
    cin>>s;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>p;
        if((pos=s.find(p))!=string::npos)
            cout<<s.substr(pos)<<endl;
        else
            cout<<"Not Found"<<endl;
    }
    return 0;
}*/
//01-复杂度2 Maximum Subsequence Sum
/*
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> num(n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int thisSum=0,maxSum=0;
    int positive_flag=0,zero=0,first_flag=1,flag=1;
    int start_max=0,end_max=0,st=0,first=0,last=0;
    for(int i=0;i<n;i++)
    {
        last=num[i];
        if(num[i]>0)
            positive_flag++;
        else if(num[i]==0)
            zero++;
        if(first_flag)
        {
            first=last;
            first_flag=0;
        }
        if(flag)
        {
            st=i;
            flag=0;
        }
        thisSum+=num[i];
        if(thisSum>maxSum){
            maxSum=thisSum;
            start_max=st;
            end_max=i;
        }
        if(thisSum<0){
            thisSum=0;
            flag=1;
        }
    }
    if(positive_flag)
        printf("%d %d %d\n",maxSum,num[start_max],num[end_max]);
    else if(positive_flag==0 && zero!=0)
        printf("0 0 0\n");
    else
        printf("%d %d %d\n",maxSum,first,last);
    return 0;
}*/
//03-树2 List Leaves
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef struct Node *Tree;
struct Node
{
    int index;
    int lchild;
    int rchild;
};

int main()
{
    int n;
    scanf("%d",&n);
    char ch=getchar();
    vector<Node> node;
    Node tmp;
    vector<int> isRoot(n,0);
    for(int i=0;i<n;i++)
    {
        char left,right;
        scanf("%c %c",&left,&right);
        ch=getchar();
        tmp.index=i;
        if(left!='-')
        {
            tmp.lchild=left-'0';
            isRoot[left-'0']=1;
        }
        else
            tmp.lchild=-1;
        if(right!='-')
        {
            tmp.rchild=right-'0';
            isRoot[right-'0']=1;
        }
        else
            tmp.rchild=-1;
        node.push_back(tmp);
    }
    int root=-1;
    for(int i=0;i<n;i++)
        if(isRoot[i]==0)
        {
            root=i;
            break;
        }
    queue<Node> q;
    q.push(node[root]);
    
    int count=0,child;
    while(!q.empty())
    {
        Node curNode=q.front();
        q.pop();
        if(curNode.lchild != -1)
        {
            child=curNode.lchild;
            q.push(node[child]);
        }
        if(curNode.rchild != -1)
        {
            child=curNode.rchild;
            q.push(node[child]);
        }
        if(curNode.lchild==-1 && curNode.rchild==-1)
        {
            if(count==0){
                printf("%d",curNode.index);
                count=1;
            }
            else
                printf(" %d",curNode.index);
        }
    }
    return 0;
}*/
//03-树3 Tree Traversals Again
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#define Max 31
using namespace std;

typedef int ElemType;
typedef struct TNode *Bintree;
struct TNode
{
    ElemType Data;
    Bintree lchild;
    Bintree rchild;
};
int flag=0;
Bintree Recover(ElemType Pre[],ElemType In[],int len)
{
    Bintree T;
    int i;
    if(!len)
        return NULL;
    else
    {
        T=(Bintree)malloc(sizeof(struct TNode));
        T->Data=Pre[0];
        for(i=0;i<len;i++)//在中序遍历序列中找根节点
        {
            if(Pre[0]==In[i])
                break;
        }
        //递归构建左右子树
        T->lchild=Recover(Pre+1,In,i);
        T->rchild=Recover(Pre+1+i,In+i+1,len-i-1);
    }
    return T;
}

void PostOrder(Bintree T)
{
    if(T==NULL)
        return;
    if(T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        if(flag==0){
            printf("%d",T->Data);
            flag=1;
        }
        else
            printf(" %d",T->Data);
    }
}

int main()
{
    Bintree Tree;
    ElemType Preorder[Max],Inorder[Max];
    int N;
    scanf("%d",&N);
    stack<int> stackt;
    char type[5];
    int tmp,index=0;
    for(int i=0;i<2*N;i++)
    {
        scanf("%s",type);
        if(type[1]=='u'){
            scanf("%d",&tmp);
            stackt.push(tmp);
        }
        else if(type[1]=='o')
        {
            tmp=stackt.top();
            stackt.pop();
            Preorder[index]=tmp;
            Inorder[index++]=tmp;
        }
    }
    sort(Preorder,Preorder+N);
    Tree = Recover(Preorder, Inorder, N);
    PostOrder(Tree);
    return 0;
}*/
//7-43 字符串关键字的散列映射
/*
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N,P;
    scanf("%d%d",&N,&P);
    vector<int> H(P,-1);
    int pos;
    string s;
    int mapnum=0;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        int len=s.size(),mapnum=0;
        if(len==1)
            mapnum=s[len-1]-'A';
        else if(len==2)
            mapnum=s[len-1]-'A'+(s[len-2]-'A')*32;
        else
            mapnum=s[len-1]-'A'+(s[len-2]-'A')*32+(s[len-3]-'A')*32*32;
        
        
        pos=mapnum%P;
        int flag=1,t=1,wf=0;
        while(1)
        {
            pos=pos%P;
            if(pos<0)
                pos+=P;
            if(pos>=P)
                pos-=P;
            if(H[pos]==-1)
            {
                H[pos]=1;
                printf("%d",pos);
                break;
            }
            else{
                while(H[pos]!=-1)
                {
                    if(H[(pos+t*t*flag)%P]==-1)
                    {
                        H[(pos+t*t*flag)%P]=1;
                        printf("%d",(pos+t*t*flag)%P);
                        wf=1;
                        break;
                    }
                    if(flag==1)
                    {
                        flag=-1;
                    }
                    else{
                        flag=1;
                        t++;
                    }
                    if(t>=P){
                        wf=1;
                        break;
                    }
                }
            }
            if(wf)
                break;
        }
        if(i!=N-1)
            printf(" ");
    }
    return 0;
}*/
//10-排序5 PAT Judge （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct pat
{
    int user_id;
    int flag;
    vector<int> problem;
    int perfect_count;
    int total_score;
    int rank;
    bool operator < (const pat &a) const
    {
        if(total_score!=a.total_score)
            return total_score>a.total_score;
        else if(perfect_count!=a.perfect_count)
            return perfect_count>a.perfect_count;
        else if(user_id!=a.user_id)
            return user_id<a.user_id;
        else
            return flag>a.flag;
    }
    pat(int id=0,int f=0,int perfect=0,int total=0,int r=0):user_id(id),perfect_count(perfect),flag(f),total_score(total),rank(r){}
};
int main()
{
    int N,K,M;
    scanf("%d%d%d",&N,&K,&M);
    vector<pat> all;
    pat tmp;
    for(int j=0;j<K;j++)
        tmp.problem.push_back(-1);
    for(int i=0;i<N;i++)
    {
        tmp.user_id=i;
        all.push_back(tmp);
    }
    vector<int> perfect_score(K);
    for(int i=0;i<K;i++)
        scanf("%d",&perfect_score[i]);
    int uid,pid,pscore;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&uid,&pid,&pscore);
        uid--;
        pid--;
        if(all[uid].problem[pid]<pscore){
            if(all[uid].problem[pid]>0)
                all[uid].total_score-=all[uid].problem[pid];
            all[uid].problem[pid]=pscore;
            all[uid].total_score+=pscore;
            if(all[uid].flag==0)
                all[uid].flag=1;
        }
        else if(pscore==-1)
            all[uid].problem[pid]=0;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
            if(all[i].problem[j]==perfect_score[j])
                all[i].perfect_count++;
    }
    sort(all.begin(),all.end());
    all[0].rank=1;
    for(int i=1;i<N;i++)
    {
        if(all[i].total_score==all[i-1].total_score)
            all[i].rank=all[i-1].rank;
        else
            all[i].rank=i+1;
    }
    for(int i=0;i<N;i++)
    {
        if(all[i].flag)
        {
            printf("%d %05d %d",all[i].rank,all[i].user_id+1,all[i].total_score);
            for(int j=0;j<K;j++)
            {
                if(all[i].problem[j]==-1)
                    printf(" -");
                else
                    printf(" %d",all[i].problem[j]);
            }
            printf("\n");
        }
        else
            break;
    }
    return 0;
}*/
//7-48 银行排队问题之单窗口“夹塞”版
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
using namespace std;
struct customer
{
    string name;
    int arrive_t;
    int solve_p;
};
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    map<string,int> circles;
    int i,j,num_circle;
    string ntmp;
    for(i=0;i<M;i++)
    {
        scanf("%d",&num_circle);
        for(j=0;j<num_circle;j++)
        {
            cin>>ntmp;
            circles[ntmp]=i+1;
        }
    }
    vector<customer> persons;
    customer ctmp;
    for(i=0;i<N;i++)
    {
        cin>>ctmp.name>>ctmp.arrive_t>>ctmp.solve_p;
        if(ctmp.solve_p>60)
            ctmp.solve_p=60;
        persons.push_back(ctmp);
    }
    int ans=0,time=persons[0].arrive_t+persons[0].solve_p;
    queue<customer> q;
    vector<int> vis(N,0);
    q.push(persons[0]);
    vis[0]=1;
    while(!q.empty())
    {
        ctmp=q.front();
        cout<<ctmp.name<<endl;
        q.pop();
        bool flag=false;
        if(circles.find(ctmp.name)!=circles.end()){
            int cur=circles[ctmp.name];
            for(i=1;i<N;i++)
            {
               if(vis[i])
                   continue;
               if(persons[i].arrive_t>time)
                   break;
               if(circles[persons[i].name]==cur)
               {
                   q.push(persons[i]);
                   vis[i]=1;
                   flag=true;
                   ans+=time-persons[i].arrive_t;
                   time+=persons[i].solve_p;
                   break;
               }
            }
        }
        if(!flag)
        {
            for(i=1;i<N;i++)
            {
                if(vis[i])
                    continue;
                q.push(persons[i]);
                vis[i]=1;
                ans+=max(0,time-persons[i].arrive_t);
                if(persons[i].arrive_t>time) time=persons[i].arrive_t;
                time+=persons[i].solve_p;
                break;
            }
        }
    }
    printf("%.1f\n",1.0*ans/N);
   
    return 0;
}*/
//7-50 畅通工程之局部最小花费问题
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define maxn 10000
int f[maxn];
set<int> st;
struct road
{
    int u,v;
    int cost;
    int flag;
    bool operator < (const road &a) const
    {
        if(cost!=a.cost)
            return cost<a.cost;
        else
            return flag>a.flag;
    }
};
int find(int x)
{
    if(f[x]==x)
        return x;
    else
        return f[x]=find(f[x]);
}
int main()
{
    int N;
    scanf("%d",&N);
    vector<road> Graph;
    int num=N*(N-1)/2;
    road r;
    for(int i=0;i<=N;i++)
        f[i]=i;
    for(int i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&r.u,&r.v,&r.cost,&r.flag);
        Graph.push_back(r);
    }
    sort(Graph.begin(),Graph.end());
    
    int ans=0;
    for(int i=0;i<num;i++)
    {
        int start=find(Graph[i].u);
        int end=find(Graph[i].v);
        st.insert(Graph[i].u);
        st.insert(Graph[i].v);
        if(Graph[i].flag==1)
            f[start]=end;
        else if(start!=end)
        {
            ans+=Graph[i].cost;
            f[start]=end;
        }
        if(st.size()==N) break;
    }
    printf("%d\n",ans);
    return 0;
}
*/
//7-46 新浪微博热门话题 （30 分）
/*
#include<string>
#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
string change(string &s)
{
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') || (s[i]>='0'&&s[i]<='9'))
        {
            if(i!=0 && (s[i]>='A'&&s[i]<='Z'))
                s[i]=s[i]-'A'+'a';
            if(i==0 && (s[i]>='a'&&s[i]<='z'))
                s[i]=s[i]-'a'+'A';
        }
        else{
            s.replace(i,1," ");
        }
    }
    if(s[len-1]==' ')
        s.erase(s.end()-1);
    return s;
}
int main()
{
    int N;
    scanf("%d",&N);
    map<string,set<int>> topic;
    string tmp;
    getchar();
    for(int i=0;i<N;i++){
        getline(cin,tmp,'\n');
        int cur=0,begin,end;
        string sub,h;
        while(cur!=string::npos){
            sub=tmp.substr(cur);
            if((begin=sub.find("#"))!=string::npos)
                sub=sub.substr(begin+1);
            else
                break;
            if((end=sub.find("#"))!=string::npos)
                h=sub.substr(0,end);
            else
                break;
            h=change(h);
            topic[h].insert(i);
            cur+=begin+end+2;
        }
    }
    int max=0,mct=0;
    string h;
    for(map<string,set<int>>::iterator it=topic.begin();it!=topic.end();it++)
    {
        if(it->second.size()>max){
            max=it->second.size();
            h=it->first;
            mct=1;
        }
        else if(it->second.size()==max){
            mct++;
            if(it->first<h)
                h=it->first;
        }
    }
    cout<<h<<endl;
    cout<<max<<endl;
    if(mct>1)
        cout<<"And "<<mct-1<<" more ..."<<endl;
    return 0;
}*/
//7-44 基于词频的文件相似度 （30 分）
/*
#include<string>
#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
set<string> topic[1001];
void deal(string &s,int &cur)
{
    string word;
    s.push_back('@');
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(isalpha(s[i]))
        {
            s[i]=tolower(s[i]);
            word+=s[i];
        }
        else if(!word.empty())
        {
            if(word.size()>=3)
            {
                if(word.size()>10)
                    word.substr(0,10);
                topic[cur].insert(word);
            }
            word.clear();
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    string tmp;
    getchar();
    for(int i=0;i<N;i++){
        while(true)
        {
            string s;
            getline(cin,s,'\n');
            if((s == "#") && s.size()==1)
                break;
            deal(s,i);
        }
    }
    int time;
    scanf("%d",&time);
    set<string>::iterator ita;
    int a,b,count=0;
    for(int i=0;i<time;i++)
    {
        count=0;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        for(ita=topic[a].begin();ita!=topic[a].end();++ita)
        {
            if(topic[b].find(*ita)!=topic[b].end())
                ++count;
        }
        int all=topic[a].size()+topic[b].size()-count;
        double cal=count*100.0/all;
        printf("%.1f%%\n",cal);
    }
    
    return 0;
}*/
//7-27 家谱处理 （30 分）
/*
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    getchar();
    vector<string> name(N);
    map<string,string> father;
    for(int i=0;i<N;i++)
    {
        string s;
        getline(cin,s,'\n');
        int cnt=count(s.begin(),s.end(),' ');
        if(cnt==0)
        {
            father[s]="no";
            name[0]=s;
        }
        else{
            s=s.substr(cnt);
            father[s]=name[cnt/2-1];
            name[cnt/2]=s;
        }
    }
    for(int i=0;i<M;i++)
    {
        string a,b,c,d;
        cin>>a>>b>>b>>c>>b>>d;
        switch(c[0])
        {
            case 'p':
            {
                swap(a,d);
            }
            case 'c':
            {
                if(father[a]==d)
                    printf("True\n");
                else
                    printf("False\n");
                break;
            }
            case 's':
            {
                if(father[a]==father[d])
                    printf("True\n");
                else
                    printf("False\n");
                break;
            }
            case 'a':
                swap(a,d);
            case 'd':
            {
                while(father[a]!=d && father[a]!="no") a=father[a];
                if(father[a]=="no")
                    printf("False\n");
                else
                    printf("True\n");
                break;
            }
        }
    }
    return 0;
}
*/
//7-36 社交网络图中结点的“重要性”计算 （30 分）
/*
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define INF 10001
int f[INF];
int find(int x)
{
    if(f[x]==x) return x;
    else
        return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    int a=find(x),b=find(y);
    if(a!=b)
        f[a]=b;
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int **Dis=(int**)malloc(sizeof(int*)*(N));
    for(int i=0; i<N; i++) {
        Dis[i]=(int*)malloc(sizeof(int)*(N));
        for(int j=0; j<N; j++) {
            if(i==j)
                Dis[i][j]=0;
            else
                Dis[i][j]=INF;
        }
    }
    int i,j,k;
    for(i=0;i<M;i++)
    {
        scanf("%d%d",&j,&k);
        j--;k--;
        merge(j,k);
        Dis[j][k]=1;
        Dis[k][j]=1;
    }

    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                if(Dis[i][j]>Dis[i][k]+Dis[k][j])
                    Dis[i][j]=Dis[i][k]+Dis[k][j];
    
    scanf("%d",&k);
    int num,flag=1;
    set<int> s;
    for(i=0;i<N;i++)
        s.insert(find(i));
    if(s.size()>1)
        flag=0;
    for(i=0;i<k;i++)
    {
        scanf("%d",&num);
        num--;
        int sum=0;
        for(j=0;j<N;j++){
            if(Dis[num][j]==INF)
            {
                flag=0;
                break;
            }
            else
                sum+=Dis[num][j];
        }
        if(flag!=0)
            printf("Cc(%d)=%.2lf\n",num+1,(N-1)*1.0/sum);
        else
            printf("Cc(%d)=0.00\n",num+1);
    }
    return 0;
}*/
//7-11 关键活动 （30 分）
/*
#include <cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct data
{
    int b,lenth;
};
typedef struct node *Node;
struct node
{
    vector<data> Next;
    int Output;
    vector<data> From;
    int Input;
    node(int x=0,int y=0):Output(x),Input(y){}
};

int TopSort(vector<node> V,int n);

int main()
{
    
    int n,m;
    scanf("%d%d",&n,&m);
    vector<node> V(n+1);

    while(m--)
    {
        int disk1,disk2,lenth;
        data t;
        scanf("%d%d%d",&disk1,&disk2,&lenth);
        t.b=disk2;
        t.lenth=lenth;
        V[disk1].Next.push_back(t);
        t.b=disk1;
        V[disk2].From.push_back(t);
    }
    for(int i=1;i<=n;i++)
    {
        V[i].Input=V[i].From.size();
        V[i].Output=V[i].Next.size();
    }
    int Coast =TopSort(V,n);
    return 0;
}

int TopSort(vector<node> V,int n)
{
    vector<int> Earliest(n+1);
    while(1)
    {
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(0==V[i].Input)
            {
                flag=1;
                for(int j=0; j<V[i].Next.size(); j++)
                {
                    if(Earliest[V[i].Next[j].b]<Earliest[i]+V[i].Next[j].lenth)
                    {
                        Earliest[V[i].Next[j].b]=Earliest[i]+V[i].Next[j].lenth;
                    }
                    V[V[i].Next[j].b].Input-=1;
                }
                V[i].Input =-1;
            }
        }
        if(!flag)break;
    }
    
    int max=0,index;
    for(int i=1; i<=n; i++)
    {
        if(V[i].Input >0)
        {
            max=0;
            break;
        }
        if(Earliest[i]>max)
        {
            max=Earliest[i];
            index=i;
        }
    }
    printf("%d",max);
    if(max==0)return 0;
    
    vector<int> Latest(n+1,max);
    while(1)
    {
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(0==V[i].Output)
            {
                flag=1;
                for(int j=0; j<V[i].From.size(); j++)
                {
                    if(Latest[V[i].From[j].b]>Latest[i]-V[i].From[j].lenth)
                    {
                        Latest[V[i].From[j].b]=Latest[i]-V[i].From[j].lenth;
                    }
                    V[V[i].From[j].b].Output  -=1;
                }
                V[i].Output   =-1;
            }
        }
        if(!flag)break;
    }

    for(int i=1; i<=n; i++)
    {
        //      printf("{%d,%d}",Earliest[i],Latest[i]);
        if(Latest[i]==Earliest[i])
        {
            for(int j=V[i].Next.size()-1; j>=0; j--)
            {
                if(Latest[V[i].Next[j].b]==Latest[i]+V[i].Next[j].lenth )
                {
                    printf("\n%d->%d",i,V[i].Next[j].b);
                }
            }
        }
    }
    return max;
}*/
//7-34 任务调度的合理性 （25 分）
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct node{
    vector<int> Next;
    vector<int> From;
    int Input;
    int Output;
    node(int x=0,int y=0):Input(x),Output(y){}
};
int main()
{
    int N;
    scanf("%d",&N);
    vector<node> Ta(N+1);
    for(int i=1;i<=N;i++)
    {
        int k,pretask;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&pretask);
            Ta[i].Next.push_back(pretask);
            Ta[pretask].From.push_back(i);
        }
    }
    int cnt=0;
    node cur;
    queue<node> que;
    for(int i=1;i<=N;i++)
    {
        Ta[i].Input=Ta[i].From.size();
        Ta[i].Output=Ta[i].Next.size();
        if(Ta[i].Input==0){
            que.push(Ta[i]);
            cnt++;
        }
    }
    while(!que.empty())
    {
        cur=que.front();
        que.pop();
        for(int j=0;j<cur.Next.size();j++)
        {
            Ta[cur.Next[j]].Input--;
            if(Ta[cur.Next[j]].Input==0){
                que.push(Ta[cur.Next[j]]);
                cnt++;
            }
        }
    }
    
    if(cnt==N)
        printf("1\n");
    else
        printf("0\n");
    return 0;
}*/
//7-20 表达式转换 （25 分）
/*
 结题思路：
 将中缀表达式转换为后缀表达式，遵循以下步骤：
 (1) 初始化两个栈：运算符栈S1和储存中间结果的栈S2；
 (2) 从左至右扫描中缀表达式；
 (3) 遇到操作数时，将其压入S2；
 (4) 遇到运算符时，比较其与S1栈顶运算符的优先级：
 (4-1) 如果S1为空，或栈顶运算符为左括号“(”，则直接将此运算符入栈；
 (4-2) 否则，若优先级比栈顶运算符的高，也将运算符压入S1（注意转换为前缀表达式时是优先级较高或相同，而这里则不包括相同的情况）；
 (4-3) 否则，将S1栈顶的运算符弹出并压入到S2中，再次转到(4-1)与S1中新的栈顶运算符相比较；
 (5) 遇到括号时：
 (5-1) 如果是左括号“(”，则直接压入S1；
 (5-2) 如果是右括号“)”，则依次弹出S1栈顶的运算符，并压入S2，直到遇到左括号为止，此时将这一对括号丢弃；
 (6) 重复步骤(2)至(5)，直到表达式的最右边；
 (7) 将S1中剩余的运算符依次弹出并压入S2；
 (8) 依次弹出S2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式
 */
/*
#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    string s;
    getline(cin,s,'\n');
    for(int i=0;i<s.length();i++)
    {
        
    }
    return 0;
}*/
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main()
{
    
    int N,M;
    scanf("%d%d",&N,&M);
    int a,b;
    map<int,set<int>> conflict;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&a,&b);
        conflict[a].insert(b);
        conflict[b].insert(a);
    }
    int K,tmp;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&K);
        set<int> storage;
        for(int j=0;j<K;j++)
        {
            scanf("%d",&tmp);
            int flag=1;
            for(set<int>::iterator it=storage.begin();it!=storage.end();it++){
                int cur=*it;
                if(conflict[tmp].find(cur)!=conflict[tmp].end()){
                    flag=0;
                    break;
                }
            }
            if(flag)
                storage.insert(tmp);
        }
        if(storage.size()==K)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
*/
/*
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct mooncake
{
    double storage;
    double allprice;
    double price;
    mooncake(int s=0,int a=0,int p=0):storage(s),allprice(a),price(p){}
    bool operator<(const mooncake &a) const{
            return price>a.price;
    }
};
int main()
{
    int N,D;
    scanf("%d%d",&N,&D);
    vector<mooncake> cakes(N);
    for(int i=0;i<N;i++)
        scanf("%d",&cakes[i].storage);
    for(int i=0;i<N;i++)
        scanf("%d",&cakes[i].allprice);
    for(int i=0;i<N;i++)
        cakes[i].price=cakes[i].allprice*1.0/cakes[i].storage;
    sort(cakes.begin(),cakes.end());
    double sum=0;
    int cnt=0;
    while(D && cnt<N)
    {
        if(D>cakes[cnt].storage){
            sum+=cakes[cnt].allprice;
            D-=cakes[cnt].storage;
        }
        else
        {
            sum+=cakes[cnt].price*D;
            D=0;
        }
        cnt++;
    }
    printf("%.2lf\n",sum);
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int big(int num);
int small(int num);
void display(int a);
vector<int> digit;
void fm(int num);
int main()
{
    int n;
    while(cin>>n)
    {
        if(n<10000 && n>0)
        {
            int a=0,b=0;
            do
            {
                fm(n);
                a=big(n);
                b=small(n);
                n=a-b;
                display(a);
                cout<<" - ";
                display(b);
                cout<<" = ";
                display(n);
                cout<<endl;
                if(n%1111==0)
                    break;
            }while(n!=6174);
        }
    }
    return 0;
}
void fm(int num)
{
    digit.clear();
    while(num)
    {
        digit.push_back(num%10);
        num/=10;
    }
    sort(digit.begin(),digit.end());
}

int small(int num)
{
    int res=0;
    
    for(int i=0;i<4;i++)
    {
        res=10*res+digit[i];
    }
    return res;
}
int big(int num)
{
    int res=0;
    for(int i=3;i>=0;i--)
    {
        res=10*res+digit[i];
    }
    return res;
}
void display(int a)
{
    if(a>=1000)
        cout<<a;
    else if(a>=100)
        cout<<"0"<<a;
    else if(a>=10)
        cout<<"00"<<a;
    else if(a>=0)
        cout<<"000"<<a;
}*/

#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> example;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(example.find(a)!=example.end())
        {
            example.insert(make_pair(a, b));
        }
        else
            example[a]+=b;
    }
    for(map<int,int>::iterator it = example.begin();it!=example.end();++it)
    {
        printf("%d %d\n",it->first,it->second);
    }
    return 0;
}
