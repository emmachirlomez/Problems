#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_set<int> my_set;
    for (auto i : nums) {
        if (my_set.find(i) == my_set.end())
            my_set.insert(i);
        else
            my_set.erase(i);
    }
    return *begin(my_set);
}

int main() {
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums) << endl;
    return 0;
}