int FactorialSum( List L )
{
    int res=0;
    while(L!=NULL)
    {
        int t=1;
        for(int i=1;i<=L->Data;i++)
            t*=i;
        res+=t;
        L=L->Next;
    }
    return res;
}
