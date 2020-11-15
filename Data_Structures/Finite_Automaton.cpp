#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<cmath>
#include<queue>

using namespace std;

class Finite_Automaton
{
    int n;
    int state;
    int begin_state;
    vector<int>* final_state;
    vector<vector<int>*>* matrix;
    int number_of_end_positions;
    
    int set_to_decimal(set<int> x)
    {
        int sum = 0;
        for(auto it = x.begin(); it != x.end(); ++it)
            sum += pow(2, (*it));
        return sum;
    }
    
    set<int> decimal_to_set(int d)
    {
        vector<int> binary;
        while(d != 1)
        {
            binary.push_back(d%2);
            d /= 2;
        }
        int x = 0;
        set<int> result;
        for(int i = binary.size(); i < 0; i--)
        {
            if(binary[i])
            {
                result.insert(x);
                x++;
            }
        }
        return result;
    }
        
    
public:
    Finite_Automaton(int n, int x, int f):n(n), begin_state(x), state(x)
    {
        final_state = new vector<int>(f);
        matrix = new vector<vector<int>*>(n);
        for(int i = 0; i < n; i++)
            (*matrix)[i] = new vector<int>(26);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 26; j++)
                (*(*matrix)[i])[j] = -1;
        number_of_end_positions = 0;
    }
    
    ~Finite_Automaton()
    {
        delete final_state;
        for(int i = 0; i < n; i++)
            delete(*matrix)[i];
        delete matrix;
    }
    
    void Add_functions(int from, int to, char value)
    {
        (*(*matrix)[from])[(int)value - 'a'] = to;
    }
    
    void Add_end_position(int x)
    {
        (*final_state)[number_of_end_positions] = x;
        number_of_end_positions++;
    }
    bool recognition(string s)
    {
        for(int i = 0; i < s.length();i++)
            state = (*(*matrix)[state])[(int)s[i] - 'a'];
        for(int i = 0; i < final_state->size(); i++)
            if(state == (*final_state)[i])
                return 1;
        return 0;
    }
    void put_state()
    {
        state = begin_state;
    }
};

Finite_Automaton* build_automaton(int &n, int &k, int &f, ifstream &in)
{
    Finite_Automaton *a = new Finite_Automaton(n,k,f);
    int fin;
    for(int i = 0; i < f; i++)
    {
        in >> fin;
        a->Add_end_position(fin);
    }
    int x;
    in >> x;
    for(int i = 0; i < x; i++)
    {
        int from;
        int to;
        char val;
        in >> from >> to >> val;
        a->Add_functions(from, to, val);
    }
    return a;
}

int main()
{
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int n;
    int k;
    int f;
    int x;
    in >> n;
    in >> k;
    in >> f;
    Finite_Automaton *a = build_automaton(n,k,f, in);
    int test;
    in >> test;
    while(test--)
    {
        string s;
        in >> s;
        bool result = a->recognition(s);
        if(result)
            out << "YES";
        else
            out << "NO";
        out << endl;
        a->put_state();
    }
    in.close();
    out.close();
    return 0;
}
