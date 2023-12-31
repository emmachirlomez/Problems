#include<bits/stdc++.h>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    int ans = -1;
    unordered_map<char, int> frq;

    for (int i = 0; i < (int)s.size(); i++) {
        if (frq.contains(s[i]))
            ans = max(ans, i - frq[s[i]] - 1);
        else
            frq[s[i]] = i;
    }
    return ans;
}

int main() {
    return 0;
}