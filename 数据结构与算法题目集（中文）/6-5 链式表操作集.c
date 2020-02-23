Position Find( List L, ElementType X )
{
    while(L!=NULL)
    {
        if(L->Data == X)
            return L;
        L = L->Next;
    }
    return ERROR;
}
List Insert( List L, ElementType X, Position P )
{
    List head=L;
    List p=(List)malloc(sizeof(struct LNode));
    p->Data = X;
    p->Next = NULL;
    if(P==L)
    {
        p->Next=L;
        return p;
    }
    while(L!=NULL)
    {
        if(P==L->Next)
        {
            List temp=L->Next;
            L->Next=p;
            p->Next=temp;
            return head;
        }
        L=L->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}
List Delete( List L, Position P )
{
    if(L==P)
    {
        L=L->Next;
        return L;
    }
    List head=L;
    while(L!=NULL)
    {
        if(L->Next==P)
        {
            List temp=L->Next->Next;
            L->Next=temp;
            return head;
        }
        L=L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}
