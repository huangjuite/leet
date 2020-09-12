
// unsolved


#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct mutateS
{
    char target;
    int position;
} mutate;

typedef struct mutationStruct
{
    string dna;
    bool valid;
    vector<mutationStruct *> mutations;
    vector<mutate> todo;
} ms;

int minMutation(string start, string end, vector<string> &bank)
{
    vector<ms *> processing;
    ms *mutation = new ms;

    mutation->dna = start;
    mutation->valid = true;

    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] != end[i])
        {
            mutate m;
            m.position = i;
            m.target = end[i];
            mutation->todo.push_back(m);
        }
    }

    vector<string> ans;
    processing.push_back(mutation);

    while (processing.size() > 0)
    {
        vector<ms *> next_processing;
        for (int i = 0; i < processing.size(); i++)
        {
            vector<mutate> mt = processing[i]->todo;
            for (int k = 0; k < mt.size(); k++)
            {
                ms *next_mu = new ms;
                next_mu->dna = processing[i]->dna;
                next_mu->dna[mt[k].position] = mt[k].target;
                cout << next_mu->dna << endl;

                if (find(bank.begin(), bank.end(), next_mu->dna) != bank.end())
                {
                    next_mu->valid = true;
                    if (find(ans.begin(), ans.end(), next_mu->dna) == ans.end())
                    {
                        ans.push_back(next_mu->dna);
                    }
                }
                else
                {
                    next_mu->valid = false;
                }
                cout << next_mu->valid << endl;
                next_mu->todo = mt;
                next_mu->todo.erase(next_mu->todo.begin() + k);
                next_processing.push_back(next_mu);              
            }

            cout << "-----------" << endl;
        }
        processing = next_processing;
    }

    return (ans.size() > 0) ? ans.size() : -1;
}

int main(int argc, char const *argv[])
{
    // string start = "AACCGGTT";
    // string end = "AAACGGTA";
    // vector<string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    // string start ="AACCTTGG";
    // string end =  "AATTCCGG";
    // vector<string> bank{"AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"};

    string start = "AACCGGTT";
    string end =   "AAACGGTA";
    vector<string> bank{"AACCGATT", "AACCGATA", "AAACGATA", "AAACGGTA"};

    cout << "start: " << start << endl;
    cout << "end:   " << end << endl
         << endl;
    cout << minMutation(start, end, bank) << endl;

    return 0;
}
