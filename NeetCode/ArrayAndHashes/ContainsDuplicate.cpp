#include<bits/stdc++.h>
using namespace std;

// O(n) complexity
bool SolutionOne(vector<int>& nums) {
    map<int, int> occurence_map;
    for (int i = 0; i < nums.size(); i++) {
        occurence_map[nums[i]] += 1;
        if (occurence_map[nums[i]] > 1)
            return true;
    }
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
