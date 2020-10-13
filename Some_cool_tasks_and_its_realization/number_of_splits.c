#include<stdio.h>
#include<stdlib.h>
int main()
{
    int array[1001][1001] = { 0 };
    int n;
    scanf("%d",&n);
    array[0][0] = 1;
    for(int i = 1; i <= n;i++)
        array[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j <= i)
                array[i][j] = (array[i][j-1] + array[i-j][j]) % 1000000007;
            else
                array[i][j] = array[i][i];
        }
    }
    printf("%d",array[n][n]);
}
