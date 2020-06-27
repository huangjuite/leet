#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> m;
    for(int i=0;i<nums.size();i++){
        if(m.find(target-nums[i])==m.end()){
            m[nums[i]]=i;
        }
        else{
            ans.push_back(i);
            ans.push_back(m[target-nums[i]]);
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> data;
    data.push_back(2);
    data.push_back(6);
    data.push_back(7);
    data.push_back(1);
    vector<int> ans = twoSum(data,9);
    for(auto a:ans){
        cout << a << endl;
    }
    return 0;
}
