#include <stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list* next;
} list;

void search(list **graph_adj, int* components, int* coloring, int u, int n)
{
list* tmp;
tmp = (list*)malloc(sizeof(list));
    coloring[u] = 1;
    components[u] = n;
    if (graph_adj[u] != NULL)
    {
        tmp = graph_adj[u];
        while (tmp->next != NULL)
        {
            if (coloring[tmp->data] == 0)
                search(graph_adj, components, coloring, tmp->data, n);
            tmp = tmp->next;
        }
        if (coloring[tmp->data] == 0)
            search(graph_adj, components, coloring, tmp->data, n);
        coloring[u] = 2;
    }
}

int main()
{
    int n, m, k, j, nk = 0;
    scanf("%d%d", &n, &m);
    list** graph_adj = (list**)malloc((n+1) * sizeof(list*));
    list* previous = (list*)malloc(sizeof(list));
    list* current = (list*)malloc(sizeof(list));
    int* coloring = (int*)calloc(n+1,sizeof(int));
    int* components = (int*)calloc(n+1,sizeof(int));
    for (int i = 1; i <= n; i++)
    graph_adj[i] = 0;
    for (int i = 0; i <= m - 1; i++)
    {
        scanf("%d%d", &j, &k);
        current = graph_adj[j];
        previous = graph_adj[j];
        while (current != NULL)
        {
            previous = current;
            current = current->next;
        }
        list* last = (list*)malloc(sizeof(list));
        last->data = k;
        last->next = NULL;
        if (previous == NULL)
            graph_adj[j] = last;
        else
            previous->next = last;
        current = graph_adj[k];
        previous = graph_adj[k];
        while (current != NULL)
        {
            previous = current;
            current = current->next;
        }
        last = (list*)malloc(sizeof(list));
        last->data = j;
        last->next = NULL;
        if (previous == NULL)
            graph_adj[k] = last;
        else
            previous->next = last;
    }
    for (int i = 1; i <= n; i++)
    {
        if (coloring[i] == 0)
        {
            nk++;
            search(graph_adj, components, coloring, i, nk);
        }
    }
    printf("%d\n", nk);
    for (int i = 1; i <= n; i++)
        printf("%d ", components[i]);
    return 0;
}
