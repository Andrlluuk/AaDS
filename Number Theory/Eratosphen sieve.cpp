#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
int n;
int i,k;
k=0;
scanf("%d",&n);
int arr[1000000] ;
for(i=0;i<=n;i++) arr[i]=0;
for(int i=2;i<=sqrt(n);i++)
if (arr[i]==0)
for(int k=i*i;k<=n;k+=i)
arr[k]= 1;


for(i=2;i<=n;i++)
if(arr[i] == 0)
printf("%d ", i);
return 0;
}
