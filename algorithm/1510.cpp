#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

// bool winnerSquareGame(int n)
// {
//     if (n == 0)
//     {
//         return false;
//     }
//     else if (n == 1)
//     {
//         return true;
//     }
//     else if (m.find(n) != m.end())
//     {
//         // cout << "memory" << endl;
//         return m[n];
//     }
//     else
//     {
//         int k = int(sqrt(n));
//         for (int i = 1; i <= k; i++)
//         {
//             bool opoenent = winnerSquareGame(n - i * i);
//             m[n - i * i] = opoenent;
//             if (!opoenent)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// }

bool winnerSquareGame(int n)
{
    vector<bool> m(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k * k <= i; k++)
        {
            if (!m[i - k * k])
            {
                m[i] = true;
                break;
            }
        }
    }
    return m[n];
}

int main(int argc, char const *argv[])
{
    int n = 17;
    cout << n << endl;
    cout << winnerSquareGame(n) << endl;
    return 0;
}
