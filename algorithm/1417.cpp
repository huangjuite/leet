#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reformat(string s)
{
    string digits;
    string characters;
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 97)
        {
            characters.push_back(s[i]);
        }
        else
        {
            digits.push_back(s[i]);
        }
    }

    // cout << digits << endl;
    // cout << characters << endl;

    int len_dif = digits.size() - characters.size();
    if (abs(len_dif) > 1)
    {
        return ans;
    }

    string long_s, short_s;

    if (digits.size() >= characters.size())
    {
        long_s = digits;
        short_s = characters;
    }
    else
    {
        long_s = characters;
        short_s = digits;
    }

    if (len_dif != 0)
    {
        ans.push_back(long_s.back());
        long_s.pop_back();
    }
    while (long_s.size() > 0)
    {
        ans.push_back(short_s.back());
        short_s.pop_back();
        ans.push_back(long_s.back());
        long_s.pop_back();
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    cout << reformat("leetcode") << endl;
    return 0;
}
