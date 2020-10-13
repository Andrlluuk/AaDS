#include<stdio.h>
#include<stdlib.h>
struct node {
    int val;
    struct node *left;
    struct node *right;
};
struct node * addnode(int x, struct node *tree) {
    if (tree == NULL) {
        tree =(struct node *)malloc(sizeof(struct node));
        tree->val = x;
        tree->left =  NULL;
        tree->right = NULL;
    }else  if (x < tree->val)
        tree->left = addnode(x,tree->left);
    else if (x > tree->val)
        tree->right = addnode(x,tree->right);
    return(tree);
}
int height(struct node *tree)
{
    if(tree==NULL)
    return -1;
    int hl=height(tree->left);
    int hr=height(tree->right);
    if (hl<hr)
    {
        hr++;
        return hr;
    }
    else
    {
        hl++;
        return hl;
    }
}
int main()
{
    int p,x;
    struct node *root=NULL;
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    scanf("%d",&x);
      root=(struct node *)malloc(sizeof(struct node));
        root->val = x;
        root->left =  NULL;
        root->right = NULL;
    while(scanf("%d",&x)!=-1)
    {
       addnode(x,root);
    }
  p=height(root);
  printf("%d",p);
}
