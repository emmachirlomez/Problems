#include<bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height) {
    int ans = 0;
    int first = 0;
    int last = height.size() - 1;
    while (first < last) {
        int length = min(height[first], height[last]);
        int area = length * (last - first);
        ans = max(ans, area);
        if (height[first] < height[last])
            first++;
        else
            last--;
    }
    return ans;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}