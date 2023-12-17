#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int right = height.size() - 1;
    int left = 0;
    int maxRight = height[right];
    int maxLeft = height[left];
    int ans = 0;
    while (left < right) {
        if (maxLeft <= maxRight) {
            left++;
            maxLeft = max(height[left], maxLeft);
            ans += maxLeft - height[left];
        }
        else {
            right--;
            maxRight = max(height[right], maxRight);
            ans += maxRight - height[right];
        }
    }
    return ans;
}

int main() {
    vector<int> height = {0,1,0,0,0,0};
    cout << trap(height) << endl;
    return 0;
}