int IsTheNumber ( const int N )
{
    int flag=0,ge,cnt[10]={0},e=N;
    int t=sqrt(N);
    
    if(t*t==N)
    {
        while(e)
        {
            ge=e%10;
            cnt[ge]++;
            e=e/10;
        }
        for(int i=0;i<10;i++){
            if(cnt[i]>=2)
            {
                flag=1;
                break;
            }
        }
    }
    return flag;
}
