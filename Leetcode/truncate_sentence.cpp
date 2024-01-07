#include<bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k) {
    s += " ";
    string ans = "";

    string word = "";

    int poz = 0;
    while (true) {
        if (poz >= s.size() || k <= 0)
            return ans;
        if (s[poz] == ' ')
            ans += word, k--, word = "";
        word += s[poz];
        poz++;
    }
    return ans;
}

int main() {
    string s = "Chopper is not a tanuki";
    int k = 4;
    cout << truncateSentence(s, k) << endl;
    return 0;
}