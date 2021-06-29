#include <stdio.h>


void Insertsort(int a[], int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        if(a[i] < a[i-1])
        {
            temp = a[i];
            for(j=i-1;j>=0 && a[j] > temp;j--)
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
        low = 1;
        high = i-1;
        a[0] = a[i];
        while(low <= high)
        {
            mid = (low+high)/2;
            if(a[mid] > a[0])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }

            for(j=i-1;j>=high+1;j--)
            {
                a[j+1] = a[j];
            }
            a[high+1] = a[0];
        }
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
                a[0] = a[i];
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
    int i,j;
    for(i=0;i<n;i++)
    {
        int flag=0;
        for(j=n-1;j>i;j--)
        {
            if(a[j] < a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag=1;
            }
        }
        if(flag==0) return;
    }
}

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low < high)
    {
        while(low<high && a[high] >= pivot) high--;
        a[low] = a[high];
        while(low<high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[],int low, int high)
{
    if(low < high)
    {
        int pivotpos = Partition(a,low,high);
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}

void main()
{
    int i;
    int a[10]={5,3,0,12,9,20,5,97,100,32};
    int b[11]={0,5,3,0,12,9,20,5,97,100,32};

    BubbleSort(a,10);
    QuickSort(b,1,10);

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
