int  Search_Bin(SSTable T, KeyType k)
{
    int len=T.length;
    int left=1,right=len;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(T.R[mid].key>k)
            right--;
        else if(T.R[mid].key<k)
            left++;
        else if(T.R[mid].key==k)
            return mid;
    }
    return 0;
}
