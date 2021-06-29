#include <stdio.h>

void printstring(int a[], int n);//打印数组
void InsertSort(int a[], int n);//直接插入排序
void InsertSort1(int a[], int n);//直接插入排序（带哨兵）
void InsertSort2(int a[], int n);//折半插入排序

void main()
{
    int a[10]={1,9,0,2,4,2,6,5,8,34};
    int b[11]={-1,1,9,0,2,4,2,6,12,8,34};

    InsertSort(a, 10);
    InsertSort2(b, 11);

    printstring(a,10);
    printstring(b,11);
}

//打印数组
void printstring(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

//直接插入排序
void InsertSort(int a[], int n)
{
    int i, j, temp;
    for(i=1;i<n;i++)            //将各元素插入已排好序的序列中
    {
        if(a[i] < a[i-1])       //若A[i]关键字小于前驱
        {
            temp = a[i];        //用temp暂存A[i]
            for(j=i-1;j>=0 && a[j] > temp;j--)  //检查所有前面已排好序的元素
            {
                a[j+1]=a[j];     //所有大于temp的元素都向后挪位 
            }
            a[j+1]=temp;         //复制到插入位置
        }
    }
}
//直接插入排序（带哨兵）
void InsertSort1(int a[], int n)
{
    int i, j; 
    for(i=2;i<=n;i++)                       //依次将A[2]~A[n]插入到前面已排序序列
    {
        if(a[i] < a[i-1])                   //若A[1]关键码小于其前驱，将A[i]插入有序表
        {
            a[0] = a[i];                    //复制为哨兵，A[0]不存放元素
            for(j=i-1;a[0] < a[j]; j--)     //从后往前查找待插入位置
            {
                a[j+1] = a[j];              //向后挪位
            }
            a[j+1] = a[0];                  //复制到插入位置
        }
    }
}

//折半插入排序
void InsertSort2(int a[], int n)
{
    int i, j ,low, mid, high;
    for(i=2;i<=n;i++)               //依次将a[2]~a[n]插入到前面的已排序序列
    {
        a[0]=a[i];                  //将a[i]暂存到a[0]
        low=1;high=i-1;             //设置折半查找范围
        while(low<=high)            //折半查找（默认递增有序）
        {
            mid = (low+high)/2;     //取中间点
            if(a[mid] > a[0])       //查找左半子表
            {
                high = mid-1;
            }
            else                    //查找有半子表
            {
                low = mid+1;
            }

            for(j=i-1;j>=high+1;j--)
            {
                a[j+1]=a[j];        //统一后移元素，空出插入位置
            }   
            a[high+1] = a[0];       //插入操作
        }

    }
}