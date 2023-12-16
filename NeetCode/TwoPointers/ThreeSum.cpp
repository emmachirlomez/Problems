#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<tuple<int, int, int>> triplets;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    auto sum = [&](int first, int second, int third) {
        return nums[first] + nums[second] + nums[third];
    };

    for (int i = 0; i < nums.size() - 2; i++) {
        int first = i + 1;
        int last = nums.size() - 1;
        while(first < last) {
            if (nums[first] + nums[last] + nums[i] == 0)
                triplets.insert({nums[first], nums[last], nums[i]}), first++;
            else if (nums[first] + nums[last] + nums[i] < 0)
                first++;
            else
                last--;
        }
    }
    for (auto [a, b, c] : triplets)
        ans.push_back({ a, b, c });
    return ans;
        
}

int main() {
    unordered_set<int> s = {1, 2, 3, 4, 5};
    unordered_set<int> m = {1, 3, 2, 4, 5};
    bool ans = (s == m);
    cout << ans << endl;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans1 = threeSum(nums);
    for (auto i : ans1) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;

}