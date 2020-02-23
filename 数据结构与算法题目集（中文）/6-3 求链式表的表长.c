int Length( List L )
{
    int i=0;
    while(L!=NULL)
    {
        i++;
        L=L->Next;
    }
    return i;
}
