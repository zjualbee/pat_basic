ElementType FindKth( List L, int K )
{
    int cnt=1;
    while(L!=NULL)
    {
        if(cnt==K)
            return L->Data;
        cnt++;
        L=L->Next;
    }
    return ERROR;
}
