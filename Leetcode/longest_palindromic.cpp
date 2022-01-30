#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string z = "$*";
        
        for (int i = 0; i < (int)s.size(); i++)
            z += s[i], z += '*';
        z += '%';

        vector<string> ans;
        for (int i = 0; i < (int)z.size(); i++) {
            while (s[i] != '$' && s[i] != '%') {
                
            }
        }
        return z;
    }
};

int main()
{

}