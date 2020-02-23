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

int flag=0,flag1,flag2;
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
                flag1=1;
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
                flag2=1;
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
    
    if(Tree && !flag1)
    {
        printf("YES\n");
        PrintPost(Tree);
        printf("\n");
    }
    else if(TreeMirror && !flag2)
    {
        printf("YES\n");
        PrintPost(TreeMirror);
        printf("\n");
    }
    else
        printf("NO\n");
    return 0;
}
