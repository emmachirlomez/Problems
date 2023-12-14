#include<bits/stdc++.h>
using namespace std;

// Time O(n) and space O(1)
bool isPalindrome(string s) {    
    int first = 0;
    int last = s.size() - 1;
    while(first < last) {
        if (!isalnum(s[first]))
            first++; 
        else if (!isalnum(s[last]))
            last--; 
        else if (tolower(s[first]) != tolower(s[last]))
            return false;
        else first++, last--;
    }
    return true;
}

int main() {

}