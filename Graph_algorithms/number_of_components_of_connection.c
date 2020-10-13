#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

void search(int u, int nk, int* coloring, int* components, int **graph_adj,int n)
{
    coloring[u] = 1;
    components[u] = nk;
    for (int i = 1; i <= n; i++)
    {
        if (graph_adj[u][i] == 1)
        {
            if (coloring[i] == 0)
                search(i, nk, coloring, components, graph_adj,n);
        }
    }
    coloring[u] = 2;
}
int depth_first_search(int *coloring, int* components, int **graph_adj, int n)
{
    int nk = 0;
    for (int p = 1; p <= n; p++)
        if (!coloring[p])
        {
            nk++;
            search(p, nk, coloring, components, graph_adj,n);
        }
    return nk;
}
int main()
{
    FILE *fp,*fs;
    fp = fopen("input.txt","rt");
    fs = fopen("output.txt","wt");
    int i, j, k, m, n, number,res;
    int nnk = 0;
    fscanf(fp,"%d\n", &n);
    int *coloring = (int*)calloc(n+2, sizeof(int));
    int *components = (int*)calloc(n+2, sizeof(int));
    int **graph_adj = (int**)calloc(n+2, sizeof(int*));
    for(i = 0; i < n+2; i++)
    {
        graph_adj[i] = (int*)calloc(n+2,sizeof(int));
    }
        while(fscanf(fp,"%d %d\n", &j, &k) != EOF)
        {
        graph_adj[j][k] = 1;
        graph_adj[k][j] = 1;
        }
    k = depth_first_search(coloring, components, graph_adj,n);
    if (n == 1)
    {
        fprintf(fs,"1");
        return 0;
    }
    fprintf(fs,"%d\n",k);
    return 0;
}
