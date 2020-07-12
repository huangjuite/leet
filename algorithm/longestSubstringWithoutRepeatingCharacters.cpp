#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> m;
    int ans = 0;
    int last_repeate = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) != m.end() && last_repeate < m[s[i]])
        {
            last_repeate = m[s[i]];
        }
        if (i - last_repeate > ans)
        {
            ans = i - last_repeate;
        }
        m[s[i]] = i;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    string s1 = "bbbbb";
    cout << s1 << ":" << lengthOfLongestSubstring(s1) << endl;
    return 0;
}
