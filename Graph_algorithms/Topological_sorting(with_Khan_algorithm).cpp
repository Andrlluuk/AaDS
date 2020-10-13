#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int themes, k, m;
    int dependence;
    int count = 0;
    fin >> themes >> dependence;
    int **adjust_matrix = new int *[themes + 5];
    for(int i = 0; i < themes + 5; i++)
    {
        adjust_matrix[i] = new int [themes+5];
    }
    int *answer = new int [themes + 5];
    int *indeg = new int [themes + 5];
    int *flag = new int [themes + 5];
    for(int i = 0; i < themes + 5; i++)
    {
        answer[i] = 0;
        indeg[i] = 0;
        flag[i] = 0;
        for(int j = 0; j < themes + 5; j++)
            adjust_matrix[i][j] = 0;
    }
    for(int i = 0; i < dependence; i++)
    {
        fin >> k >> m;
        adjust_matrix[k][m] = true;
    }
    for(int i = 1 ; i <= themes; i++)
        for(int j = 1; j <= themes; j++)
            indeg[i] = indeg[i] + adjust_matrix[j][i];
    int index = 1;
        while(count < themes)
        {
            for(k = 1; k <= themes; k++)
            {
                if((indeg[k] == 0) && (flag[k] == 0))
                {
                    answer[index] = k;
                    index++;
                    flag [k] = 1;
                    for(int i = 1; i <= themes; i++)
                    {
                        if(adjust_matrix[k][i] == 1)
                        {
                            indeg[i]--;
                            adjust_matrix[k][i] = 0;
                        }
                    }
                    break;
                }
                else continue;
            }
            count++;
        }
    if (index == themes + 1)
        for(int i = 1; i <= themes; i++)
            fout << answer[i] << " ";
    else
        fout << "bad course" ;
        return 0;
}
