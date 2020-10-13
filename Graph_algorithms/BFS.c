#include <stdio.h>
#include <string.h>
#define inf 200001

typedef struct list {
    int data;
    struct list* next;
} list;

typedef struct Deck {
    int length;
    int tail;
    int head;
    int count;
    int* arr;
} deck;

int full(deck s, int n)
{
    if (s.count == 2*n)
        return 1;
    else
        return 0;
}

int empty(deck s)
{
    if (s.count == 0)
        return 0;
    else
        return 1;
}

int get_back(deck* s)
{
    if (s->count == 0)
        return 0;
    else
    {
        s->count--;
        s->tail++;
        return(s->arr[s->tail]);
    }
}

void push_front(deck* s, int x)
{
    if(!s->count)
    {
        s->arr[1] = x;
        s->count = 1;
    }
    else
    {
        s->count++;
        s->head++;
        s->arr[s->head] = x;
    }
}



int main()
{
    deck queue;
    FILE *fp, *fs;
    fp = fopen("input.txt","rt");
    fs = fopen("output.txt","wt");
    int i,n, m, len, x, card,j,k,p,q;
    int flag_r = 0;
    fscanf(fp,"%d %d\n", &n, &m);
    queue.arr = (int*)malloc((n + 1) * sizeof(int));
    queue.length = n + 1;
    queue.tail = 1;
    queue.head = 1;
    queue.count = 0;
    list** graph_adj = (list**)malloc((n+1) * sizeof(list*));
    list* previous = (list*)malloc(sizeof(list));
    list* current = (list*)malloc(sizeof(list));
    int* coloring = (int*)calloc(n+1,sizeof(int));
    int* d = (int*)calloc(n+1,sizeof(int));
    int* parent = (int*)calloc(n+1,sizeof(int));
    for (i = 1; i <= n; i++)
    graph_adj[i] = 0;
    for (i = 0; i <= m - 1; i++)
    {
        fscanf(fp,"%d%d", &j, &k);
        current = graph_adj[j];
        previous = graph_adj[j];
        list* last = (list*)malloc(sizeof(list));
        last->data = k;
        last->next = NULL;
        if (previous == NULL)
            graph_adj[j] = last;
        else
        {
            while (current != NULL)
        {
            previous = current;
            current = current->next;
        }
            previous->next = last;
        }
    }
    d[1] = 0;
    parent[1] = 0;
    for(i = 2; i <= n; i++)
    {
        coloring[i] = 0;
        d[i] = -1;
        parent[i] = 0;
    }
    push_front(&queue,1);
    coloring[1] = 1;
    while(empty(queue))
    {
        p = queue.arr[queue.tail];
        list* tmp;
        tmp = (list*)malloc(sizeof(list));
        if (graph_adj[p] != NULL)
        {
            tmp = graph_adj[p];
            while (tmp->next != NULL)
            {
                if (coloring[tmp->data] == 0)
                {
                    coloring[tmp->data] = 1;
                    parent[tmp->data] = p;
                    d[tmp->data] = d[p] + 1;
                    push_front(&queue,tmp->data);
                }
                tmp = tmp->next;
            }
            if (coloring[tmp->data] == 0)
            {
                coloring[tmp->data] = 1;
                parent[tmp->data] = p;
                d[tmp->data] = d[p] + 1;
                push_front(&queue,tmp->data);
            }
        }
        q = get_back(&queue);
        coloring[p] = 2;
    }
    for(i = 1; i <= n; i++)
        fprintf(fs,"%d\n",d[i]);
    return 0;
}
