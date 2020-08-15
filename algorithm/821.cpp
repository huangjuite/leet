#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

vector<int> shortestToChar(string S, char C)
{
    bool is_first = true;
    string cut;
    vector<int> ans;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == C)
        {
            if (cut.size() > 0)
            {
                for (int k = 0; k < cut.size(); k++)
                {
                    if (is_first)
                    {
                        ans.push_back(cut.size() - k);
                    }
                    else
                    {
                        if (k < cut.size() / 2)
                        {
                            ans.push_back(k + 1);
                        }
                        else
                        {
                            ans.push_back(cut.size() - k);
                        }
                    }
                }
                ans.push_back(0);
            }
            else
            {
                ans.push_back(0);
            }

            is_first = false;
            cut.clear();
        }
        else
        {
            cut.push_back(S[i]);
        }
    }

    if (cut.size() > 0)
    {
        for (int k = 0; k < cut.size(); k++)
        {
            ans.push_back(k + 1);
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> ans = shortestToChar("loveleetcodeasd", 'e');

    for (int k = 0; k < ans.size(); k++)
    {
        cout << ans[k];
    }
    cout << endl;
    return 0;
}
