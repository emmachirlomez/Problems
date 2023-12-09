#include<bits/stdc++.h>
using namespace std;

// Solution: O(n)
vector<vector<string>> groupAnagramsSolutionOne(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto i : strs) {
            string x = i;
            sort(x.begin(), x.end());
            mp[x].push_back(i);
        }

        vector<vector<string>> ans;
        for (auto i : mp)
            ans.push_back(i.second);

        return ans;

    }

int main() {
    return 0;
}