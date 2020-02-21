ElementType Average( ElementType S[], int N )
{
    ElementType s=0;
    for(int i=0;i<N;i++)
        s+=S[i];
    return s*1.0/N;
}
