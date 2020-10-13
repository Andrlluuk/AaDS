#include<stdio.h>
#include<stdlib.h>
int Get_index(int *arr, int *t, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (arr[t[m]] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}
int LIS(int *arr, int n, int *d, int *p)
{
    int *tail = (int*)calloc(n, sizeof(int));
    int *prev = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        prev[i] = -1;
        tail[i] = 0;
    }
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[tail[0]]) {
            tail[0] = i;
        }
        else if (arr[i] > arr[tail[len - 1]]) {
            prev[i] = tail[len - 1];
            tail[len++] = i;
        }
        else {
            int pos = Get_index(arr, tail, -1, len - 1, arr[i]);
            prev[i] = tail[pos - 1];
            tail[pos] = i;
        }
    }
    int j = 0;
    for (int i = tail[len - 1]; i >= 0; i = prev[i])
    {
        if((j <= n) && (i <= n))
        {
        d[j] = arr[i];
        p[j] = i;
        j++;
        }
        else break;
    }
    return len;
}
  
int main()
{
    FILE *fp;
    fp = fopen("input.txt","r");
    int n;
    int arr[100500] = { 0 };
    int d[100500] = { 0 };
    int p[100500] = { 0 };
    fscanf(fp,"%d\n",&n);
    for(int i = 0; i < n; i++)
        fscanf(fp,"%d\n",&arr[i]);
    int q = LIS(arr, n,d,p);
    printf("%d\n",q);
    for(int i = q - 1; i >= 0; i--)
        printf("A[%d] = %d\n",p[i]+1,d[i]);
    return 0;
}
