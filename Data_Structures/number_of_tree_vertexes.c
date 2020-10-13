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
int leafs(struct node *root)

{
 int result;
 if ((root->left==NULL)&&(root->right==NULL))
  result=1;
 else
  result=0;
 if (root->left)
  result+=leafs(root->left);
 if (root->right)
  result+=leafs(root->right);
 return result;
}
int main()
{
    int g = 0, x;
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
    g = leafs(root);
  printf("%d",g);
}
