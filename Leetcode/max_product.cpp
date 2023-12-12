#include<bits/stdc++.h>
using namespace std;

// O(nlogn) time and O(1) memory
int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    return (nums[size - 2] - 1) * (nums[size - 1] -1);
}

int main() {
    return 0;
}