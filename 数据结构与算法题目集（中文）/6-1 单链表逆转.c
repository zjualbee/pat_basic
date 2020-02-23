List Reverse( List L )
{
    List p,q;
    p=L;
    L=NULL;
    while(p)
    {
        q=p;
        p=p->Next;
        q->Next=L;
        L=q;
    }
    return L;
}
