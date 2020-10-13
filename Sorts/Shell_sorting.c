#include<stdio.h>
#include<math.h>
void insert(int b, int h, int *arr, int n)
{
    int i=b+h;
    while(i<n)
    {
        int x=arr[i];
        int j=i-h;
        while((j>=b) && (arr[j]>x))
        {
            arr[j+h]=arr[j];
            j=j-h;
        }
       arr[j+h]=x;
        i=i+h;
    }
}
int main()
{
    int i,j,n;
    int arr[1000000];
    int h = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    while(h<(n-1)/3)
        h=3*h+1;
    while(h>=1)
    {
        for(j=0;j<h;j++)
        {
            insert(j,h,arr,n);
        }
    h=(h-1)/3;
    }
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
