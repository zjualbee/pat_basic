int Factorial( const int N )
{
    int res=1;
    if(N>0)
    {
        for(int i=1;i<=N;i++)
            res*=i;
    }
    else
        res=0;
    return res;
}
