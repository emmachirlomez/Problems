#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
        count[s[i] - 'a']++, count[t[i] - 'a']--;
    
    for (auto i : count)
        if (i != 0)
            return false;
    return true;
}


int main() {
    return 0;
}