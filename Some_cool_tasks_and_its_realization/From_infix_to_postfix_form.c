#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct stack {
    char data;
    int number;
    struct stack *next;
} Stack;

int indexation(char c)
{
    int d;
    if ((int) c == 40)
        d = 1;
    else if ((int) c == 41)
        d = 2;
    else if ((int) c == 61)
        d = 3;
    else if ((int) c == 43)
        d = 4;
    else if ((int) c == 45)
        d = 4;
    else if ((int) c == 47)
        d = 5;
    else if ((int) c == 42)
        d = 5;
    return d;
}
int main()
{
    FILE *fs, *fp;
    fs = freopen("input.txt","r",stdin);
    Stack *top = NULL;
    int val;
    char c;
    Stack *p, *k, *j;
    fscanf(fs,"%c",&c);
    while(isalpha(c))
    {
        printf("%c",c);
        fscanf(fs,"%c",&c);
    }
    p = (Stack *) malloc(sizeof(Stack));
    p->data = c;
    p->next = top;
    p->number = indexation(c);
    top = p;
    while(fscanf(fs,"%c",&c) != -1)
    {
        if(isalpha(c)) printf("%c",c);
        if(c == '(')
            {
                p = (Stack *) malloc(sizeof(Stack));
                p->data = c;
                p->next = top;
                p->number = indexation(c);
                top = p;
            }
        if(c == ')')
            {
                while(top->data != '(')
                {
                    printf("%c",top->data);
                    top = top->next;
                    free(p);
                    p = top;
                }
                top = top ->next;
                free(p);
                p = top;
            }
        if((indexation(c) > 2) && (indexation(c) < 6))
        {
            while ((top != NULL) && (top->number >= indexation(c)))
            {
                printf("%c", top->data);
                top = top->next;
                free(p);
                p = top;
            }
            p = (Stack *) malloc(sizeof(Stack));
            p->data = c;
            p->next = top;
            p->number = indexation(c);
            top = p;
        }
    }
    while(top != NULL)
    {
        printf("%c",top -> data);
        top = top->next;
        free(p);
        p = top;
    }
    free(top);
    return 0;
}
