#include <stdio.h>

void printstring(int a[], int n);//打印数组
void Shellsort(int a[], int n);//希尔排序


void main()
{
    int b[11]={-1,1,9,0,2,4,2,6,12,8,34};

    Shellsort(b, 11);
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

//希尔排序
void Shellsort(int a[], int n)
{
    int i,j,d;
    //a[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
    
    for(d=n/2;d>=1;d=d/2)
    {
        for(i=d+1;i<=n;i++)
        {
            if(a[i] < a[i-d])
            {
                a[0] = a[i];
                for(j=i-d;j>0 && a[j] > a[0];j-=d)
                {
                    a[j+d] = a[j];
                }
                a[j+d] = a[0];
            }
        }
    }
}
