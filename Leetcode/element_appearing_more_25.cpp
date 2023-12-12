#include<bits/stdc++.h>
using namespace std;

// O(n) for both time and memory
int findSpecialInteger(vector<int>& arr) {
    unordered_map<int, int> frq;
    for (auto i : arr) {
        frq[i]++;
        if (frq[i] > 0.25 * arr.size())
            return i;
    }
    return -1;
}

int main() {
    return 0;
}