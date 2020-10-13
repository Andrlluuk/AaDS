#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char val[50];
    struct node *left;
    struct node *right;
};
struct node * addnode( struct node *tree, char *word) {
    if (tree == NULL) {
        tree =(struct node *)malloc(sizeof(struct node));
        strcpy(tree->val, word);
        tree->left =  NULL;
        tree->right = NULL;
    }else  if (strcmp(word,tree->val)>0)
        tree->right = addnode(tree->right,word);
    else if (strcmp(word,tree->val)<0)
        tree->left = addnode(tree->left,word);
    return(tree);
}
void print(struct node *tree)
{
    if(tree!=NULL)
    {
        print(tree->left);
        puts(tree->val);
        print(tree->right);
    }
}
int main()
{
    int p, lev, x;
    char word[50];
    struct node *root=NULL;
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    gets(word);
    root=(struct node *)malloc(sizeof(struct node));
    strcpy(root->val, word);
    root->left =  NULL;
    root->right = NULL;
    while(gets(word)!=0)
    {
        addnode(root,word);
    }
    print(root);
    return 0;
}
