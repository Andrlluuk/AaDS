#include<stdio.h>
#include<string.h>
#include<math.h>
void glavelem( int s, double mas[200][201], int q, int otv[])
{
    int i, j, i_max = s, j_max = s;
    double temp;
    for (i=s;i<q;i++)
    {
        for (j=s;j<q;j++)
        {
            if (fabs(mas[i][j])>fabs(mas[i_max][j_max]))
            {
                i_max = i;
                j_max = j;
            }
        }
    }
    for ( j = s; j < q + 1; j++ )
    {
        temp = mas[s] [j];
        mas[s] [j] = mas[i_max] [j];
        mas[i_max] [j] = temp;
    }
    for ( i = 0; i < q; i++ )
    {
        temp = mas[i] [s];
        mas[i] [s] = mas[i] [j_max];
        mas[i] [j_max] = temp;
    }
    i = otv[s];
    otv[s] = otv[j_max];
    otv[j_max] = i;
}

int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    double arr[200][201];
    int otv[200];
    double x[200];
    for(i=0;i<n;i++)
        for(j=0;j<n+1;j++)
            scanf("%lf",&arr[i][j]);
    for(i = 0;i < n ; i++ )
        otv[i] = i;
    for ( k = 0; k < n; k++ )
    {
        glavelem( k, arr, n, otv );
        for ( j = n; j >= k; j-- )
            arr[k] [j] /= arr[k] [k];
        for ( i = k + 1; i < n; i++ )
            for ( j = n; j >= k; j-- )
                arr[i] [j] -= arr[k] [j] * arr[i] [k];
    }
    for ( i = 0; i < n; i++ )
        x[i] =arr[i][n];
    for ( i = n - 2; i >= 0; i-- )
        for ( j = i + 1; j < n; j++ )
            x[i] -= x[j] *arr[i][j];
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            if ( i == otv[j] )
            {
                printf( "%f\n", x[j] );
                break;
            }
}
