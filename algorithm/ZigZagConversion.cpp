#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

string convert(string s, int numRows)
{
    if(numRows==1) return s;
    vector<string> ans_v(numRows);
    string ans;
    int bounce = 1;
    int row = 0;

    for (int i = 0; i < s.size(); i++)
    {
        ans_v[row].push_back(s[i]);
        row += bounce;
        if (row == -1)
        {
            row = 1;
            bounce = 1;
        }
        else if (row == numRows)
        {
            row = numRows - 2;
            bounce = -1;
        }
    }

    for(int i=0;i<numRows;i++){
        ans.append(ans_v[i]);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    string s1 = "PAYPALISHIRING";
    cout << convert(s1,3) << endl;
    return 0;
}

// 3
// PAYPALISHIRING

// P   A   H   N
// A P L S I I G
// Y   I   R

// PAHNAPLSIIGYIR

// 4
// PAYPALISHIRING

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// PINALSIGYAHRPI