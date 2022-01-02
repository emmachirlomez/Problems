#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans = 0;
        for (auto i : s)
            if (i == 'N')
                ans++;
        if (ans == 1)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}