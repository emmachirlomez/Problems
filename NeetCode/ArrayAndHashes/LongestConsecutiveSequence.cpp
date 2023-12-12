#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> my_set;
    for (auto i : nums)
        my_set.insert(i);
    int ans = 0;
    for (auto i : nums) {
        if (my_set.find(i - 1) == my_set.end()) {
            int length = 1;
            while(my_set.find(i + length) != my_set.end())
                length++;
            ans = max(ans, length);
        }
    }
    return ans;
}

int main()
{
    return 0;
}