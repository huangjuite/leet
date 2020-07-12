#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    double ans = 0;
    vector<int> merged;
    int idx = 0;
    int expected_size = (nums1.size() + nums2.size()) / 2;
    int even_size = (nums1.size() + nums2.size()) % 2;
    while (!nums1.empty() || !nums2.empty())
    {
        if (!nums1.empty() && !nums2.empty())
        {
            if (nums1.back() > nums2.back())
            {
                merged.push_back(nums1.back());
                nums1.pop_back();
            }
            else
            {
                merged.push_back(nums2.back());
                nums2.pop_back();
            }
        }
        else if (nums2.empty())
        {
            merged.push_back(nums1.back());
            nums1.pop_back();
        }
        else if (nums1.empty())
        {
            merged.push_back(nums2.back());
            nums2.pop_back();
        }
        idx++;
        if (idx == expected_size + 1)
        {
            if (!even_size)
            {
                int n1 = merged.back();
                merged.pop_back();
                int n2 = merged.back();
                ans = (n1 + n2) / 2.0;
            }
            else
            {
                ans = merged.back();
            }

            break;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums1{1, 3};
    vector<int> nums2{2, 4};

    double ans = findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;

    return 0;
}
