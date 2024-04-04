#include<bits/stdc++.h>
using namespace std;

// O(n) complexity O(n) space complexity
bool SolutionOne(vector<int>& nums) {
    map<int, int> occurence_map;
    for (int i = 0; i < nums.size(); i++) {
        occurence_map[nums[i]] += 1;
        if (occurence_map[nums[i]] > 1)
            return true;
    }
    return false;
}

// O(n) time complexity O(1) space complexity
bool SolutionTwo(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] == nums[i + 1])
            return true;
    return false;
}

int main() {
    vector<int> nums;
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int ans;
        cin >> ans;
        nums.push_back(ans);
    }
    cout << SolutionOne(nums) << '\n';
    return 0;
}
