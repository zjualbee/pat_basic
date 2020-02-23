Stack CreateStack(int MaxSize)
{
    Stack stack = (Stack)malloc(sizeof(struct SNode));
    stack->Data = (int *)malloc(sizeof(ElementType)* MaxSize);
    stack->Top1 = -1;
    stack->Top2 = MaxSize;
    stack->MaxSize = MaxSize;
    return stack;
}
bool Push(Stack S, ElementType X, int Tag)
{
    if (S == NULL)return false;
    if (S->Top1+1==S->Top2){
        printf("Stack Full\n");
        return false;
    }
    
    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else S->Data[--S->Top2] = X;
    return true;
}
ElementType Pop(Stack S, int Tag)
{
    if (S == NULL)return ERROR;
    if (Tag == 1){
        if (S->Top1 == -1)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    }
    
    if (S->Top2 == S->MaxSize)
    {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    return S->Data[S->Top2++];
    
    
}
