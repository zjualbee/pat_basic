List MakeEmpty()
{
    List L=(List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
Position Find( List L, ElementType X )
{
    L = L->Next;
    while(L!=NULL)
    {
        if(L->Data == X)
            return L;
        L = L->Next;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P )
{
    List p=(List)malloc(sizeof(struct LNode));
    p->Data = X;
    p->Next = P;
    while(L!=NULL)
    {
        if(P==L->Next)
        {
            L->Next=p;
            return true;
        }
        L=L->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}
bool Delete( List L, Position P )
{
    while(L!=NULL)
    {
        if(L->Next==P)
        {
            L->Next=P->Next;
            return true;
        }
        L=L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}
