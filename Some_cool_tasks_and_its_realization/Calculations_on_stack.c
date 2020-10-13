#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
} Stack;
int main()
{
    FILE *fs, *fp;
    fs = fopen("input.txt","r");
    fp = fopen("output.txt","w");
    int k;
    char str[10];
    Stack *p, *top, *s;
    fscanf(fs,"%s",str);
    if(str[0]<='9')
    {
        p = (Stack *) malloc(sizeof(Stack));
        k = atoi(str);
        p->data = k;
        p->next = NULL;
        top = p;
    }
    while(fscanf(fs,"%s",str)!= -1)
    {
        if(str[0]>='0')
        {
            p = (Stack *) malloc(sizeof(Stack));
            p->data = atoi(str);
            p->next = top;
            top = p;
        }
        else
            switch((int)str[0])
            {
                case 42:
                    s = top;
                    k = top->data*((top->next)->data);
                    (top->next)->data = k;
                    top = top->next;
                    free(s);
                    break;
                case 43:
                    s = top;
                    k = top->data+((top->next)->data);
                    (top->next)->data = k;
                    top = top->next;
                    free(s);
                    break;
                case 45:
                    s = top;
                    k = ((top->next)->data)-(top->data);
                    (top->next)->data = k;
                    top = top->next;
                    free(s);
                    break;
                case 47:
                    s = top;
                                   k = ((top->next)->data)/top->data;
                                   (top->next)->data = k;
                                   top = top->next;
                                   free(s);
                                   break;
                default:
                    break;
            }
            }
    printf("%d",top->data);
    }
