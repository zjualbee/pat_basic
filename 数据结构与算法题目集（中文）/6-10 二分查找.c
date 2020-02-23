Position BinarySearch( List L, ElementType X )
{
    if(L)
    {
        Position left=1,right=L->Last,mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(X==L->Data[mid])
                return mid;
            else if(X<L->Data[mid])
                right=mid-1;
            else
                left=mid+1;
        }
        return NotFound;
    }
    return NotFound;
}
