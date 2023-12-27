#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    if (digits[i] != 9) {
        digits[i]++;
        return digits;
    }

    while (true) {
        digits[i] = 0;
        if (i - 1 < 0) {
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
            return digits;
        }
        if (digits[i - 1] == 9) {
            i--;
            continue;
        }
        else {
            digits[i - 1]++;
            return digits;
        }
    }

    return digits;
}

int main() {
    vector<int> digits = {8, 9, 9, 9};
    vector<int> ans = plusOne(digits);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}