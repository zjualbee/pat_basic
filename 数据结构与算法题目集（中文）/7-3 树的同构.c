#include<stdio.h>
#include<string.h>
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
}

