#include<bits/stdc++.h>
using namespace std;

// Solution 1: O(nlogn) time complexity, O(1) space complexity
bool isAnagramSolutionOne(string s, string t) {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
}

// Solution 2: O(n) time complexity, O(n) space complexity
bool isAnagramSolutionTwo(string s, string t) {
        unordered_map<char, int> count;

        for (auto x : s)
            count[x]++;

        for (auto x : t)
            count[x]--;

        for (auto x : count)
            if (x.second != 0)
                return false;

        return true;
    }

// Solution 3: O(n) with Hash table
bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++)
            count[s[i] - 'a']++, count[t[i] - 'a']--;
        
        for (auto x : count)
            if (x != 0)
                return false;

        return true;
    }

// Solution 4: O(n) and O(n)
bool isAnagramSolutionFour(string s, string t) {
    unordered_map<int, int> s_frq;
    unordered_map<int, int> t_frq;
    for (auto i : s)
        s_frq[i]++;
    for (auto i : t)
        t_frq[i]++;
    return (t_frq == s_frq);
}

int main() {
    return 0;
}