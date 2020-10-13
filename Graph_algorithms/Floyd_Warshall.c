#include<stdio.h>
#include<stdlib.h>

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

void Floyd_Warshall(int **D, int **graph_adj, int n)
{
    for(int i = 0; i < n + 5; i++)
        for(int j = 0; j < n + 5; j++)
            D[i][j] = graph_adj[i][j];
    for(int k = 0; k < n+5; k++)
        for(int i = 0; i < n +5 ; i++)
            for(int j = 0; j < n+5; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

int main()
{
    int n,m,vert1, vert2,s,tests,start,finish;
    FILE *fp, *fs;
    fp = fopen("input.txt","rt");
    fs = fopen("output.txt","wt");
    fscanf(fp,"%d %d\n",&n,&m);
    int **graph_adj = (int**)malloc((n+5)*sizeof(int*));
    int **D = (int**)malloc((n+5)*sizeof(int*));
    for(int i = 0; i < n+5;i++)
    {
        graph_adj[i] = (int*)calloc(n+5,sizeof(int));
        D[i] = (int*)calloc(n+5,sizeof(int));
    }
    for(int i = 0; i < n+5; i++)
        for(int j = 0; j < n+5; j++)
        {
            if(i != j)
                graph_adj[i][j] = 400000;
            else
                graph_adj[i][j] = 0;
        }
    for(int i = 0; i < m;i++)
    {
        fscanf(fp,"%d %d %d\n",&vert1, &vert2, &s);
        if(graph_adj[vert1][vert2] > s)
        {
        graph_adj[vert1][vert2] = s;
        graph_adj[vert2][vert1] = s;
        }
    }
    fscanf(fp,"%d\n", &tests);
    Floyd_Warshall(D,graph_adj,n);
    for(int i = 0; i < tests; i++)
    {
        fscanf(fp,"%d %d\n",&start,&finish);
        fprintf(fs,"%d\n",D[start][finish]);
    }
    return 0;
}
