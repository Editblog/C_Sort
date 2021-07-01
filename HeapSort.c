#include <stdio.h>

//将以k为根的子树调整为大根堆
void HeadAdjust(int a[],int k,int len)
{
    a[0] = a[k];                //a[0]暂存子树的根结点
    for(int i=2*k;i<=len;i*=2)  //沿着key较大的子结点向下筛选
    {
        if(i<len&&a[i]<a[i+1])  //取得key较大的子结点的下标
        {
            i++;
        }
        if(a[0] >= a[i])        //筛选结果
        {
            break;
        }
        else
        {
            a[k] = a[i];        //将a[i]调整到双亲结点上
            k = i;              //修改k值，以便继续向下筛选
        }
    }
    a[k] = a[0];                //被筛选结点的值放入最终位置
}

//建立大根堆
void BuildMaxHeap(int a[],int len)
{
    for(int i=len/2;i>0;i--)    //从后往前调整所有非终端结点
    {
        HeadAdjust(a,i,len);
    }
}

//堆排序的完整逻辑
void HeapSort(int a[],int len)
{
    BuildMaxHeap(a,len);        //建立初始的堆
    for(int i=len;i>1;i--)      //n-1趟的交换和建堆过程
    {
        int temp = a[i];        //堆顶元素和堆底元素交换
        a[i] = a[1];
        a[1] = temp;
        HeadAdjust(a,1,i-1);    //把剩余的待排序元素整理成堆
    }
}

void main()
{
    int a[11]={0,10,29,0,1,23,45,8,4,2,1};

    HeapSort(a, 10);

    for(int i=0;i<11;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}