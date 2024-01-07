#include<bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> frq;
    for (auto i : nums)
        frq[i]++;
    for (auto [i, j] : frq) {
        if (j <= 1) {
            continue;
        }
        int fact = 1;
        for (int k = 1; k < j; k++)
            fact *= k;
        ans += fact;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << numIdenticalPairs(nums) << endl;
    return 0;
}