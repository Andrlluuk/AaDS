#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap
{
    int *tree;
    int size;
} heap;

heap* create(int Q)
{
    heap *h;
    h = (heap *)malloc(sizeof(heap));
    h -> size = 0;
    h -> tree = (int *)calloc(Q, sizeof(int));
    return h;
}

int parent(int i)
{
    return i/2;
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return 2*i + 1;
}

int size(heap* h)
{
    return h->size;
}

void swap(int* a, int* b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}

void sifting_up(heap* h, int i)
{
    if (i == 1)
        return;
    if (h->tree[i] <= h->tree[parent(i)])
    {
        swap(&h->tree[i], &h->tree[parent(i)]);
        sifting_up(h, parent(i));
    }
}

void sifting_down(heap* h, int i)
{
    int l, r, largest;
    l = left(i);
    r = right(i);
    if ((l <= size(h)) && (h->tree[l] < h->tree[i]))
        largest = l;
    else
        largest = i;
    if ((r <= size(h)) && (h->tree[r] < h->tree[largest]))
        largest = r;
    if (largest != i)
    {
        swap(&h->tree[i], &h->tree[largest]);
        sifting_down(h, largest);
    }
}

void heap_insert(heap* h, int x)
{
    int i = ++(h->size);
    h->tree[i] = x;
    sifting_up(h, i);
}

int heap_extract_min(heap* h)
{
    int min = h->tree[1];
    h->tree[1] = h->tree[size(h)];
    (h->size)--;
    if (size(h) != 0)
        sifting_down(h, 1);
    return min;
}

int main()
{
    int n;
    char str[200000];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    heap *h = create(n);
    gets(str);
    for (int i = 0; i < n; i++)
    {
        gets(str);
        if (str[1] == 'u')
        {
            int num = 0, j = 5, minus = 1;
            if (str[j] == '-')
            {
                minus = -1;
                j++;
            }
            while((str[j] != '\n') && (str[j] != '\0'))
            {
                num = num*10 + str[j++] - '0';
            }
            num *= minus;
            heap_insert(h, num);
        }
        else
            if (size(h) != 0)
                printf("%d\n", heap_extract_min(h));
            else
                printf("Heap is empty\n");
    }
    return 0;
}
