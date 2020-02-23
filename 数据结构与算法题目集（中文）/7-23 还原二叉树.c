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
Bintree Recover(ElemType *Pre,ElemType *In,int len);
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
}
