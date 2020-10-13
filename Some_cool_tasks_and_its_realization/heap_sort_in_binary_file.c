#include<stdio.h>
#include<math.h>
void swap(int i,int j,int *arr)
{
    int tmp;
    tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
void shifting(int i,int n,int *arr)
{
    int r;
    while(2*i<=n)
    {
        r=2*i;
        if((r+1<=n) && (arr[r]<arr[r+1]))
            r++;
        if(arr[i]<arr[r])
        {
            swap(i,r,arr);
            i=r;
        }
        else return;
    }
}
int main()
{
    int res, n, i,p;
    FILE *fp;
    int arr[500005];
    fp=fopen("input.bin","rb");
    fread(&p ,sizeof(int), 1,fp);
        for(i = 1 ; i <= p; i++)
        fread(&arr[i], sizeof(int), 1, fp);
        fclose (fp);
        fp = fopen( "output.bin", "wb" );
            i=p/2;
            while(i>=1)
            {
                shifting(i,p,arr);
                i--;
            }
            i=p;
            while(i>1)
            {
                swap(1,i,arr);
                i--;
                shifting(1,i,arr);
            }
            for(i=1;i<=p;i++)
            {
            fwrite ( &arr[i], 4, 1, fp );
                printf("%d",arr[i]);
            }
        fclose ( fp );
        return 0;
    }
