#include<bits/stdc++.h>
using namespace std;

// O(nlogn)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto i : nums)
        mp[i]++;

    vector<pair<int, int>> value_by_frq;
    for (auto [value, frq] : mp)
        value_by_frq.push_back({frq, value});

    sort(value_by_frq.rbegin(), value_by_frq.rend());
    
    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.push_back(value_by_frq[i].second);

    return ans;
}

// O(n)
vector<int> topKFrequentSolutionTwo(vector<int>&nums, int k) {
    unordered_map<int, int> mp;
    for (auto i : nums)
        mp[i]++;

    vector<vector<int>> frq;
    frq.resize(nums.size() + 1);

    for (auto [value, freq] : mp) 
        frq[freq].push_back(value);

    vector<int> ans;
    for (int i = frq.size() - 1; i >= 0; i--) {
        for (auto j : frq[i])
            ans.push_back(j);
    }
    ans.resize(k);
    return ans;
}


int main() {

    vector<int> nums;
    int x;
    int k;
    cin >> k;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int ans;
        cin >> ans;
        nums.push_back(ans);
    }

    vector<int> ans = topKFrequent(nums, k);
    for (auto i : ans)
        cout << i << " ";

    cout << '\n';

    return 0;
}