#include <stdio.h>

int b[11];

void Merge(int a[],int low,int mid,int high)
{
    int i,j,k;
    for(k=low;k<=high;k++)
    {
        b[k] = a[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++)
    {
        if(b[i] <= b[j])
        {
            a[k] = b[i++];
        }
        else
        {
            a[k] = b[j++];
        }
    }
    while(i<=mid)   a[k++] = b[i++];
    while(j<=high)  a[k++] = b[j++];
}

void MergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}

void main()
{
    int a[10]={10,2,1,9,6,7,5,0,3,2};


    MergeSort(a,0,9);

    for(int i=0;i<10;i++) 
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}