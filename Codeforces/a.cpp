#include <bits/stdc++.h>
using namespace std;

bool IsSubstring(string s, string original)
{
    for (int start = 0; start + s.size() - 1 < original.size(); start++)
    {
        int ok = true;
        for (int i = 0; i < s.size(); i++)
            ok &= (s[i] == original[start + i]);
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (y < -1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}