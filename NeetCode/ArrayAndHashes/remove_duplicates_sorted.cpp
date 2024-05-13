#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int prev = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[prev - 1] != nums[i]) {
            nums[prev] = nums[i];
            prev++;
        }
    }
    return prev;
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

    cout << removeDuplicates(nums) << endl;

    return 0;
}