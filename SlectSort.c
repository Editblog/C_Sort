#include <stdio.h>

void printstring(int a[], int n);//打印数组
void SelectSort(int a[], int n);//希尔排序


void main()
{
    int b[11]={-1,1,9,0,2,4,2,6,12,8,34};

    SelectSort(b, 11);
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
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}
