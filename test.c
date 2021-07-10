#include <stdio.h>


void Insertsort(int a[], int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        if(a[i] < a[i-1])
        {
            temp = a[i];
            for(j=i-1;j>=0&&a[j] > temp;j--)
            {
                a[j+1] = a[j];
            }
            a[j+1] = temp;
        }
    }
}

void Insertsort1(int a[], int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(a[i] < a[i-1])
        {
            a[0] = a[i];
            for(j=i-1;a[j] > a[0];j--)
            {
                a[j+1] = a[j];
            }
            a[j+1] = a[0];
        }
    }
}

void Insertsort2(int a[], int n)
{
    int i,j,low,mid,high;
    for(i=2;i<=n;i++)
    {
        a[0] = a[i];
        low = 1;
        high = i-1;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(a[mid] > a[0])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        for(j=i-1;j>=high+1;j--)
            {
                a[j+1] = a[j];
            }
            a[high+1] = a[0];
    }
}

void ShellSort(int a[],int n)
{
    int i,j,d;
    for(d=n/2;d>=1;d=d/2)
    {
        for(i=d+1;i<=n;i++)
        {
            if(a[i] < a[i-d])
            {
                a[0]= a[i];
                for(j=i-d;j>0&&a[j] > a[0];j-=d)
                {
                    a[j+d] = a[j];
                }
                a[j+d] = a[0];
            }
        }
    }
}

void BubbleSort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        int flag = 0;
        for(j=n-1;j>i;j--)
        {
            if(a[j] < a[j-1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag = 1;
            }
        }
        if(flag==0) return;
    }
}

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low<high)
    {
        while(low<high&&a[high] >= pivot) high--;
        a[low] = a[high];
        while(low<high&&a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[],int low, int high)
{
    if(low<high)
    {
        int pivotpos = Partition(a,low,high);
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}

//简单选择排序
void SelectSort(int a[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}


//将以k为根的子树调整为大根堆
void HeadAdjust(int a[],int k,int len)
{
    a[0] = a[k];
    for(int i=k*2;i<=len;i*=2)
    {
        if(i<len&&a[i] < a[i+1])
        {
            i++;
        }
        if(a[0] >= a[i])
        {
            break;
        }
        else
        {
            a[k] = a[i];
            k = i;
        }
        a[k] = a[0];
    }
}

//建立大根堆
void BuildMaxHeap(int a[],int len)
{
    for(int i=len/2;i>=0;i--)
    {
        HeadAdjust(a,i,len);
    }
}

//堆排序的完整逻辑
void HeapSort(int a[],int len)
{
    BuildMaxHeap(a,len);
    for(int i=len;i>1;i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        HeadAdjust(a,1,i-1);
    }
}

//归并排序
void Merge(int a[],int low,int mid,int high)
{//a[low...mid]和a[mid+1...high]各自有序，将两个部分归并
    int i,j,k;
    for(k=low;k<=high;k++)
    {
        b[k] = a[k];
    }

    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
    {
        if(b[i] < b[j])
        {
            a[k] = b[i++];
        }
        else
        {
            a[k] = b[j++];
        }
    }
    while(i<=mid) a[k++] = b[i++];
    while(j<=high) a[k++] = b[j++];
}


void main()
{
    int i;
    int a[10]={5,3,0,12,9,20,5,97,100,32};
    int b[11]={0,5,3,0,12,9,20,5,97,100,32};

    SelectSort(a,10);
    HeapSort(b,10);

    for(i=0;i<10;i++) 
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

    for(i=0;i<11;i++)
    {
        printf("%d\t",b[i]);
    }
    printf("\n");
}
