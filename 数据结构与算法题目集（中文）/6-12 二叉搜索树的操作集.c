BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else
    {
        if(X<BST->Data)
        {
            BST->Left = Insert(BST->Left,X);
        }
        else if(X>BST->Data)
        {
            BST->Right = Insert(BST->Right,X);
        }
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    Position temp;
    if(!BST)
    {
        printf("Not Found\n");
    }
    else
    {
        if(X<BST->Data)
            BST->Left = Delete(BST->Left,X);
        else if(X>BST->Data)
            BST->Right = Delete(BST->Right,X);
        else
        {
            if(BST->Left && BST->Right)
            {
                temp = FindMin(BST->Right);
                BST->Data = temp->Data;
                BST->Right = Delete(BST->Right,temp->Data);
            }
            else
            {
                if(!BST->Left)
                    BST = BST->Right;
                else if(!BST->Right)
                    BST = BST->Left;
            }
        }
    }
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    while(BST)
    {
        if(X<BST->Data)
            BST = BST->Left;
        else if(X>BST->Data)
            BST = BST->Right;
        else
            return BST;
    }
    return NULL;
}
Position FindMin( BinTree BST )
{
    if(!BST)
        return NULL;
    else if(!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
}
Position FindMax( BinTree BST )
{
    if(!BST)
        return NULL;
    else if(!BST->Right)
        return BST;
    else
        return FindMax(BST->Right);
}
