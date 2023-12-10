#include<bits/stdc++.h>
using namespace std;

// Solution O(n)
vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        vector<int> left_side(size);
        vector<int> right_side(size);

        left_side[0] = 1;
        right_side[size - 1] = 1;

        for (int i = 1; i < size; i++)
            left_side[i] = left_side[i - 1] * nums[i - 1];

        for (int i = size - 2; i >= 0; i--)
            right_side[i] = right_side[i + 1] * nums[i + 1];

        for (int i = 0; i < size; i++)
            ans[i] = left_side[i] * right_side[i];

        return ans; 

}

int main() {
    return 0;
}