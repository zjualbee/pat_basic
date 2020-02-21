double f( int n, double a[], double x )
{
    double sum=0,cur=1;
    for(int i=0;i<=n;i++)
    {
        sum+=a[i]*cur;
        cur*=x;
    }
    return sum;
}
