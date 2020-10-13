include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Item{
    int weight;
    int cost;
} item;

unsigned long long int max(unsigned long long int a,unsigned long long int b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    FILE *fp;
    fp = fopen("input.txt","r");
    item Cave_item[205];
    _Bool array_of_subjects[205] = { 0 };
    unsigned long long int **arr;
    arr = (unsigned long long int**)malloc(250*sizeof(unsigned long long int*));
    for(int i = 0; i < 250; i++)
        arr[i] = (unsigned long long int*)calloc(50005,sizeof(unsigned long long int));
    int N;
    int MAX_WEIGHT;
    fscanf(fp,"%d ",&N);
    fscanf(fp,"%d\n",&MAX_WEIGHT);
    for(int i = 1; i <= N;i++)
        fscanf(fp,"%d %d\n", &Cave_item[i].weight, &Cave_item[i].cost);
    for(int i = 1; i <= N;i++)
        for(int j = 1; j <= MAX_WEIGHT; j++)
        {
            if(Cave_item[i].weight > j)
                arr[i][j] = arr[i-1][j];
            else
                arr[i][j] = max(arr[i-1][j],arr[i-1][j-Cave_item[i].weight] + Cave_item[i].cost);
        }
   int i = N;
   int j = MAX_WEIGHT;
   int summary = 0;
    int summary_weight = 0;
    while(i != 0)
    {
        if (arr[i][j] != arr[i-1][j])
        {
            array_of_subjects[i] = 1;
            j-= Cave_item[i].weight;
            summary++;
            summary_weight += Cave_item[i].weight;
            i--;
        }
        else
        {
            i--;
        }
    }
    printf("%d %d %d\n",summary,summary_weight,arr[N][MAX_WEIGHT]);
    for(i = 0;i <= N; i++)
        if(array_of_subjects[i])
            printf("%d ",i);
    return 0;
}
