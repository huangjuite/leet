#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int knightDialer(int N)
{
    vector<vector<int>> moves{
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}};

    vector<int> result(10, 1);

    for (int i = 0; i < N - 1; i++)
    {
        vector<int> next;
        for (int k = 0; k < result.size(); k++)
        {
            int step = 0;
            for (int j = 0; j < moves[k].size(); j++)
            {
                step += result[moves[k][j]];
                step %= (1000000000 + 7);
            }
            next.push_back(step);
        }
        result = vector<int>(next);
    }

    long ans = 0;
    for (int i = 0; i < result.size(); i++)
    {
        ans += result[i];
        ans %= (1000000000 + 7);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << knightDialer(3) << endl;
    return 0;
}
