#include<bits/stdc++.h>
using namespace std;

string makeGood(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (ans.size() == 0 ) {
            ans.push_back(s[i]);
            continue;
        }
        if ((ans.back() - s[i] == ('a' - 'A')) || (s[i] - ans.back() == ('a' - 'A'))) {
            ans.pop_back();
            continue;
        }

        ans.push_back(s[i]);
    }
    return ans;
}

int main() {
    string s = "leEeetcode";
    cout << makeGood(s) << endl;
    return 0;
}