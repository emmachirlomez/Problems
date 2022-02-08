#include<bits/stdc++.h>
using namespace std;

bool PalindromeChecker(string s) 
{
    string s_inverse = s;
    reverse(s_inverse.begin(), s_inverse.end());
    return (s == s_inverse);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        while(n--) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        if (k == 0)
            cout << 1 << '\n';
        else {
            if(PalindromeChecker(s))
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }
    return 0;
}