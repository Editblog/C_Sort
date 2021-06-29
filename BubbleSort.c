#include <stdio.h>

//交换两个元素的值
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void BubbleSort(int a[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int flag=0;             //表示本趟冒泡是否发生交换的标志
        for(j=n-1;j>i;j--)      //一趟冒泡过程
        {
            if(a[j] < a[j-1])   //若为逆序
            {
                swap(&a[j-1], &a[j]);   //交换
                flag=1;
            }
        }
        if(flag==0)             //本趟遍历没有发生交换，说明表已经有序
            return;
    }
}

void main()
{
    int a[10]={10,5,0,9,2,7,4,7,2,40};

    BubbleSort(a,10);

    for(int i=0;i<10;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}