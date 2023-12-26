#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int ans = 0;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        int size_word = 0;
        while(i != s.size() && s[i] != ' ')
            size_word++, i++;
        ans = size_word;
    }
    return ans;
}

int main() {
    string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}