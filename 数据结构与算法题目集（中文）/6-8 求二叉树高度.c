int GetHeight( BinTree BT )
{
    int lh,rh;
    if(BT==NULL)
        return 0;
    else
    {
        lh = GetHeight(BT->Left);
        rh = GetHeight(BT->Right);
        return (lh>rh?lh:rh)+1;
    }
}
