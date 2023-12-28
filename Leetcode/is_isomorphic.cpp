#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;
    unordered_map<char, char> my_map;
    unordered_set<char> my_set;
    for (int i = 0; i < s.size(); i++) {
        if (my_map.find(s[i]) == my_map.end()) {
            if (my_set.find(t[i]) != my_set.end())
                return false;
            my_set.insert(t[i]);
            my_map[s[i]] = t[i];
        }
        if (my_map[s[i]] != t[i])
            return false;
    }
    return true;
}

int main() {
    string s = "badc";
    string t = "baba";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}