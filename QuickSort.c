#include <stdio.h>

//用第一个元素将待排序序列划分成左右两个部分
int Partition(int a[], int low, int high)
{
    int pivot=a[low];           //第一个元素作为枢轴
    while(low < high)           //用low、high搜索枢轴的最终位置
    {
        while(low < high && a[high] >= pivot) high--;
        a[low] = a[high];       //比枢轴小的元素移到到左端
        while(low < high && a[low] <= pivot) low++;
        a[high] = a[low];        //比枢轴大的元素移到到右端
    }
    a[low] = pivot;              //枢轴元素存放到最终位置
    return low;                  //返回存放枢轴的最终位置
}
//快速排序
void QuickSort(int a[], int low, int high)
{
    if(low < high)          //递归跳出的条件
    {
        int pivotpos = Partition(a, low, high);//划分
        QuickSort(a, low, pivotpos-1);        //划分左子表
        QuickSort(a, pivotpos+1, high);       //划分右子表
    }
}

void main()
{
    int a[10]={10,29,0,1,23,45,8,4,2,1};

    QuickSort(a, 0, 9);

    for(int i=0;i<10;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}