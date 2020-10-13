#include <stdio.h>

void search(char **graph_adj, int i, int j, int n, int nk)
{
    graph_adj[i][j] = 1;
    if(i > 0)
          if(!graph_adj[i-1][j])
              search(graph_adj,i-1,j,n,nk);
    if(j > 0)
        if(!graph_adj[i][j-1])
            search(graph_adj,i,j-1,n,nk);
    if(i < n - 1)
        if(!graph_adj[i+1][j])
            search(graph_adj,i+1,j,n,nk);
    if(j < n - 1)
        if(!graph_adj[i][j+1])
            search(graph_adj,i,j+1,n,nk);
    graph_adj[i][j] = 2;
}

int main()
{
    int i, j, n, nk = 0;
    char c, shlak;
    scanf("%d\n", &n);
    char** graph_adj = (char**)malloc((n+1) * sizeof(char*));
    for (int i = 0; i < n + 1; i++)
    {
        graph_adj[i] = (char*)malloc((n+1)*sizeof(char));
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%c",&graph_adj[i][j]);
            if(graph_adj[i][j] == '*')
                graph_adj[i][j] = 3;
            else
                graph_adj[i][j] = 0;
        }
    scanf("%c",&shlak);
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if(graph_adj[i][j] == 0)
            {
                search(graph_adj,i,j,n,nk);
                nk++;
            }
        }
    
    printf("%d",nk - 1);
       return 0;
}
