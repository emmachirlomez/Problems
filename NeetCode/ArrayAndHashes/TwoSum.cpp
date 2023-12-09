#include<bits/stdc++.h>
using namespace std;

// Soluetion 1: O(n^2)
vector<int> TwoSumSolutionOne(vector<int>& nums, int target) {
    vector<int> ans = {0, 0};
        for (int i = 0; i < nums.size() - 1; i++) {
            ans[0] = i;
            for (int j = i + 1; j < nums.size(); j++ ) {
                if (nums[i] + nums[j] == target) {
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
}


// Solution 2: O(n)
vector<int> TwoSumSolutionTwo(vector<int>& nums, int target) {
    unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return { map[complement], i };
            }
            map[nums[i]] = i;
        }
        return {-1, -1}; // or return {};
}

int main() {
    return 0;
}