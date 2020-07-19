#include <iostream>
#include <stdlib.h>
using namespace std;

string findPalindrome(string s, int left, int right)
{
    // string palindrome;
    while (left > 0 && right < s.size()-1 && s[left] == s[right])
    {
        cout << left << "," << right << endl;
        cout << s[left] << "," << s[right] << endl;
        
        if(s[left-1] == s[right+1]){
            left--;
            right++;
        }
        else{
            break;
        }
    }
    string ans;
    
    if(left==right){
        ans = s[left]; 
    }
    else if(s[left]!=s[right])
    {
        ans = s[left]; 
    }
    else{
        ans = s.substr(left, right - left + 1);
    }
    cout << left << endl;
    cout << right << endl;
    cout << ans << endl;
    cout << "----------" << endl;

    return ans;
}

string longestPalindrome(string s)
{
    if(s.size()==0) return "";
    string longest;
    longest.push_back(s[0]);

    for (int i = 0; i < s.size(); i++)
    {
        string odd = findPalindrome(s, i, i);
        if (odd.size() > longest.size())
        {
            longest = odd;
        }
        string even = findPalindrome(s, i, i + 1);
        if (even.size() > longest.size())
        {
            longest = even;
        }
    }

    return longest;
}

int main(int argc, char const *argv[])
{
    string s1 = "aaabaaaa";
    cout << longestPalindrome(s1) << endl;
    return 0;
}
