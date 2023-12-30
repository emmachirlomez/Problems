#include<bits/stdc++.h>
using namespace std;

bool makeEqual(vector<string>& words) {
    unordered_map<char, int> frq;
    for (auto i : words)
        for (auto c : i)
            frq[c]++;
    
    for (auto i : frq)
        if (i.second % words.size() != 0)
            return false;
    
    return true;
}

int main() {
    return 0;
}