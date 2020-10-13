#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int minimum(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int maximum(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
typedef struct t {
    int x;
    int y;
} towns;

struct heapitem {
    int priority;
    int value[2];
};
 
typedef struct Heap {
    int maxsize;
    int nitems;
    struct heapitem *items;
} heap;

 heap *heap_create(int maxsize)
{
    heap *h = (heap*)malloc(sizeof(*h));
    if (h != NULL) {
        
        h->maxsize = maxsize;
        h->nitems = 0;
        h->items = malloc(sizeof(struct heapitem) * (maxsize + 1));
        
        if (h->items == NULL) {
            
            free(h);
            return NULL;
        }
    }
    return h;
}
 

void heap_free(heap *h)
{
    
    free(h->items);
    free(h);
}
 
void heap_swap(struct heapitem *a, struct heapitem *b)
{
    struct heapitem temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
}
 
struct heapitem heap_max(heap *h)
{
    
    struct heapitem erritem;
    erritem.priority = -1;
    erritem.value[0] = 0;
    erritem.value[1] = 0;
    if (h->nitems > 0) {
        return h->items[1];
        
    }else {
        fprintf(stderr, "heap: Heap is empty.\n");
        return erritem;
    }
}
 
int heap_insert(heap *h, int priority, int x, int y)
{
    
    int i;
    if (h->nitems >= h->maxsize) {
        fprintf(stderr,"heap: Heap overflow.\n");
        return -1;
    }
    
    h->nitems++;
    h->items[h->nitems].priority = priority;
    h->items[h->nitems].value[0] = x;
    h->items[h->nitems].value[1] = y;
    
    for (i = h->nitems; (i > 1) && (h->items[i].priority < h->items[i / 2].priority); i = i / 2) {
        
        heap_swap(&h->items[i], &h->items[i / 2]);
    }
    
    return 0;
}
 
struct heapitem heap_removemax(heap *h)
{
    
    int k, n, j;
    heap_swap(&h->items[1], &h->items[h->nitems]);
    
    for (k = 1, n = h->nitems - 1; 2 * k <= n; k = j) {
        j = 2 * k;
        if ((j < n) && (h->items[j].priority > h->items[j + 1].priority)) {
            j++;
        }
        
        if (h->items[k].priority <= h->items[j].priority) {
            break;
        }
        
        heap_swap(&h->items[k], &h->items[j]);
    }
    
    return h->items[h->nitems--];
}

int graph_priority(int k, int q, int *priority, int *ind, int *graph, int n, int *number_of_components)
{
    if (priority[k] != priority[q])
    {
        int w = maximum(priority[k], priority[q]);
        int ww = minimum(priority[k], priority[q]);
        for(int i = 1; i <= n; i++)
            if(priority[i] == w)
                priority[i] = ww;
        *number_of_components -= 1;
        return 2;
    }
    else
        return 0;
}


int main()
{
    FILE *fp, *fs;
    fp = fopen("input.txt","rt");
    fs = fopen("output.txt","wt");
    int i,n,m,j,k,q;
    int included = 0;
    struct heapitem maximum;
    fscanf(fp,"%d\n", &n);
    int **d = (int**)malloc((n+5)*sizeof(int*));
    int number_of_components = n;
    towns* town = (towns*)malloc((n+5)*sizeof(towns));
    int* priority = (int*)calloc(n + 5,sizeof(int));
    for( i = 0 ; i < n + 5; i++)
        d[i] = (int*)malloc((n+5)*sizeof(int));
    for(i = 1; i < n+1; i++)
    {
        fscanf(fp,"%d %d\n",&town[i].x,&town[i].y);
        priority[i] = i;
    }
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            if((i == j) || (i > j))
                d[i][j] = -1;
            else
                d[i][j] = abs((town[i].x-town[j].x)*(town[i].x-town[j].x)+(town[i].y-town[j].y)*(town[i].y-town[j].y));
        }
    fscanf(fp,"%d\n", &m);
    if(n == 1)
        return 0;
    int graph = 0;
    int ind = 1;
    for(i = 0; i < m; i++)
    {
        fscanf(fp,"%d %d\n",&k,&q);
        d[k][q] = -1;
        d[q][k] = -1;
        graph_priority(k,q,priority,&ind,&graph,n, &number_of_components);
    }
    int squ = n*n;
    heap *queue = heap_create(squ);
    for(i = 1; i < n + 1; i++)
        for(j = 1; j < n + 1; j++)
            if(d[i][j] >= 0)
                heap_insert(queue,d[i][j],i,j);
   
    while(number_of_components > 1)   {
        maximum = heap_removemax(queue);
        if( graph_priority(maximum.value[0],maximum.value[1], priority, &ind, &graph,n,&number_of_components))
        {
            fprintf(fs,"%d %d\n",maximum.value[0],maximum.value[1]);
        }
    }
    return 0;
}
