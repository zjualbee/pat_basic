/*6-11 求自定类型元素序列的中位数（25 分）
 
 本题要求实现一个函数，求N个集合元素A[]的中位数，即序列中第⌊N/2+1⌋大的元素。其中集合元素的类型为自定义的ElementType。
 其中给定集合元素存放在数组A[]中，正整数N是数组元素个数。该函数须返回N个A[]元素的中位数，其值也必须是ElementType类型。*/

#include <stdio.h>
#define MAXN 10
typedef float ElementType;

ElementType Median (ElementType A[], const int N);//调用排序算法并打印中值
void showarray (ElementType A[], const int N);//展示数组
void quicksort (ElementType A[], const int N, int r);//快速排序
void bubblesort (ElementType A[], const int N);//冒泡排序
void insertsort (ElementType A[], const int N);//插入排序
void shellsort (ElementType A[], const int N);//希尔排序

int main ()
{
    ElementType A[MAXN];
    int N, i;
    
    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));
    
    return 0;
}


ElementType Median (ElementType A[], const int N)
{
    //printf("\n*********************insertSort********************\n");
    //insertsort(A,N);
    
    //printf("\n*********************bubbleSort********************\n");
    //bubblesort(A,N);
    
    //printf("\n*********************shellSort********************\n");
    //shellsort(A,N);
    
    printf("\n*********************selectSort********************\n");
    quicksort(A,N,9);
    
    printf("\nThe median Number:\n");
    return A[N/2];
}
//展示数组
void showarray (ElementType A[], const int N)
{
    int j;
    for(j=0; j<N; j++)
    {
        printf("%.2f\t", A[j]);
    }
    printf("\n");
}
//快速排序
void quicksort( ElementType A[], const int N, int r)
{
    ElementType tmp;
    int i, j;
    
    if(N < r)
    {
        i = N;
        j = r;
        tmp = A[i];
        while(i < j)
        {
            while(A[j]>tmp && i<j) //一定要i<j，因为下面j--改变了j的值，没有这个判定，无法跳过A[j]大于tmp不用改变j值的情况
                j--;               //由右往左寻找，遇到A[j]>tmp则跳过，寻找下一个
            if(i<j)
            {
                A[i] = A[j];
                i++;
            }
            while(A[i]<tmp && i<j) //改变这里的A[i]<tmp小于的符号，同时改变42行A[j]>tmp的大于符号，可以改为由大到小排列
                i++;
            if(i<j)
            {
                A[j] = A[i];
                j--;
            }
            showarray(A, r+1);
            //printf("\n***************************\n");
        }
        /**< 如果r == l，下面的语句不会执行，这也是迭代停止的条件 */
        A[i] = tmp;
        quicksort(A, N, i-1);
        quicksort(A, i+1, r);
    }
}

//冒泡排序
void bubblesort (ElementType A[], const int N)
{
    ElementType temp;
    int low=0;
    int high=N-1;
    int j;
    while(low<high)
    {
        for(j=low;j<high;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
        --high;
        for(j=high;j>low;j--)
        {
            if(A[j]<A[j-1])
            {
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
        ++low;
    }
}
//插入排序
void insertsort (ElementType A[], const int N)
{
    ElementType temp;
    int i,j;
    for(i=1;i<N;i++)
    {
        temp=A[i];
        for(j=i;j>0 && A[j]>A[j-1];j--)
            A[j]=A[j-1];
        A[j]=temp;
        showarray(A,N);
    }
}
//希尔排序
void shellsort (ElementType A[], const int N)
{
    int i,j,gap;
    ElementType tmp;
    for(gap=N/2;gap>0;gap/=2)
    {
        for(i=gap; i<N; i++)
        {
            tmp = A[i];
            for(j=i; j>0 && A[j-gap]>tmp; j-=gap)
                A[j] = A[j-gap];  //前一位和当前位a[j]交换
            A[j] = tmp;
        }
        showarray(A,N);
    }
}


