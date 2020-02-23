/*7-3 树的同构 （25 分）
#include<cstdio>
#include<iostream>
using namespace std;
typedef struct TNode Tree;
struct TNode
{
    char Data;
    int Left,Right;
};
Tree t1[12],t2[12];

int Read(Tree t[])
{
    int i;
    int n;
    int pre[12];
    int root=-1;
    memset(pre,0,sizeof(pre));
    scanf("%d",&n);
    if(n)
    {
        for(i=0;i<n;i++)
        {
            char l,r;
            scanf(" %c %c %c",&t[i].Data,&l,&r);
            if(l!='-')
            {
                t[i].Left=l-'0';
                pre[t[i].Left]=1;
            }
            else
                t[i].Left=-1;
            if(r!='-')
            {
                t[i].Right=r-'0';
                pre[t[i].Right]=1;
            }
            else
                t[i].Right=-1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(!pre[i])
        {
            root=i;
            break;
        }
    }
    return root;
}
int isSame(int root1,int root2)
{
    if((root1 == -1) && (root2 == -1)){//树根都是空，同构返回1
        return 1;
    }
 
    if(((root1 == -1) && (root2 != -1)) || ((root1 != -1) && (root2 == -1))){//如果一个是空一个不空，不同构，返回0
        return 0;
    }
 
    if((t1[root1].Data) != (t2[root2].Data)){//如果树根值不同，不同构，返回0
        return 0;
    }
 
    if((t1[root1].Left == -1) && (t2[root2].Left == -1)){//如果左子树都是空的，判断右子树
        return isSame(t1[root1].Right,t2[root2].Right);
    }
 
    if((t1[root1].Left != -1) && (t2[root2].Left != -1) && (t1[t1[root1].Left].Data == t2[t2[root2].Left].Data)){//如果左树不空且左子树值想同，判断其左右子树
        return (isSame(t1[root1].Left,t2[root2].Left) && isSame(t1[root1].Right,t2[root2].Right));
    }
 
    else{//如果左子树有一个空的，或者两个树不空 左子树的值不同 ,交换左右子树判断
        return (isSame(t1[root1].Left,t2[root2].Right) && isSame(t1[root1].Right,t2[root2].Left));
    }
}
int main()
{
    int root1,root2;
    root1=Read(t1);
    root2=Read(t2);
    if(isSame(root1, root2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}*/

//7-5 堆中的路径
/*
#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 1001
#define MINH -10001
int H[MAXN],size;
void Create()
{
    size=0;
    H[0]=MINH;
}

void Insert(int X)
{
    if(size==MAXN)
    {
        printf("堆栈已满\n");
        return;
    }
    int i;
    for(i=++size;H[i/2]>X;i/=2)
    {
        H[i]=H[i/2];
    }
    H[i]=X;
}
int main()
{
    int n,m,x,i,j;
    scanf("%d %d",&n,&m);
    Create();
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        Insert(x);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&j);
        printf("%d",H[j]);
        while(j>1)
        {
            j/=2;
            printf(" %d",H[j]);
        }
        printf("\n");
    }
    return 0;
}*/

/*7-7 是否同一棵二叉搜索树
#include<cstdio>
#include<iostream>
using namespace std;

typedef struct TNode* Tree;
struct TNode{
    int Data;
    Tree Left;
    Tree Right;
};
Tree insert(Tree BST,int X)
{
    if(BST==NULL)
    {
        BST = (Tree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        return BST;
    }
    else
    {
        if(X<BST->Data)
            BST->Left = insert(BST->Left,X);
        else if(X>BST->Data)
            BST->Right = insert(BST->Right, X);
    }
    return BST;
}
int isSame(Tree a, Tree b)
{
    if(a==NULL && b==NULL)
        return 1;
    else if((a==NULL && b!=NULL)||(a!=NULL && b==NULL))
        return 0;
    else if(a->Data != b->Data)
        return 0;
    else{
        int flag1=0,flag2=0;
        flag1=isSame(a->Left,b->Left);
        flag2=isSame(a->Right, b->Right);
        if(flag1 && flag2)
            return 1;
        else
            return 0;
    }
}

int main()
{
    int n,l;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        Tree BST=NULL;
        cin>>l;
        int X;
        for(int i=0;i<n;i++)
        {
            cin>>X;
            BST=insert(BST,X);
        }
 
        while(l--)
        {
            Tree com=NULL;
            for(int i=0;i<n;i++)
            {
                cin>>X;
                com=insert(com,X);
            }
            int flag=0;
            flag=isSame(BST, com);
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}*/
/*最大子列和问题
#include<iostream>
#include<vector>
using namespace std;
int maxsub1(vector<int> num,int n)
{
    int ThisSum, MaxSum=0;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            ThisSum=0;
            for(k=i;k<=j;k++)
                ThisSum+=num[k];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
        }
    }
    return MaxSum;
}
int maxsub2(vector<int> num,int n)
{
    int ThisSum, MaxSum=0;
    int i,k;
    for(i=0;i<n;i++)
    {
            ThisSum=0;
            for(k=i;k<n;k++)
                ThisSum+=num[k];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
    }
    return MaxSum;
}
int maxsub3(vector<int> num,int n)
{
    int ThisSum=0, MaxSum=0;
    int i;
    for(i=0;i<n;i++)
    {
        ThisSum+=num[i];
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;
        else if(ThisSum<0)
            ThisSum=0;
    }
    return MaxSum;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> num(n);
        for(int i=0;i<n;i++)
            cin>>num[i];
        cout<<maxsub3(num,n)<<endl;
    }
    return 0;
}*/
//线性表的定义与操作-顺序表
/*
#include<iostream>
#include<cstdio>
#define ERROR -1
#define MAXSIZE 10
using namespace std;

typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    int last;
};

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->last=-1;
    return L;
}
int Find(List L,ElementType X)
{
    int i=0;
    while(i<=L->last && L->Data[i]!=X)
        i++;
    if(i>L->last) return ERROR;
    else  return i;
}
bool Insert(List L,ElementType X,int P)
{
    int i;
    if(L->last==MAXSIZE-1)
    {
        printf("表满");
        return false;
    }
    if(P<0 || P>L->last+1)
    {
        printf("位置不合理");
        return false;
    }
    for(i=L->last;i>=P;i--)
        L->Data[i+1]=L->Data[i];
    L->Data[P]=X;
    L->last++;
    return true;
}
bool Delete(List L,int P)
{
    int i;
    if(P<0 || P>L->last)
    {
        printf("位置不合理");
        return false;
    }
    for(i=P+1;i<=L->last;i++)
        L->Data[i-1]=L->Data[i];
    L->last--;
    return true;
}
*/
//线性表的定义与操作-链式表
/*
#include<iostream>
#include<cstdio>
#define ERROR NULL
#define MAXSIZE 10
using namespace std;

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode next;
};
typedef PtrToLNode List;

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->next=NULL;
    return L;
}
List Find(List L,ElementType X)
{
    List p=L;
    while(p && p->Data!=X)
        p=p->next;
    if(p)
        return p;
    else
        return ERROR;
}
bool Insert(List L,ElementType X,List P)
{
    List tmp,pre;
    for(pre=L;pre && pre->next!=P;pre=pre->next);
    if(pre==NULL)
    {
        printf("插入位置不合理\n");
        return false;
    }
    else
    {
        tmp=(List)malloc(sizeof(struct LNode));
        tmp->Data=X;
        tmp->next=P;
        pre->next=tmp;
        return true;
    }
}
bool Delete(List L,List P)
{
    List tmp,pre;
    for(pre=L;pre && pre->next!=P;pre=pre->next);
    if(pre==NULL || P==NULL)
    {
        printf("删除位置不合理\n");
        return false;
    }
    else
    {
        pre->next=P->next;
        free(P);
        return true;
    }
}*/
//堆栈的定义与操作-顺序存储
/*
#include<cstdio>
#include<iostream>
using namespace std;

typedef int Position;
typedef int ElementType;
struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize*sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize-1);
}
bool Push(Stack S,ElementType X)
{
    if(IsFull(S))
    {
        printf("堆栈已满\n");
        return false;
    }
    else
    {
        S->Data[++(S->Top)]=X;
        return true;
    }
}
bool IsEmpty(Stack S)
{
    return (S->Top==-1);
}

ElementType Pop(Stack S)
{
    if(IsEmpty(S))
    {
        printf("堆栈为空\n");
        return false;
    }
    else
    {
        return S->Data[(S->Top)--];
    }
}*/
//堆栈的定义与操作-链式存储
/*
#include<cstdio>
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack Create()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S)
{
    return (S->Next == NULL);
}

bool Push(Stack S, ElementType X)
{
    PtrToSNode tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = X;
    tmp->Next = S->Next;
    S->Next = tmp;
    return true;
}

ElementType Pop(Stack S)
{
    PtrToSNode first;
    ElementType fcell;
    if(IsEmpty(S))
        return false;
    else
    {
        first = S->Next;
        fcell =  S->Data;
        S->Next = first->Next;
        free(first);
        return fcell;
    }
}*/
//多项式相加
/*
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};
Polynomial P1,P2;

void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    (*pRear)->link = P;
    *pRear = P;
}
Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;
    while(P1 && P2)
    {
        switch(compare(P1->expon,P2->expon))
        {
            case 1:
                Attach(P1->coef,P1->expon,&rear);
                P1 = P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&rear);
                P2 = P2->link;
                break;
            case 0:
                sum=P1->coef+P2->coef;
                if(sum) Attach(sum,P1->expon,&rear);
                P1=P1->link;
                P2=P2->link;
                break;
        }
    }
    for(;P1;P1=P1->link)
        Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link)
        Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp=front;
    front=front->link;
    free(temp);
    return front;
}*/
//二叉树的链式存储
/*
#include<cstdio>
using namespace std;

typedef struct TreeNode *BinTree;
typedef BinTree Position;
typedef int ElementType;
struct TreeNode
{
    ElementType Data;
    BinTree left;
    BinTree right;
};

void PreOrderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}
void InOrderTraversal(BinTree BT)
{
    if(BT)
    {
        InOrderTraversal(BT->left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->right);
    }
}
void PostOrderTraversal(BinTree BT)
{
    if(BT)
    {
        PostOrderTraversal(BT->left);
        PostOrderTraversal(BT->right);
        printf("%d",BT->Data);
    }
}
*/

/*
void InTraversal(BinTree BT)
{
    BinTree T=BT;
    Stack S = CreateStack(MaxSize);
    while(T || !IsEmpty(S))
    {
        while(T)
        {
            Push(S,T);
            T=T->left;
        }
        if(!IsEmpty(S))
        {
            T=Pop(S);
            printf("%5d",T->Data);
            T=T->right;
        }
    }
}*/

/*
#include<cstdio>
#include<iostream>
using namespace std;

typedef struct TNode* Tree;
struct TNode
{
    int Data;
    Tree Left;
    Tree Right;
};

Tree Insert(Tree BST,int X)
{
    if(BST == NULL)
    {
        BST = (Tree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
    }
    else
    {
        if(X<BST->Data)
            BST->Left = Insert(BST->Left,X);
        else if(X>BST->Data)
            BST->Right = Insert(BST->Right,X);
    }
    return BST;
}
int isSame(Tree a, Tree b)
{
    if(a==NULL && b==NULL)
        return 1;
    else if((a==NULL && b!=NULL) || (a!=NULL && b==NULL))
        return 0;
    else if(a->Data!=b->Data)
        return 0;
    else
    {
        int flag1=0,flag2=0;
        flag1=isSame(a->Left,b->Left);
        flag2=isSame(a->Right,b->Right);
        if(flag1 && flag2)
            return 1;
        else
            return 0;
    }
}

int main()
{
    int n,l;
    while(cin>>n)
    {
        if(n==0)
            break;
        Tree BST=NULL;
        cin>>l;
        int X;
        for(int i=0;i<n;i++)
        {
            cin>>X;
            BST=Insert(BST, X);
        }
        while(l--)
        {
            Tree com=NULL;
            for(int i=0;i<n;i++)
            {
                cin>>X;
                com=Insert(com, X);
            }
            int flag=0;
            flag=isSame(BST, com);
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}*/
//最大堆操作
/*
#include<cstdio>
#include<iostream>
using namespace std;

typedef struct HNode *Heap;
typedef int ElementType;
struct HNode
{
    ElementType *Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
#define MAXDATA 1000

MaxHeap Create(int MaxSize)
{
    MaxHeap H=(MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType *)malloc(sizeof(ElementType)*(MaxSize+1));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}

bool IsFull(MaxHeap H)
{
    return H->Size==H->Capacity;
}

bool Insert(MaxHeap H, ElementType X)
{
    int i;
    if(IsFull(H))
    {
        printf("最大堆已满\n");
        return false;
    }
    i=++H->Size;
    for(;H->Data[i/2]<X;i/=2)
    {
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return true;
}

#define ERROR -1
bool IsEmpty(MaxHeap H)
{
    return H->Size==0;
}

ElementType DeleteMax(MaxHeap H)
{
    int parent,child;
    if(IsEmpty(H))
    {
        printf("最大堆已为空\n");
        return ERROR;
    }
    ElementType MaxItem,X;
    MaxItem = H->Data[1];
    X = H->Data[H->Size--];
    for(parent=1;parent*2<=H->Size;parent=child)
    {
        child=parent*2;
        if((child!=H->Size)&&(H->Data[child]<H->Data[child+1]))
            child++;
        if(X>=H->Data[child])
            break;
        else
            H->Data[parent]=H->Data[child];
    }
    H->Data[parent]=X;
    return MaxItem;
}

void PercDown(MaxHeap H, int p)
{
    int parent, child;
    ElementType X;
    X=H->Data[p];
    for(parent=p;parent*2<=H->Size;parent=child)
    {
        child = parent*2;
        if((child!=H->Size)&&(H->Data[child]<H->Data[child+1]))
            child++;
        if(X<=H->Data[child])
            break;
        else
            H->Data[parent]=H->Data[child];
    }
    H->Data[parent]=X;
}
void BuildHeap(MaxHeap H)
{
    int i;
    for(i=H->Size/2;i>0;i--)
        PercDown(H, i);
}*/

