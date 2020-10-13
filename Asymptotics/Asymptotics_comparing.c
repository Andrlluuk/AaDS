#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fs, *fp;
    fs = fopen("input.txt","r");
    fp = fopen("output.txt","w");
    char string1[50];
    char string2[50];
    char nstring1[10];
    char nstring2[10];
    char expstring1[10];
    char expstring2[10];
    char logstring1[13];
    char logstring2[13];
    char trashstring1[5];
    char trashstring2[5];
    char trash;
    float log1 = 0,log2 = 0;
    float x1 = 0 ,x2 = 0, n1 = 0, n2 = 0;
    int n,i,q,len1,len2;
    fscanf(fs, "%d", &n);
    fscanf(fs, "%d", &n);
    for(int j = 0; j < n; j++)
    {
        fgets(string1, 45, fs);
        fgets(string2, 45, fs);
        len1 = strlen(string1);
        len2 = strlen(string2);
        if(string1[len1-1] = '\n') string1[len1-1] = '\0';
        if(string2[len2-1] = '\n') string2[len2-1] = '\0';
        if(!strcmp(string1, "O( 1 )"))
        {
            x1 = 0;
            n1 = 0;
            log1 = 0;
        }
        else
        {
            char *part1 = strtok(string1, " ");
            while (part1 != NULL)
            {
                if (part1[0] == 'O')
                    strcpy(trashstring1, part1);
                if (part1[0] == 'N')
                    strcpy(nstring1, part1);
                if (part1[0] == 'l')
                    strcpy(logstring1, part1);
                if ((part1[0] <= '9') && (part1[0] >= '0'))
                    strcpy(expstring1, part1);
                part1 = strtok(NULL, " ");
            }
                q = strlen(expstring1);
                if (q >= 3)
                {
                expstring1[q - 2] = '\0';
                n1 = atof(expstring1);
                if (n1 == 1) n1 = 0;
                }
                else n1 = 0;
                len1 = strlen(nstring1);
                if(len1>=1)
                {
                if(!strcmp(nstring1, "N")) x1 = 1;
                else
                    x1 = atof(nstring1+2);
                }
                len1 = strlen(logstring1);
               if(len1>=1)
               {
                if (!strcmp(logstring1,"logN")) log1 = 1;
                else
                    log1 = atof(logstring1+5);
               }
        }
        if(!strcmp(string2, "O( 1 )"))
        {
            x2= 0;
            n2 = 0;
            log2 = 0;
        }
        else
        {
            char *part2 = strtok(string2, " ");
            while (part2 != NULL)
            {
                if (part2[0] == 'O')
                    strcpy(trashstring2, part2);
                if (part2[0] == 'N')
                    strcpy(nstring2, part2);
                if (part2[0] == 'l')
                    strcpy(logstring2, part2);
                if ((part2[0] <= '9') && (part2[0] >= '0'))
                    strcpy(expstring2, part2);
                part2 = strtok(NULL, " ");
            }
             q = strlen(expstring2);
             if (q >= 3)
             {
             expstring2[q - 2] = '\0';
             n2 = atof(expstring2);
             if (n2 == 1) n2 = 0;
             }
             else n2 = 0;
            len1 = strlen(nstring2);
            if(len1 >= 1)
            {
             if(!strcmp(nstring2, "N")) x2 = 1;
             else x2 = atof(nstring2+2);
            }
            len1 = strlen(logstring2);
            if(len1 >= 1)
            {
             if (!strcmp(logstring2,"logN")) log2 = 1;
             else log2 = atof(logstring2+5);
            }
        }
        if (n1 > n2)
            printf("1\n");
        else
        if (n1 < n2)
            printf("-1\n");
        else
        if (n1 == n2)

        {
            if(x1 > x2)
                printf("1\n");
            else
            if (x1 < x2)
                printf("-1\n");

            else if (x1 == x2)
            {
                if (log1 > log2)
                    printf("1\n");
                else if (log1 < log2)
                    printf("-1\n");

                else if (log1 == log2)
                    printf("0\n");
            }
        }
        nstring1[0]='\0';
        nstring2[0]='\0';
        expstring1[0]='\0';
        expstring2[0]='\0';
        logstring1[0]='\0';
        logstring2[0]='\0';
        trashstring1[0]='\0';
        trashstring2[0]='\0';
        x1 = 0;
        x2 = 0;
        n1 = 0;
        n2 = 0;
        log1 = 0;
        log2 = 0;
    }
    fclose(fp);
    fclose(fs);
    return 0;
}
