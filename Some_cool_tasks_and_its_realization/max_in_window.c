#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
int maxVal(int x, int y)
{
    return (x > y)? x: y;
}
  
int Middle(int begin, int end)
{
    return begin + (end - begin)/2;
}
  
int Finder_maximum(int *array, int start, int end, int requeststart, int requestend, int node)
{
    if ((requeststart <= start) && (requestend >= end))
        return array[node];
    if (end<requeststart || start>requestend)
    return INT_MIN;
    int mid = Middle(start, end);
    return maxVal(Finder_maximum(array, start, mid, requeststart, requestend, 2*node+1),
                  Finder_maximum(array, mid+1, end, requeststart, requestend, 2*node+2));
}
  
  
int construct_segment_tree(int *arr, int start, int end, int *ar, int node)
{

    if (start == end)
    {
        ar[node] = arr[start];
        return arr[start];
    }
  
    int mid = Middle(start, end);
    ar[node] =  maxVal(construct_segment_tree(arr, start, mid, ar, node*2+1),
                     construct_segment_tree(arr, mid+1, end, ar, node*2+2));
    return ar[node];
}
  
int *construct_tree(int *arr, int n)
{
    
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *ar;
    ar = (int*)malloc(max_size * sizeof(int));
    construct_segment_tree(arr, 0, n-1, ar, 0);
    return ar;
}
int main()
{
    int *arr;
    int n;
    int *tr;
    FILE *fp;
    fp = fopen("input.txt","r");
    char symb;
    fscanf(fp,"%d",&n);
    arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n;i++)
    {
        fscanf(fp,"%d",&arr[i]);
    }
    tr = construct_tree(arr, n);
    fscanf(fp,"%c",&symb);
    int right = -1;
    int left = 0;
   for(int i = 0;i < 2*n -1;i++)
      {
          fscanf(fp,"%c",&symb);
          if (symb == 'R')
              right++;
          else left++;
          printf("%d\n",Finder_maximum(tr,0,n-1,left,right,0));
      }
    return 0;
}
