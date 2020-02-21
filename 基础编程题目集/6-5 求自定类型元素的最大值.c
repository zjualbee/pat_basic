ElementType Max( ElementType S[], int N )
{
    ElementType s=S[0];
    for(int i=1;i<N;i++)
    {
        if(S[i]>s)
            s=S[i];
    }
    return s;
}
