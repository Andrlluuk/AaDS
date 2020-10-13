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
void printprefix(struct node *tree) {
    if (tree!=NULL) {
       printf("%d ",tree->val);
        printprefix(tree->left);
        printprefix(tree->right);
    }
}
void printinfix(struct node *tree)
{
    if(tree!=NULL)
    {
        printinfix(tree->left);
        printinfix(tree->right);
        printf("%d ",tree->val);
    }
}
int main()
{
    int x;
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
    printprefix(root);
    printf("\n");
    printinfix(root);
}
