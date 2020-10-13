#include<string.h>
#include<stdio.h>
#include<math.h>
void quicksort(int *arr,int first,int last)
{
    int i;
    if(first<last)
    {
         int l = first;
         int r = last;
         int middle = arr[(l+r)/2];
         do
         {
             while(arr[l]<middle) l++;
             while(arr[r]>middle) r--;
             if (l<=r)
             {
                 int swap = arr[l];
                 arr[l] = arr[r];
                 arr[r] = swap;
                 l++;
                 r--;
             }
         } while(l<=r);
        quicksort(arr,first,r);
        quicksort(arr,l,last);
         }
}
int main()
{
    int i,j,k;
    double p;
    int n,begin;
    double min,sum;
    int arr[1000000];
    scanf("%d",&n);
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=(double) arr[i]/n;
    }
    min=sum;
    begin=0;
    for(i=0;i<n;i++)
    {
        if(fabs(arr[i]-sum)<min)
        {
            min=fabs(arr[i]-sum);
            begin=i;
        }
    }
    quicksort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
    }
