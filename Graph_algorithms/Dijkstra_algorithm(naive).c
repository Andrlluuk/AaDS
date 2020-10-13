#include<stdio.h>
#include<stdlib.h>
int main()
{
    int graph_adj[105][105] = { 0 };
    int d[105] = { 0 };
    int v[105] = { 0 };
    int N, start, finish,i,j,min_ind, min,temp,x;
    FILE *fp, *fs;
    fp = fopen("input.txt","rt");
    fs = fopen("output.txt","wt");
    fscanf(fp,"%d\n",&N);
    fscanf(fp,"%d %d\n",&start,&finish);
    while(fscanf(fp,"%d %d",&i,&j) != - 1)
    {
        fscanf(fp,"%d\n",&x);
        graph_adj[j][i] = x;
        graph_adj[i][j] = x;
    }
    for(i = 1; i <= N; i++)
    {
        d[i] = 1005;
        v[i] = 1;
    }
    d[start] = 0;
    do
    {
    min_ind = 1000;
    min = 1000;
    for (int i = 1; i<=N; i++)
    {
      if ((v[i] == 1) && (d[i] < min))
      {
        min = d[i];
        min_ind = i;
      }
    }
        if (min_ind != 1000)
           {
             for (int i = 1; i<=N; i++)
             {
               if (graph_adj[min_ind][i] > 0)
               {
                 temp = min + graph_adj[min_ind][i];
                 if (temp < d[i])
                 {
                   d[i] = temp;
                 }
               }
             }
             v[min_ind] = 0;
           }
         } while (min_ind < 1000);
    if((d[finish] == 0) && (start!=finish))
        fprintf(fs,"no");
    else if (d[finish] == 1005)
        fprintf(fs,"no");
    else
        fprintf(fs,"%d ",d[finish]);
}
