#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int i = 0;
    while(i < haystack.size()) {
        bool found = true;
        for (int j = 0; j < needle.size(); j++) {
            if (i + j >= haystack.size() || haystack[i + j] != needle[j]) {
                found = false;
                break;
            }
                
        }
        if (found)
            return i;
        i ++;
        
    }
    return -1;

}

int main() {
    string s = "mississippi";
    string t = "issi";
    int pos = strStr(s, t);
    cout << pos << endl;
    return 0;
}