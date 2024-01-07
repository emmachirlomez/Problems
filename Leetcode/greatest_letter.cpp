#include<bits/stdc++.h>
using namespace std;

string greatestLetter(string s) {
    vector<pair<bool, bool>> letter(25);
    for (auto i : s)
        if (i >= 'a' && i <= 'z')
            letter[i - 'a'] = {true, false};
    for (auto i : s)
        if (i >= 'A' && i <= 'Z' && letter[i - 'A'].first)
            letter[i - 'A'] = {true, true};

    string ans = "";
    for (int i = letter.size() - 1; i >= 0; i--) {
        if (letter[i].second) {
            ans += i + 'A';
            return ans;
        }
    }

    return ans;
}

int main () {
    string s = "admeDCAB";
    cout << greatestLetter(s) << endl;
    return 0;
}